#include "Personne.hpp"

Personne::Personne() {

}

Personne::~Personne() {

}
void Personne::init() {
  std::string tmpDate;
  std::string tmpNCivique;
  std::string tmpRue;
  std::string tmpVille;
  std::string tmpPays;

  std::cout << "Nom : ";
  std::cin >> _nom;
  std::cout << "prenom : ";
  std::cin >> _prenom;

  std::cout << "Date : ";
  std::cin >> tmpDate;
  _dateNaissance = Date(tmpDate);


  std::cout << "Numero civique : ";
  std::cin >> tmpNCivique;
  std::cout << "Rue : ";
  std::cin >> tmpRue;
  std::cout << "Ville : ";
  std::cin >> tmpVille;
  std::cout << "Pays : ";
  std::cin >> tmpPays;
  _adresse = Adresse(tmpNCivique, tmpRue, tmpVille, tmpPays);

  std::cout << "Salaire : ";
  std::cin >> _salaire;

  std::cout << "Heure par semaine : ";
  std::cin >> _salaire;

}

const std::string &Personne::getPrenom() {
 return _prenom;
}

const std::string &Personne::getNom() {
  return  _nom;
}

const Adresse     &Personne::getAdresse() {
  return _adresse;
}

const Date        &Personne::getDateNaissance() {
  return _dateNaissance;
}

double            Personne::getSalaire() {
  return _salaire;
}

int               Personne::getHeureParSemaine() {
  return _heureParSemaine;
}
