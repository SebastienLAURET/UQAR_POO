#ifndef DATE_HPP
# define DATE_HPP

#include <sstream>
#include <string>
typedef struct  s_date {
  int day;
  int month;
  int year;
}               t_date;

struct Date {
  Date();
  Date(t_date&);
  Date(std::string &date);
  Date(int,int,int);
  ~Date();

  bool        operator==(Date&);
  void        toStruct(t_date &);
  std::string toString();

  int         getDay();
  int         getMonth();
  int         getYear();

  int _day;
  int _month;
  int _year;
};

#endif //!DATE_HPP
