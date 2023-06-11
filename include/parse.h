#pragma once
#include <string>

namespace DwsGDS {

class GDScriptParse
{
public:
  GDScriptParse() {}
  GDScriptParse(std::string file);

  int parse();
  std::string getClassName() {return m_className;}

private:
    std::string m_file {};
    std::string m_className {};
};

}// namespace DwsGDS
