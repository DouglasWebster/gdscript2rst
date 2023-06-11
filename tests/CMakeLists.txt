# Testing library
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.3.2)
FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

# Tests need to be added as executables first
add_executable(testparse testparse.cpp)

# I'm using C++20 in the test
target_compile_features(testparse PRIVATE cxx_std_20)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(testparse PRIVATE Catch2::Catch2WithMain gdscript_parse)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME testparsetest COMMAND testparse)
