#include "input.hpp"

bool Input::is_integer(const std::string & s){
    return std::regex_match(s, std::regex("[0-9]+"));
}
bool Input::is_Date(const std::string &s) {
    return std::regex_match(s, std::regex("[0-9]+[/][0-9]+[/][0-9]+"));
}

double Input::getDouble(std::string str) {
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

int Input::getInt(std::string str) {
  std::string tmp;
  std::cout << "getint" << std::endl;

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

Date Input::getDate(std::string str) {
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
std::string Input::getString(std::string str) {
  std::cout << str ;
  std::string tmp;
  while (tmp == "") {
    getline(std::cin, tmp);
  }
  return tmp;
}
