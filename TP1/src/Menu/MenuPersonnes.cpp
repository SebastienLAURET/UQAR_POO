#include "MenuPersonnes.hpp"
#include "MenuPrincipal.hpp"
#include "input.hpp"

  void MenuPersonnes::searchPersonne(Personnes *listPers) {
    MenuPersonnes::_displayMenuSearch();
    while (search(listPers)) {
      MenuPersonnes::_displayMenuSearch();
    }
  }
  void MenuPersonnes::_displayMenuSearch() {
    system("clear");
    std::cout << "chercher par :" << std::endl;
    std::cout << "\t" << "1 - Nom" << std::endl;
    std::cout << "\t" << "2 - Prenom" << std::endl;
    std::cout << "\t" << "3 - Date" << std::endl;
  }

  bool MenuPersonnes::search(Personnes *listPers) {
    Personnes *tmpList = NULL;

    std::string value;
    switch (Input::getInt("selection :")) {
      case 1:
        value = Input::getString("nom : ");
        tmpList = listPers->findByNom(value);
        break;
      case 2:
        value = Input::getString("prenom : ");
        tmpList = listPers->findByPrenom(value);
        break;
      case 3:

        tmpList = listPers->findByDate(Input::getDate("date de Naissance : "));
        break;
      default:
        break;
    }

    if (tmpList->length() == 0) {
      value = Input::getString("Aucune Personne \n voulez vous encore test (y/n):");
      return (value == "y");
    }

    Personnes *persSelect = tmpList->next;
    if (tmpList->length() > 1)
      persSelect = MenuPersonnes::_selectPersonne(tmpList);

    std::cout << "size list select : " << tmpList->length() << std::endl;
    while (true) {
      MenuPersonnes::_displayMenuPersonne(persSelect);

      switch (Input::getInt("selection : ")) {
        case 1: MenuPersonnes::edit(persSelect); break;
        case 2: MenuPersonnes::deletePers(listPers, persSelect); return false;
        case 3: return true;
        case 4: return false;
      }
    }
  }

  Personnes *MenuPersonnes::_selectPersonne(Personnes *listPers) {
    system("clear");
    int i = 0;
    Personnes *iter = listPers->root->next;
    while (iter->pers != NULL) {
      std::cout << i++ << " -- ";
      iter->pers->display();
      iter = iter->next;
    }
    return listPers->at(Input::getInt("selection"));
  }

  void MenuPersonnes::_displayMenuPersonne(Personnes *pers) {
    system("clear");
    pers->pers->display();
    std::cout << "Profile :" << std::endl;
    std::cout << "\t" << "1 - edit" << std::endl;
    std::cout << "\t" << "2 - supprimer" << std::endl;
    std::cout << "\t" << "3 - chercher autre personnes" << std::endl;
    std::cout << "\t" << "4 - fin" << std::endl;

  }
  void MenuPersonnes::edit(Personnes *pers) {
    pers->pers->init();
  }

  void MenuPersonnes::deletePers(Personnes *list, Personnes *pers) {
    pers->pers->display();
    delete pers->pers;
    list->remove(pers->pers);
  }
