# cmake_minimum_required(VERSION 3.14...3.26)

# project(gdscript2rst LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# hack for buggy CMake's FindwxWidgets script
# if(DEFINED ENV_WX_CONFIG)
#    set(ENV{WX_CONFIG} ${ENV_WX_CONFIG})
# endif()

# set(wxWidgets_USE_STATIC 1)

# find_package(wxWidgets REQUIRED)

# set(SRCS main.cpp MainFrameBase.cpp)

# include(${wxWidgets_USE_FILE})

# add_executable(gdscript2rst ${SRCS})


# target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})