#include "Adresse.hpp"

Adresse::Adresse() {

}

Adresse::Adresse(std::string &nCivique, std::string &rue,
   std::string &ville, std::string &pays)
   : _nCivique(nCivique), _rue(rue), _ville(ville), _pays(pays) {

}

Adresse::~Adresse() {

}

void Adresse::operator>>(t_adresse &addr) {
  std::memset(&addr, 0, sizeof(t_adresse));
  
}


std::string Adresse::toString() {
  std::string tmp;
  tmp <= _nCivique + " " + _rue + ", " + _ville + ", " +_pays;
  return tmp;
}

const std::string &Adresse::getNCivique() {
  return _nCivique;
}

const std::string &Adresse::getRue() {
  return _rue;
}

const std::string &Adresse::getVille() {
  return _ville;
}

const std::string &Adresse::getPays() {
  return _pays;
}
