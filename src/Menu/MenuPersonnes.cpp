#include "MenuPersonnes.hpp"
#include "MenuPrincipal.hpp"
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
    value = MenuPrincipal::getPromptValue(std::string("slection :"));

    switch (std::stoi(value)) {
      case 1:
        value = MenuPrincipal::getPromptValue(std::string("Nom"));
        tmpList = listPers->findByNom(value);
        break;
      case 2:
        value = MenuPrincipal::getPromptValue(std::string("Prenom"));
        tmpList = listPers->findByPrenom(value);
        break;
      case 3:
        value = MenuPrincipal::getPromptValue(std::string("Date"));
        tmpList = listPers->findByDate(Date(value));
        break;
      default:
        break;
    }

    if (tmpList->length() == 0) {
      value = MenuPrincipal::getPromptValue(std::string("Aucune Personne \n voulez vous encore test (y/n):"));
      return (value == "y");
    }

    Personnes *persSelect = tmpList->next;
    if (tmpList->length() > 1)
      persSelect = MenuPersonnes::_selectPersonne(tmpList);

    std::cout << "size list select : " << tmpList->length() << std::endl;
    while (true) {
      MenuPersonnes::_displayMenuPersonne(persSelect);

      value = MenuPrincipal::getPromptValue("selection:");

      switch (std::stoi(value)) {
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
    std::string value = MenuPrincipal::getPromptValue(std::string("slection :"));
    return listPers->at(std::stoi(value));
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
    MenuPrincipal::getPromptValue(std::string("erase"));
    std::cout << "size list select : " << list->length() << std::endl;
  //  delete pers->pers;
    list->remove(pers->pers);
    std::cout << "size list select : " << list->length() << std::endl;
  }
