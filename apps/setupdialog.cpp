#include "setupdialog.h"

#include <wx/dirdlg.h>
#include <wx/gbsizer.h>
#include <wx/statline.h>

SetupDialog::SetupDialog(wxWindow *parent, wxString pythonVersion)
  : wxDialog(parent,
    wxID_ANY,
    "Project setup",
    wxDefaultPosition,
    wxDefaultSize,
    wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER),
    m_pythonVersion(pythonVersion)
{

  const auto MARGIN{ FromDIP(10) };

  auto mainSizer = new wxBoxSizer(wxVERTICAL);
  wxPanel *panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600, 200));

  this->SetBackgroundColour(panel->GetBackgroundColour());

  auto sizer = new wxGridBagSizer(MARGIN, MARGIN);

  // Get the default directories
  auto projectLabel = new wxStaticText(panel, wxID_ANY, "Project location:");
  auto sourceLabel = new wxStaticText(panel, wxID_ANY, "Source location:");
  auto destinationLabel = new wxStaticText(panel, wxID_ANY, "Destination location:");

  auto projectPath = new wxTextCtrl(panel, wxID_ANY, m_projectPath);
  projectPath->SetEditable(false);
  auto sourcePath = new wxTextCtrl(panel, wxID_ANY);
  sourcePath->SetEditable(false);
  auto destinationPath = new wxTextCtrl(panel, wxID_ANY);
  destinationPath->SetEditable(false);

  auto projectButton = new wxButton(panel, wxID_ANY, "Project Dir...");
  auto sourceButton = new wxButton(panel, wxID_ANY, "Source Dir...");
  auto destinationButton = new wxButton(panel, wxID_ANY, "Destination Dir...");

  auto projectFormSizer = new wxBoxSizer(wxHORIZONTAL);
  projectFormSizer->Add(projectPath, 1, wxEXPAND | static_cast<wxStretch>(wxRight), MARGIN);
  projectFormSizer->Add(projectButton, 0, wxALIGN_CENTER_VERTICAL);

  auto sourceFormSizer = new wxBoxSizer(wxHORIZONTAL);
  sourceFormSizer->Add(sourcePath, 1, wxEXPAND | static_cast<wxStretch>(wxRight), MARGIN);
  sourceFormSizer->Add(sourceButton, 0, wxALIGN_CENTRE_VERTICAL);

  auto destinationFormSizer = new wxBoxSizer(wxHORIZONTAL);
  destinationFormSizer->Add(destinationPath, 1, wxEXPAND | static_cast<wxStretch>(wxRight), MARGIN);
  destinationFormSizer->Add(destinationButton, 0, wxALIGN_CENTER_VERTICAL);

  sizer->Add(projectLabel, { 0, 0 }, { 1, 1 }, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
  sizer->Add(sourceLabel, { 1, 0 }, { 1, 1 }, wxALIGN_RIGHT);
  sizer->Add(destinationLabel, { 2, 0 }, { 1, 1 }, wxALIGN_RIGHT);
  sizer->Add(projectFormSizer, { 0, 1 }, { 1, 1 }, wxEXPAND);
  sizer->Add(sourceFormSizer, { 1, 1 }, { 1, 1 }, wxEXPAND);
  sizer->Add(destinationFormSizer, { 2, 1 }, { 1, 1 }, wxEXPAND);

  wxStaticLine *divisor1 = new wxStaticLine(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
  sizer->Add(divisor1, wxGBPosition(3, 0), wxGBSpan(1, 3), wxEXPAND | wxALL, 5);

  wxBoxSizer *pythonDetailsSizer;
  pythonDetailsSizer = new wxBoxSizer(wxHORIZONTAL);

  auto *pythonVersionCtrl = new wxTextCtrl(panel, wxID_ANY, "");
  pythonVersionCtrl->SetValue(m_pythonVersion);
  pythonVersionCtrl->SetEditable(false);

  pythonDetailsSizer->Add(pythonVersionCtrl, 1, wxALL, 5);

  auto *venvLabel = new wxStaticText(panel, wxID_ANY, "venv name: ");
  auto *venvNameCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
  venvNameCtrl->SetValue(".venv");
  pythonDetailsSizer->Add(venvLabel, 0, wxALL, 5);
  pythonDetailsSizer->Add(venvNameCtrl, 1, wxALL, 5);

  sizer->Add(pythonDetailsSizer, wxGBPosition(4, 0), wxGBSpan(1, 4), wxEXPAND, 5);

  sizer->AddGrowableCol(1);
  panel->SetSizer(sizer);

  mainSizer->Add(panel, 1, wxEXPAND | wxALL, MARGIN);
  mainSizer->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL));
  this->SetSizerAndFit(mainSizer);

  projectButton->Bind(wxEVT_BUTTON, [=, this](wxCommandEvent &event) {
    wxDirDialog dialog(this, "Project directory", this->m_projectPath, wxDD_DEFAULT_STYLE);
    if (dialog.ShowModal() == wxID_CANCEL) { return; }

    projectPath->SetValue(dialog.GetPath());
    if (destinationPath->IsEmpty()) {
      wxString suggestedPath = projectPath->GetValue() + "/build";
      destinationPath->SetValue(suggestedPath);
    }

    this->Layout();
    this->Fit();
  });

  sourceButton->Bind(wxEVT_BUTTON, [=, this](wxCommandEvent &event) {
    wxFileDialog dialog(this,
      _("Godot Project directory"),
      "",
      "",
      "Godot Project files (project.godot)|project.godot",
      wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (dialog.ShowModal() == wxID_CANCEL) { return; }

    sourcePath->SetValue(dialog.GetDirectory());

    this->Layout();
    this->Fit();
  });

  destinationButton->Bind(wxEVT_BUTTON, [=, this](wxCommandEvent &event) {
    wxDirDialog dialog(this, "Destination directory", this->m_projectPath, wxDD_DEFAULT_STYLE);
    if (dialog.ShowModal() == wxID_CANCEL) { return; }

    destinationPath->SetValue(dialog.GetPath());

    this->Layout();
    this->Fit();
  });
}
