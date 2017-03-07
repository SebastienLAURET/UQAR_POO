#ifndef MENUVIEW_HPP
# define MENUVIEW_HPP

#include <list>
#include <sstream>
//#include <cstdlib>
#include "CompteNormal.hpp"
#include "CompteEnfant.hpp"
#include "CompteEpargne.hpp"
#include "input.hpp"
#include "CompteController.hpp"

class MenuView {
public:
  MenuView (CompteController &compteController)
  : _compteController(compteController){

  }

  int displayMenu() {
    system("clear");
    std::stringstream str;

    str << "-------------------------" << "\n"
        << "----------MENU-----------" << "\n"
        << "-------------------------" << "\n"
        << "- 1/ list des Comptes   -" << "\n"
        << "- 2/ Detail du compte.  -" << "\n"
        << "- 3/ Ajouter un compte  -" << "\n"
        << "- 4/ supprimer un compte-" << "\n"
        << "- 5/ faire un Retrai    -" << "\n"
        << "- 6/ Ajouter de l'argent-" << "\n"
        << "- 0/ Quitter            -" << "\n"
        << "-------------------------" << "\n"
        << "selection : " ;
    return Input::getInt(str.str());
  }

  void displayListCompte() {
    std::list<Compte*> list = _compteController.getListCompte();
    std::cout << "id\t\t:Nom\t\t:Prenom\t\t:Date"<< '\n';
    for (auto compte : list) {
      std::cout << compte->getId() << "\t\t"
                << compte->getNom() << ((compte->getNom().length() >= 9) ? "\t" : "\t\t")
                << compte->getPrenom() << ((compte->getPrenom().length() >= 9) ? "\t" : "\t\t")
                << compte->getNaissance().toString() << '\n';
    }
    std::string str;
    std::getline(std::cin, str);
  }
  void displayCompte() {
    if (_compteController.getListCompte().size() == 0)
      return;
    Compte* compte = getCompte();

    std::cout << "id\t:" << compte->getId() << '\n'
              << "Nom\t:" << compte->getNom() << '\n'
              << "Prenom\t:" << compte->getPrenom() << '\n'
              << "Date\t:" << compte->getNaissance().toString() << '\n'
              << "Sold\t:" << compte->getSold() << '\n'
              << "TRANSACTION :: " << '\n';
    for (auto transac : compte->getListTransaction()) {
      std::cout << transac.getDate().toString()
                << " -- " << transac.getMontant() << '\n';
    }
    std::string str;
    std::getline(std::cin, str);
  }

  void ajouterCompte() {
    int id = _compteController.getNewId();
    int idParent = 0;
    int type;
    std::string nom, prenom;
    Date date;
    CompteNormal *compteParent;

    do {

      do {
        system("clear");
        type = Input::getInt("Créer un compte :\n1/Epargne\n2/normal\nselection:");
      } while (type != 1 && type != 2);

      nom = Input::getString("nom : ");
      prenom = Input::getString("prenom : ");
      date = Input::getDate("date Naissance : ");

      std::cout << (Date() - date).getYear() << '\n';
      std::cout << Date().getYear() << " " << date.getYear() << '\n';

      if ((Date() - date).getYear() < 10) {
        std::cout << "Ce compte doit avoir un compte rataché" << '\n';
        do {
          idParent = Input::getInt("id du compte parent:");
        } while(compteParent = reinterpret_cast<CompteNormal*>(_compteController.findCompteById(idParent)));
      }
    } while(Input::getString("tout est correct? (y/n)") != "y");

    if (type == 1) {
      _compteController.addCompte(new CompteEpargne(id, nom, prenom, date));
    } else if (type == 2 && idParent == 0) {
      _compteController.addCompte(new CompteNormal(id, nom, prenom, date));
    } else if (type == 2 && idParent != 0){
      _compteController.addCompte(new CompteEnfant(id, nom, prenom, date, *compteParent));
    }
  }

  Compte  *getCompte() {
    Compte *compte;
    int idParent = 0;
    do {
      idParent = Input::getInt("selection id du compte:");
    } while((compte = _compteController.findCompteById(idParent)) == nullptr);
    return compte;
  }

  void supprimerCompte() {
    if (_compteController.getListCompte().size() == 0)
      return;
    Compte *compte = getCompte();
    _compteController.supprimerCompte(compte);
  }

  void faireRetrait() {
    if (_compteController.getListCompte().size() == 0)
      return;
    Compte *compte = getCompte();
    double montant;

    do {
      montant = Input::getDouble("Montant du retrait :");
    } while(montant <= 0);
    Transaction transaction(-montant);
    if (!compte->makeTransaction(transaction)) {
      std::cout << "Transacion refuser" << std::endl;
      std::string tmp;
      std::getline(std::cin, tmp);
    }
  }
  void ajouterDeLArgent(){
    if (_compteController.getListCompte().size() == 0)
      return;
    Compte *compte = getCompte();
    double montant;

    do {
      montant = Input::getDouble("Montant du versement :");
    } while(montant <= 0);
    Transaction transaction(montant);
    if (!compte->makeTransaction(transaction)) {
      std::cout << "Transacion refuser" << std::endl;
      std::string tmp;
      std::getline(std::cin, tmp);
    }
  }

private:
  CompteController &_compteController;
};

#endif //!MENUVIEW_HPP
