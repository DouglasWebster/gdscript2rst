#include <cstdlib>
#include <regex>

#include "app.h"
#include <wx/print.h>

// start the wxWidget based app off.
wxIMPLEMENT_APP(MyApp);

/**
 * @brief Create the main frame for the app
 * @return true if the app is created,
 *
 * The main frame is created with a given title, position and size then shown.
 */
bool MyApp::OnInit()
{
  MainFrame *frame =
    new MainFrame(nullptr, wxID_ANY, "Godot GScript API to ReStructured Text", wxDefaultPosition, wxSize(1024, 600));
  frame->Show(true);
  frame->OnCheckPython();

  return true;
}

MainFrame::MainFrame(wxWindow *parent,
  wxWindowID id,
  const wxString &title,
  const wxPoint &pos,
  const wxSize &size,
  long style)
  : wxFrame{ parent, id, title, pos, size, style }
{
  logger = new wxLogStderr();
  wxLog::SetActiveTarget(logger);

  this->SetSizeHints(wxDefaultSize, wxDefaultSize);

  m_MainFrameMenu = new wxMenuBar(0);
  m_menuFile = new wxMenu();
  wxMenuItem *m_menuProjectNew;
  m_menuProjectNew = new wxMenuItem(m_menuFile, wxID_NEW, wxString(wxEmptyString), wxEmptyString, wxITEM_NORMAL);
  m_menuFile->Append(m_menuProjectNew);

  wxMenuItem *m_menuFileOpen;
  m_menuFileOpen = new wxMenuItem(m_menuFile, wxID_OPEN, wxString(wxEmptyString), wxEmptyString, wxITEM_NORMAL);
  m_menuFile->Append(m_menuFileOpen);

  wxMenuItem *m_menuSave;
  m_menuSave = new wxMenuItem(m_menuFile, wxID_SAVE, wxString(wxEmptyString), wxEmptyString, wxITEM_NORMAL);
  m_menuFile->Append(m_menuSave);

  m_menuFile->AppendSeparator();

  wxMenuItem *m_menuFileClose;
  m_menuFileClose = new wxMenuItem(m_menuFile, wxID_CLOSE, wxString(wxEmptyString), wxEmptyString, wxITEM_NORMAL);
  m_menuFile->Append(m_menuFileClose);

  m_MainFrameMenu->Append(m_menuFile, wxT("File"));

  m_menuCheck = new wxMenu();
  wxMenuItem *menuCheckPython;
  menuCheckPython = new wxMenuItem(m_menuCheck, wxID_ANY, wxString(wxT("Python...")), wxEmptyString, wxITEM_NORMAL);
  m_menuCheck->Append(menuCheckPython);

  m_MainFrameMenu->Append(m_menuCheck, wxT("Check system"));

  m_menu3 = new wxMenu();
  m_MainFrameMenu->Append(m_menu3, wxT("MyMenu"));

  this->SetMenuBar(m_MainFrameMenu);

  wxBoxSizer *bSizer1;
  bSizer1 = new wxBoxSizer(wxHORIZONTAL);

  this->SetSizer(bSizer1);

  this->Layout();
  m_MainStatusBar = this->CreateStatusBar(1, wxSTB_DEFAULT_STYLE, wxID_ANY);
  wxStatusBarPane paneOne = m_MainStatusBar->GetField(0);
  paneOne.SetStyle(wxSB_SUNKEN);
  m_MainStatusBar->SetStatusText("No project open.");

  // Connect Events
  m_menuFile->Bind(
    wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnClose), this, m_menuFileClose->GetId());

  m_menuFile->Bind(
    wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::startNewProject), this, m_menuProjectNew->GetId());
}

void MainFrame::OnClose(wxCommandEvent &event) { Close(true); }

void MainFrame::startNewProject(wxCommandEvent &event)
{
  wxString pythonString{ "Python version: " };
  pythonString.append(m_pythonVersion);
  if (GetPythonVersion() < 3) { pythonString.append(" (version 3+ required - document generation inhibited."); }
  SetupDialog setupDialog(this, pythonString);
  
  if (setupDialog.ShowModal() == wxID_OK) {
    wxLogMessage("Setup dialog returned OK");
  } else {
    wxLogMessage("Setup dialog box was cancelled");
  }
}

void MainFrame::OnCheckPython()
{
  std::string command = "python --version 2>&1";
  std::string version = "";

  FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    wxMessageBox("Failed to get Python information from the system");
    return;
  }

  char buffer[128];
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr) { version += buffer; }

  int status = pclose(pipe);
  if (status == -1) {
    std::cerr << "Failed to close pipe!" << std::endl;
    return;
  }

  std::regex pattern("\\d+.\\d+.\\d+");
  std::smatch match;
  std::regex_search(version, match, pattern);

  m_pythonVersion = match.str();

  if (version.empty() | std::stoi(m_pythonVersion) < 3) {
    m_pythonInstalled = false;
    wxMessageBox(
      "Python version 3 or greater is required for this program.  Document generation step will be disabled.");
  } else {
    m_pythonInstalled = true;
    wxString message = "Python version " + m_pythonVersion + " found.";
  }
}

int MainFrame::GetPythonVersion()
{
  if (m_pythonVersion.empty()) { return 0; }

  return std::stoi(m_pythonVersion);
}
