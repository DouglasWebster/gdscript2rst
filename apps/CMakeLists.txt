find_package(
  wxWidgets
  COMPONENTS core base
  REQUIRED)

if(wxWidgets_FOUND)
  message(
    STATUS "Found preinstalled wxWidgets libraries at ${wxWidgets_LIBRARIES}")
  set(wxWidgets_USE_PRECOMPILED_HEADERS_ON)
  include(${wxWidgets_USE_FILE})
  add_library(wxWidgets_external INTERFACE)
else()
  message(STATUS "Preinstalled wxWidgets not found.")
endif()

set(SRCS app.cpp setupdialog.cpp)

add_executable(app ${SRCS})


# Set the linker flags
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=mold")
message(STATUS "Using linker flags ${CMAKE_EXE_LINKER_FLAGS}")

target_compile_definitions(app PRIVATE WX_PRECOMP)
target_precompile_headers(app PRIVATE <wx/wxprec.h> <iostream>)

target_link_libraries(app ${wxWidgets_LIBRARIES})

target_compile_features(app PRIVATE cxx_std_20)
