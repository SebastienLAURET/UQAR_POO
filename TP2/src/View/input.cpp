#include "input.hpp"

bool Input::is_integer(const std::string & s){
  size_t i = 0;

  if (s.at(i) == '-')
    ++i;
  for (; i < s.length(); i++) {
    if (s.at(i) < '0' && s.at(i) > '9' && s.at(i) == '.')
      return false;
  }
  return true;
}
bool Input::is_Date(const std::string &s) {
  std::vector<std::string> v;

  v = FactoryCSV::split(s, '/');
  if (v.size() != 3)
    return false;
  if (!is_integer(v[0])
      && std::stoi(v[0]) > 0
      && std::stoi(v[0]) <= 31)
    return false;
  if (!is_integer(v[1])
      && std::stoi(v[0]) > 0
      && std::stoi(v[0]) <= 12)
    return false;
  if (!is_integer(v[2])
      && std::stoi(v[0]) > 1900
      && std::stoi(v[0]) <= 2017)
    return false;

  return true;
}

double Input::getDouble(const std::string str) {
  std::string tmp;
  while (tmp == "") {
    tmp = Input::getString(str);
    if (Input::is_integer(tmp)){
      return std::stoi(tmp);
    } else {
      tmp.clear();
    }
  }
  return -1;
}

int Input::getInt(const std::string str) {
  std::string tmp;

  while (tmp == "") {
    tmp = Input::getString(str);
    if (Input::is_integer(tmp)){
      return std::stoi(tmp);
    } else {
      tmp.clear();
    }
  }
  return -1;
}

Date Input::getDate(const std::string str) {
  std::string tmp;
  while (tmp == "") {
    tmp = Input::getString(str);
    if (Input::is_Date(tmp)){
      return Date(tmp);
    } else {
      tmp.clear();
    }
  }
  std::string dateErr = "-1/-1/-1";
  return Date(dateErr);
}

std::string Input::getString(const std::string str) {
  std::cout << str ;
  std::string tmp;
  while (tmp == "") {
    getline(std::cin, tmp);
  }
  return tmp;
}
