#include "Adresse.hpp"

Adresse::Adresse() {

}

Adresse::Adresse(t_adresse &addr)
: _nCivique(addr.nCivique), _rue(addr.rue), _ville(addr.ville), _pays(addr.pays) {

}

Adresse::Adresse(std::string &nCivique, std::string &rue,
   std::string &ville, std::string &pays)
   : _nCivique(nCivique), _rue(rue), _ville(ville), _pays(pays) {

}

Adresse::~Adresse() {

}

void Adresse::toStruct(t_adresse &addr) {
  size_t  size;

  std::memset(&addr, 0, sizeof(t_adresse));
  size = _nCivique.size();
  std::memcpy(&(addr.nCivique), _nCivique.c_str(), size);
  size = _rue.size();
  std::memcpy(&(addr.rue), _rue.c_str(), size);
  size = _ville.size();
  std::memcpy(&(addr.ville), _ville.c_str(), size);
  size = _pays.size();
  std::memcpy(&(addr.pays), _pays.c_str(), size);
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
