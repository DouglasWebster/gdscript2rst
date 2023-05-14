/**
 * @file app.h
 * @author Douglas Webster
 * @brief Main entry point for the GDScriptToSpinx utility
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/log.h>
#include <wx/dirdlg.h>

#include "setupdialog.h"

/**
 * @brief Generate the wxWidgets program.
 */
class MyApp : public wxApp {
public:
  virtual bool OnInit() override;
};

/**
 * @brief The main window for the program.
 *
 * The window consists of a menu, status bar and blank are for use by the program subsystem.
 */
class MainFrame : public wxFrame {
private:
  wxMenuBar *m_MainFrameMenu;
  wxMenu *m_menuFile;
  wxMenu *m_menuCheck;
  wxMenu *m_menu3;

  wxStatusBar *m_statusBar1;
  bool m_pythonInstalled{ false };
  int m_pythonVersionMain{};

public:
  /**
   * @brief Single constructor for the main frame
   * @param parent A pointer to the parent window.
   * @param id The id of this window.
   * @param title A wxString containing the title for this window.
   * @param pos The default position of this window relative to it's parent - wxDefaultPosition lets
   * wxWidgets choose.
   * @param size The dimensions of this frame - wxDefaultSize lets wxWidgets choose.
   * @param style The style for this frame;
   *
   * The frame is created with wxDEFAULT_FRAME_STYLE | wxMAXIMIZE_BOX | wxMINIMIZE_BOX |
   * wxTAB_TRAVERSAL which allows for resizing the window and for tab cycling.
   */
  MainFrame( wxWindow *parent = nullptr, wxWindowID id = wxID_ANY,
             const wxString &title = wxEmptyString, const wxPoint &pos = wxDefaultPosition,
             const wxSize &size = wxDefaultSize,
             long style = wxDEFAULT_FRAME_STYLE | wxMAXIMIZE_BOX | wxMINIMIZE_BOX |
                          wxTAB_TRAVERSAL );

  virtual void OnClose( wxCommandEvent &event );
  virtual void startNewProject( wxCommandEvent &event );

  /**
   * @brief get the major version of python currently in use
   */
  void OnCheckPython();

  int GetPythonVersion() { return m_pythonVersionMain; }
  
};