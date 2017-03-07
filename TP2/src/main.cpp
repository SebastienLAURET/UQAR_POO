#include "CompteController.hpp"
#include "MenuPrincipalView.hpp"

int main() {
  CompteController compteContoller;
  MenuView menu(compteContoller);
  int selection;

  while ((selection = menu.displayMenu()) != 0) {
    switch (selection) {
      case 1: menu.displayListCompte(); break;
      case 2: menu.displayCompte(); break;
      case 3: menu.ajouterCompte(); break;
      case 4: menu.supprimerCompte(); break;
      case 5: menu.faireRetrait(); break;
      case 6: menu.ajouterDeLArgent(); break;
      default: break;
    }
  }


  return 0;
}
