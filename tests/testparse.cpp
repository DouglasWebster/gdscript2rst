#include <catch2/catch_test_macros.hpp>

#include <memory>

#include "../include/parse.h"

TEST_CASE("GDScriptParse expects a script to parse", "[GDScriptParse]")
{


  SECTION("Supplying an empty string is returns non zero  ")
  {

    DwsGDS::GDScriptParse script;

    REQUIRE(script.parse() != 0);
  }

  SECTION("Supplying and invalid script file returns non zero") {
    DwsGDS::GDScriptParse script("anything.xxx");

    REQUIRE(script.parse() != 0);
  }

  SECTION("Supplying valid file is OK") {
    std::string dummyScriptFile{"project/root/source/anything.gd"};
    DwsGDS::GDScriptParse script(dummyScriptFile);

    REQUIRE(script.parse() == 0);
    std::string className = script.getClassName();
    WARN("The class name is: " << className);
    REQUIRE(className == dummyScriptFile);
  }
}
