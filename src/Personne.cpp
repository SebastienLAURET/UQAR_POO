#include "Personne.hpp"

Personne::Personne() {

}

Personne::Personne(t_personne &pers)
: _prenom(pers.prenom), _nom(pers.nom), _adresse(pers.addr),
 _dateNaissance(pers.date), _salaire(pers.salaire),
 _heureParSemaine(pers.heureSemaine) {

}

Personne::~Personne() {

}

void Personne::init() {
  putp(tgetstr("cl", NULL));

  std::string tmp;
  std::string tmpNCivique;
  std::string tmpRue;
  std::string tmpVille;
  std::string tmpPays;

  std::cout << "Nom : ";
  std::getline (std::cin, _nom);
  std::cout << "prenom : ";
  std::getline (std::cin, _prenom);

  std::cout << "Date : ";
  std::getline (std::cin, tmp);
  _dateNaissance = Date(tmp);


  std::cout << "Numero civique : ";
  std::getline (std::cin, tmpNCivique);
  std::cout << "Rue : ";
  std::getline (std::cin, tmpRue);
  std::cout << "Ville : ";
  std::getline (std::cin, tmpVille);
  std::cout << "Pays : ";
  std::getline (std::cin, tmpPays);
  _adresse = Adresse(tmpNCivique, tmpRue, tmpVille, tmpPays);

  std::cout << "Salaire : ";
  std::getline (std::cin, tmp);
  _salaire = std::stoi(tmp);

  std::cout << "Heure par semaine : ";
  std::getline (std::cin, tmp);
  _heureParSemaine = std::stoi(tmp);
}

void Personne::toStruct(t_personne &pers) {
  size_t  size;

  std::memset(&pers, 0, sizeof(t_personne));
  size = (_prenom.size() <= 10) ? _prenom.size() : 10;
  std::memcpy(&pers.prenom, _prenom.c_str(), size);
  size = (_nom.size() <= 10) ? _nom.size() : 10;
  std::memcpy(&pers.nom, _nom.c_str(), size);
  pers.salaire = _salaire;
  pers.heureSemaine = _heureParSemaine;
  _dateNaissance.toStruct(pers.date);
  _adresse.toStruct(pers.addr);
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

void              Personne::display() {

  std::cout << "------------------------------" << std::endl;
  std::cout << "Prenom : " <<  _prenom << std::endl;
  std::cout << "Nom : " << _nom << std::endl;
  std::cout << "Date de naissance : " << _dateNaissance.toString() << std::endl;
  std::cout << "Numero civique : " << _adresse.getNCivique() << std::endl;
  std::cout << "Rue : " << _adresse.getRue() << std::endl;
  std::cout << "Ville : " << _adresse.getVille() << std::endl;
  std::cout << "Pays : " << _adresse.getPays() << std::endl;
  std::cout << "Salaire : " << _salaire << std::endl;
  std::cout << "Heure/semaine : " << _heureParSemaine << std::endl;
  std::cout << "------------------------------" << std::endl;

}
