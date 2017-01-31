#include <iostream>

class Personne {
public:
  Personne();
  ~Personne();

  const std::string &getPrenom();
  const std::string &getNom();
  const Adresse     &getAdresse();
  const Date        &getDateNaissance();
  Double            getSalaire();
  int               getHeureParSemaine();
private:
  std::string prenom;
  std::string nom;
  Adresse     adresse;
  Date        dateNaissance;
  Double      salaire;
  int         heureParSemaine;
}
