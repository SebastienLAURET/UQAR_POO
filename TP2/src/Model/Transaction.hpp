#ifndef TRANSACTION_HPP
# define TRANSACTION_HPP

#include "Date.hpp"
#include <sstream>

class Transaction {
public:
  Transaction(std::string date, std::string mont)
  : _date(date), _montant(std::stof(mont)){

  }
  Transaction(int const montant)
  : _montant(montant){

  }
  Transaction(Transaction const &tran)
  : _date(tran._date), _montant(tran._montant){

  }
  Date const &getDate() const {
    return _date;
  }

  double    getMontant() const {
      return _montant;
  }

  std::string tostring() {
    std::stringstream str;
    str << "," <<_date.toString()
        << "," <<_montant;
    return str.str();
  }
private:
  Date const  _date;
  double const   _montant;
};

#endif //!TRANSACTION_HPP
