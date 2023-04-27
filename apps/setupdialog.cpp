#include "setupdialog.h"

#include <wx/dirdlg.h>
#include <wx/gbsizer.h>

SetupDialog::SetupDialog( wxWindow *parent )
    : wxDialog( parent, wxID_ANY, "Project setup", wxDefaultPosition, wxDefaultSize,
                wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER ) {
  const auto MARGIN{ FromDIP( 10 ) };

  auto mainSizer = new wxBoxSizer( wxVERTICAL );
  wxPanel *panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 400, 200 ) );

  this->SetBackgroundColour( panel->GetBackgroundColour() );

  auto sizer = new wxGridBagSizer( MARGIN, MARGIN );

  auto projectLabel = new wxStaticText( panel, wxID_ANY, "Project location:" );
  auto sourceLabel = new wxStaticText( panel, wxID_ANY, "Source location:" );
  auto destinationLabel = new wxStaticText( panel, wxID_ANY, "Destination location:" );

  auto projectPath = new wxStaticText( panel, wxID_ANY, "" );
  auto sourcePath = new wxStaticText( panel, wxID_ANY, "" );
  auto destinationPath = new wxStaticText( panel, wxID_ANY, "" );

  auto projectButton = new wxButton( panel, wxID_ANY, "Select ..." );
  projectButton->Bind( wxEVT_BUTTON, &SetupDialog::OnProjectButtonClick, this );

  auto sourceButton = new wxButton( panel, wxID_ANY, "Select ..." );
  sourceButton->Bind( wxEVT_BUTTON, &SetupDialog::OnSourceButtonClick, this );

  auto destinationButton = new wxButton( panel, wxID_ANY, "Select ..." );
  destinationButton->Bind( wxEVT_BUTTON, &SetupDialog::OnDestinationButtonClick, this );

  auto projectFormSizer = new wxBoxSizer( wxHORIZONTAL );
  projectFormSizer->Add( projectPath, 1, wxEXPAND );
  projectFormSizer->Add( projectButton, 0, wxALIGN_CENTER_VERTICAL );

  auto sourceFormSizer = new wxBoxSizer( wxHORIZONTAL );
  sourceFormSizer->Add( sourcePath, 1, wxEXPAND );
  sourceFormSizer->Add( sourceButton, 0, wxALIGN_CENTRE_VERTICAL );

  auto destinationFormSizer = new wxBoxSizer( wxHORIZONTAL );
  destinationFormSizer->Add( destinationPath, 1, wxEXPAND );
  destinationFormSizer->Add( destinationButton, 0, wxALIGN_CENTER_VERTICAL );

  sizer->Add( projectLabel, { 0, 0 }, { 1, 1 }, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL );
  sizer->Add( sourceLabel, { 1, 0 }, { 1, 1 }, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL );
  sizer->Add( destinationLabel, { 2, 0 }, { 1, 1 }, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL );
  sizer->Add( projectFormSizer, { 0, 1 }, { 1, 1 }, wxEXPAND );
  sizer->Add( sourceFormSizer, { 1, 1 }, { 1, 1 }, wxEXPAND );
  sizer->Add( destinationFormSizer, { 2, 1 }, { 1, 1 }, wxEXPAND );

  sizer->AddGrowableCol( 1 );
  panel->SetSizer( sizer );

  mainSizer->Add( panel, 1, wxEXPAND | wxALL, MARGIN );
  mainSizer->Add( CreateStdDialogButtonSizer( wxOK | wxCANCEL ) );
  this->SetSizerAndFit( mainSizer );
}

void SetupDialog::OnProjectButtonClick( wxCommandEvent &event ) {
  wxString path = ChooseDirectory( "Project Directory" );
  if ( !path.IsEmpty() ) {
    m_projectPath = path;
  }
  wxMessageBox( wxString::Format( "Project directory selected: %s", m_projectPath ) );
}

void SetupDialog::OnSourceButtonClick( wxCommandEvent &event ) {
  wxString path = ChooseDirectory( "Source Directory" );
  if ( !path.IsEmpty() ) {
    m_sourcePath = path;
  }
  wxMessageBox( wxString::Format( "Source directory selected: %s", m_sourcePath ) );
}

void SetupDialog::OnDestinationButtonClick( wxCommandEvent &event ) {
  wxString path = ChooseDirectory( "Destination Directory" );
  if ( !path.IsEmpty() ) {
    m_destinationPath = path;
  }
  wxMessageBox( wxString::Format( "Destination directory selected: %s", m_destinationPath ) );
}

wxString SetupDialog::ChooseDirectory( wxString message ) {
  wxDirDialog dialog( nullptr, message, "", wxDD_DEFAULT_STYLE );
  if ( dialog.ShowModal() == wxID_CANCEL ) {
    return "";
  }

  return dialog.GetPath();
}
