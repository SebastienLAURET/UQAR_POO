#ifndef INPUT_HPP
# define INPUT_HPP

#include <vector>
#include <iostream>
#include <cstring>
#include "Date.hpp"
#include "Factory.hpp"

namespace Input {
  bool is_integer(const std::string & s);
  bool is_Date(const std::string &s);
  double getDouble(const std::string str);
  int getInt(const std::string str);
  Date getDate(const std::string str);
  std::string getString(const std::string str);
};

#endif
