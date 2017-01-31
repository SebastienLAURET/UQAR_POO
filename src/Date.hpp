#ifndef DATE_HPP
# define DATE_HPP

#include <sstream>
#include <string>

class Date {
public:
  Date();
  Date(std::string &date);
  Date(int,int,int);
  ~Date();

  std::string toString();

  int         getDay();
  int         getMonth();
  int         getYear();

private:
  int _day;
  int _month;
  int _year;
};

#endif //!DATE_HPP
