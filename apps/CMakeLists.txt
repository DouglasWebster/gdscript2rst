find_package(wxWidgets COMPONENTS core base REQUIRED)

if (wxWidgets_FOUND) 
  message(STATUS "Found preinstalled wxWidgets libraries at ${wxWidgets_LIBRARIES}")
    include(${wxWidgets_USE_FILE})
    add_library(wxWidgets_external INTERFACE)
else()
  message(STATUS "Preinstalled wxWidgets not found.")
endif()

set(SRCS app.cpp MainFrameBase.cpp )

add_executable(app ${SRCS})

target_link_libraries(app ${wxWidgets_LIBRARIES})

target_compile_features(app PRIVATE cxx_std_20)

