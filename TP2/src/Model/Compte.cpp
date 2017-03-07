#include "Compte.hpp"

Compte::Compte(int id, e_compte type, std::string const &nom,
   std::string const &prenom, Date naissance)
   : _id(id), _type(type), _nom(nom), _prenom(prenom),
   _naissance(naissance), _sold(0) {

}

int                                 Compte::getId() const {
  return _id;
}
Compte::e_compte                    Compte::getType() const {
  return _type;
}
std::string const                   &Compte::getNom() const {
  return _nom;
}
std::string const                   &Compte::getPrenom() const {
  return _prenom;
}
Date const                          &Compte::getNaissance() const {
  return _naissance;
}
double                              Compte::getSold() const {
  return _sold;
}
std::list<Transaction> const  &Compte::getListTransaction() const {
  return _listTransaction;
}

bool Compte::addTransaction(Transaction const &transaction) {
  if (_sold + transaction.getMontant() >= 0) {
    _sold += transaction.getMontant();
    _listTransaction.push_back(transaction);
    return true;
  }
  return false;
}

std::string Compte::toCsv(int idParent) {
  std::stringstream str;
  std::stringstream idP("");

  if (idParent > 0)
    idP << idParent;

  str << _id << ","
      << (char)_type << ","
      << _nom << ","
      << _prenom << ","
      << _naissance.toString() << ","
      << idP.str() << ","
      << _sold ;
  for (auto transac: _listTransaction) {
    str << "," << transac.getDate().toString()
        << "," << transac.getMontant();
  }
  return str.str();
}

void  Compte::setTransaction(std::vector<std::string> &v) {
  std::cout << "size : " << v.size() << std::endl;

  std::cout << v[6] << '\n';
  _sold = std::stof(v[6]);
  for (size_t i = 7; i < v.size(); i += 2) {
    Transaction tran(v[i], v[i+1]);
    _listTransaction.push_back(tran);
  }
}
