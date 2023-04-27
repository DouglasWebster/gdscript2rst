///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-88b0f50)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/gbsizer.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_MainFrameMenu;
		wxMenu* m_menuFile;
		wxMenu* m_menu2;
		wxMenu* m_menu3;
		wxStaticText* m_ProjectPathLabel;
		wxTextCtrl* m_textProjectPath;
		wxButton* m_btnProjectPath;
		wxStatusBar* m_statusBar1;

		// Virtual event handlers, override them in your derived class
		virtual void OnClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void getProjectPath( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Godot API's to reStructuredText"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxTAB_TRAVERSAL );

		~MainFrameBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ProjectDetailsDlg
///////////////////////////////////////////////////////////////////////////////
class ProjectDetailsDlg : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel;
		wxStaticText* m_projectDirectoryLable;
		wxStaticText* m_godotDirectoryLable;
		wxStaticText* m_sourceDirectoryLabel;
		wxTextCtrl* projectLocationPath;
		wxButton* projectLocationChooseBtn;

	public:

		ProjectDetailsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Project Details"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxFULL_REPAINT_ON_RESIZE );

		~ProjectDetailsDlg();

};

