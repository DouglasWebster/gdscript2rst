#include <iostream>

#include "parse.h"

DwsGDS::GDScriptParse::GDScriptParse(std::string file = "") : m_file{ file }
{
  if (m_file.empty()) return;

  size_t dotIndex = m_file.find_last_of(".");
  if (dotIndex == std::string::npos) {
    m_file = "";
    return;
  }

  if (m_file.substr(dotIndex + 1) != "gd") { m_file = ""; }
}

int DwsGDS::GDScriptParse::parse()
{
  if (m_file.empty()) { return 1; }

  m_className = m_file;

  return 0;
}