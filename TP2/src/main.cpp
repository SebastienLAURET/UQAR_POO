#include "CompteController.hpp"
#include "MenuPrincipalView.hpp"

int main() {
  CompteController compteContoller;
  MenuView menu(compteContoller);
  int selection;

  while (selection = menu.displayMenu()) {
    switch (selection) {
      case 1: menu.displayListCompte(); break;
      case 2: menu.ajouterCompte(); break;
      case 3: menu.supprimerCompte(); break;
      case 4: menu.faireRetrait(); break;
      case 5: menu.ajouterDeLArgent(); break;
      default: break;
    }
  }


  return 0;
}
