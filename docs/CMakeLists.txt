set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_STRIP_FROM_PATH "/mnt/DEV/cpp_work/gdscript2rst")
set(DOXYGEN_PROJECT_NAME "GDscriptToSpinx")
set(DOXYGEN_PROJECT_BRIEF "Parses the gdsript files in a Godot project and creates API documentation.")
set(DOXYGEN_PROJECT_LOGO "${CMAKE_CURRENT_SOURCE_DIR}/GDScript2SphinxLogo1.png")

doxygen_add_docs(docs modern/lib.hpp "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md" "${PROJECT_SOURCE_DIR}/apps"
                 WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
