///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-88b0f50)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrameBase.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_MainFrameMenu = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* m_menuFileNew;
	m_menuFileNew = new wxMenuItem( m_menuFile, wxID_NEW, wxString( wxEmptyString ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuFileNew );

	wxMenuItem* m_menuFileOpen;
	m_menuFileOpen = new wxMenuItem( m_menuFile, wxID_OPEN, wxString( wxEmptyString ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuFileOpen );

	wxMenuItem* m_menuSave;
	m_menuSave = new wxMenuItem( m_menuFile, wxID_SAVE, wxString( wxEmptyString ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuSave );

	m_menuFile->AppendSeparator();

	wxMenuItem* m_menuFileClose;
	m_menuFileClose = new wxMenuItem( m_menuFile, wxID_CLOSE, wxString( wxEmptyString ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuFileClose );

	m_MainFrameMenu->Append( m_menuFile, wxT("File") );

	m_menu2 = new wxMenu();
	m_MainFrameMenu->Append( m_menu2, wxT("MyMenu") );

	m_menu3 = new wxMenu();
	m_MainFrameMenu->Append( m_menu3, wxT("MyMenu") );

	this->SetMenuBar( m_MainFrameMenu );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_ProjectPathLabel = new wxStaticText( this, wxID_ANY, wxT("Project Path"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ProjectPathLabel->Wrap( -1 );
	bSizer1->Add( m_ProjectPathLabel, 0, wxALL, 10 );

	m_textProjectPath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer1->Add( m_textProjectPath, 1, wxALL, 5 );

	m_btnProjectPath = new wxButton( this, wxID_ANY, wxT("Select Project path"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_btnProjectPath, 0, wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	// Connect Events
	m_menuFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnClose ), this, m_menuFileClose->GetId());
	m_btnProjectPath->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::getProjectPath ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	m_btnProjectPath->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::getProjectPath ), NULL, this );

}
