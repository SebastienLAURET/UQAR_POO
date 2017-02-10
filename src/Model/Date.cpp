#include "Date.hpp"

Date::Date() {

}

Date::Date(t_date &date)
: _day(date.day), _month(date.month), _year(date.year) {

}

Date::Date(std::string &date) {
  std::string str;
  std::size_t begin = 0, end = 0;

  if ((end = date.find("/", begin)) != std::string::npos) {
    str = date.substr(begin, end - begin);
    _day = std::stoi(str);
    begin = end + 1;
  }
  if ((end = date.find("/", begin)) != std::string::npos) {
    str = date.substr(begin, end - begin);
    _month = std::stoi(str);
    begin = end + 1;
    str = date.substr(begin, date.size());
    _year = std::stoi(str);
  }
}

Date::Date(int day, int month, int year)
: _day(day), _month(month), _year(year) {

}

Date::~Date() {

}

void Date::toStruct(t_date &date) {
  date.day = _day;
  date.month = _month;
  date.year = _year;
}

std::string Date::toString() {
  std::stringstream  tmp;

  tmp << _day << "/" << _month << "/" << _year;
  return tmp.str();
}

int         Date::getDay() {
  return _day;
}

int         Date::getMonth() {
  return _month;
}

int         Date::getYear() {
  return _year;
}

bool        Date::operator==(Date &date) {
  return (date._day == _day
        && date._month == _month
        && date._year == _year);
}
