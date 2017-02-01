#ifndef PERSONNE_HPP
# define PERSONNE_HPP

#include <iostream>
#include <string>

#include <curses.h>
#include <term.h>

#include "Date.hpp"
#include "Adresse.hpp"

typedef struct s_personne {
    char      prenom[10];
    char      nom[10];
    t_adresse addr;
    t_date    date;
    double    salaire;
    int       heureSemaine;
}              t_personne;

class Personne {
public:
  Personne();
  Personne(t_personne&);
  ~Personne();

  void              init();
  void              toStruct(t_personne&);
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
