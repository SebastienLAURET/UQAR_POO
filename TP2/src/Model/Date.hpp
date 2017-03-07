#ifndef DATE_HPP
# define DATE_HPP

#include <iostream>
#include <sstream>
#include <ctime>

class Date {
public:
  Date() {
    time_t inst;
    std::time(&inst);
    tm *timeinfo = std::localtime(&inst);
    _day = timeinfo->tm_mday;
    _month = timeinfo->tm_mon;
    _year = timeinfo->tm_year + 1900;
  //  std::cout << _day << "/" << _month << "/" << _year << std::endl;
  }

  Date(Date const &date)
  : _day(date.getDay()), _month(date.getMonth()), _year(date.getYear()) {
  //  std::cout << _day << "/" << _month << "/" << _year << std::endl;

  }

  Date(std::string &date)
  : _day(-1), _month(-1), _year(-1) {
    std::string str;
    std::size_t begin = 0, end = 0;

    if ((end = date.find("-", begin)) != std::string::npos) {
      str = date.substr(begin, end - begin);
      //std::cout << "year : "<< str << std::endl;
      _year = std::stoi(str);
      begin = end + 1;
    }
    if ((end = date.find("-", begin)) != std::string::npos) {
      str = date.substr(begin, end - begin);
      //std::cout << "month : "<< str << std::endl;
      _month = std::stoi(str);
      begin = end + 1;
      str = date.substr(begin, date.size());
    //  std::cout << "day : "<< str << std::endl;
      _day = std::stoi(str);
    }
  //  std::cout << _day << "/" << _month << "/" << _year << std::endl;

  }

  Date(int day, int month, int year)
  : _day(day), _month(month), _year(year) {

  }

  ~Date() {

  }

  std::string toString() const {
    std::stringstream  tmp;
    tmp << _year << "-" << _month << "-" << _day;
    return tmp.str();
  }

  int         getDay() const {
    return _day;
  }

  int         getMonth() const {
    return _month;
  }

  int         getYear() const {
    return _year;
  }

  Date        operator-(Date const &date) {
      return Date(_day - date._day, _month - date._month, _year - date._year);
  }

  bool        operator==(Date const &date) {
    return (date._day == _day
          && date._month == _month
          && date._year == _year);
  }

private:
  int _day;
  int _month;
  int _year;
};

#endif //!DATE_HPP
