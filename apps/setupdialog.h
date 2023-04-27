/** 
* @file setupdialog.h
* @author Douglas Webster
* @brief Collect the information required to scaffold a new project.
* @version 0.1
* @date 2023-04-26
* 
* @copyright Copyright (c) 2023
* 
*/

#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/dialog.h>
#include <wx/dirdlg.h>


/**
 * @brief Dialog for inputting the required file locations and defaults.
 * 
 * Collects the users preferred locations for:
 *  - Project :  Where the setup for Sphinx is stored.
 *  - Source: Where the Godot project file is.
 *  - Destination: Where the generated documentation should go.
 */
class SetupDialog : public wxDialog {
public:
  SetupDialog( wxWindow *parent );

private:
  wxString m_projectPath{};
  wxString m_destinationPath{};
  wxString m_sourcePath{};

  void OnProjectButtonClick(wxCommandEvent &event);
  void OnSourceButtonClick(wxCommandEvent &event);
  void OnDestinationButtonClick(wxCommandEvent &event);
  wxString ChooseDirectory(wxString message);
};