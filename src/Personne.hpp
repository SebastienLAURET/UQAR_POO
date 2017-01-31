#ifndef PERSONNE_HPP
# define PERSONNE_HPP

#include <iostream>
#include <string>

#include "Date.hpp"
#include "Adresse.hpp"

class Personne {
public:
  Personne();
  ~Personne();

  void              init();
  const std::string &getPrenom();
  const std::string &getNom();
  const Adresse     &getAdresse();
  const Date        &getDateNaissance();
  double            getSalaire();
  int               getHeureParSemaine();
  void              display();
private:
  std::string _prenom;
  std::string _nom;
  Adresse     _adresse;
  Date        _dateNaissance;
  double      _salaire;
  int         _heureParSemaine;
};

#endif //!PERSONNE_HPP
