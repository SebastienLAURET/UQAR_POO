#ifndef COMPTECOMTROLLER_HPP
# define COMPTECOMTROLLER_HPP

#include <list>
#include "Compte.hpp"
#include "Factory.hpp"

class CompteController {
public:
  CompteController ()
    : _listCompte(FactoryCSV::getFactory().getList()) {

  }
  ~CompteController () {
      delete &FactoryCSV::getFactory();
  }

  Compte*  findCompteById(int id) {
    for (auto compte : _listCompte) {
      if (compte->getId() == id) {
        return compte;
      }
    }
    return nullptr;
  }

  std::list<Compte*>  findCompteByNom(std::string &nom) {
    std::list<Compte*> list;

    for (auto compte : _listCompte) {
      if (compte->getNom() == nom) {
        list.push_back(compte);
      }
    }
    return list;
  }

  std::list<Compte*>  findCompteByPrenom(std::string &prenom) {
    std::list<Compte*> list;

    for (auto compte : _listCompte) {
      if (compte->getPrenom() == prenom) {
        list.push_back(compte);
      }
    }
    return list;
  }

  std::list<Compte*> &getListCompte() {
    return _listCompte;
  }

  int getNewId() {
    int newId = 1;
    while (findCompteById(newId) != nullptr) {
      ++newId;
    }
    return newId;
  }

  void addCompte(Compte *compte) {
    _listCompte.push_back(compte);
  }

  void supprimerCompte(Compte *compte) {
    _listCompte.remove(compte);
    delete compte;
  }
private:
  std::list<Compte*> &_listCompte;
};

#endif //!COMPTECOMTROLLER_HPP
