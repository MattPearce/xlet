#pragma once

#include <string>
#include <sstream>

// Patch for missing function
template <typename T>
std::string to_string_patch(const T &n)
{
  std::ostringstream stm;
  stm << n;
  return stm.str();
}
