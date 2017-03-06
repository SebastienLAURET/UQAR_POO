#ifndef INPUT_HPP
# define INPUT_HPP

#include <iostream>
#include <regex>
#include <cstring>
#include "Date.hpp"

namespace Input {
  bool is_integer(const std::string & s);
  bool is_Date(const std::string &s);
  double getDouble(std::string str);
  int getInt(std::string str);
  Date getDate(std::string str);
  std::string getString(std::string str);
};

#endif
