// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/dirdlg.h>

#include "MainFrameBase.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MainFrame : public MainFrameBase {
private:
    wxString m_ProjectPath {};

public:
    MainFrame(
        wxWindow* parent = NULL,
        wxWindowID id = wxID_ANY,
        const wxString& title = wxEmptyString,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(1, 1))
        : MainFrameBase { parent, id, title, pos, size }
    {
    }

    virtual void OnClose(wxCommandEvent& event);
    virtual void getProjectPath(wxCommandEvent& event);
};

bool MyApp::OnInit()
{
    MainFrame* frame = new MainFrame(
        NULL, wxID_ANY, "Godot GScript API to ReStructured Text", wxDefaultPosition, wxSize(500, 300));
    frame->Show(true);
    return true;
}

void MainFrame::OnClose(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::getProjectPath(wxCommandEvent& event)
{
    wxDirDialog* projPathDlg = new wxDirDialog(this, "Choose the Project Path", m_ProjectPath);

    if (projPathDlg->ShowModal() == wxID_OK) {

        m_ProjectPath = projPathDlg->GetPath();
        m_textProjectPath->AppendText(projPathDlg->GetPath());
    };
}
