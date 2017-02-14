#include "MenuPrincipal.hpp"
#include "MenuPersonnes.hpp"

void MenuPrincipal::run() {
  Personnes   persList;
  std::string nbTmp;

  while (true) {
      _displayMenuPrincipal();
      switch (Input::getInt("select :")) {
        case 1: _loadFile(persList);      break;
        case 2: _addPersonne(persList);   break;
        case 3: _printPersonne(persList); break;
        case 4: _savePersonne(persList);  break;
        case 5: MenuPersonnes::searchPersonne(&persList); break;
        case 6: _printSalaire(persList);   break;
        case 7: system("clear");          return;
        default:                          break;
      }
  }
}
void MenuPrincipal::_displayMenuPrincipal() {
  system("clear");
  std::cout << "1 - Load persone list" << std::endl;
  std::cout << "2 - Add persone" << std::endl;
  std::cout << "3 - Print persone list" << std::endl;
  std::cout << "4 - Save persone list" << std::endl;
  std::cout << "5 - Edition" << std::endl;
  std::cout << "6 - salaire" << std::endl;
  std::cout << "7 - Exit" << std::endl;
}

void MenuPrincipal::_loadFile(Personnes &persList) {
  std::ifstream     fs;

  fs.open("./save/save.sv");
  fs.seekg (0, fs.end);
  int length = fs.tellg();
  fs.seekg (0, fs.beg);

  char *tmpStr = (char*)std::malloc(length * sizeof(char));
//  char *tmpStr = new char[length];
  t_personne        *persTmp;

  if (fs.is_open()) {
    fs.read(tmpStr, length);
    for (int i = 0; i < length; i+=sizeof(t_personne)) {
      persTmp = ((t_personne*)&tmpStr[i]);
      persList.push_front(new Personne(*persTmp));
    }
  }
  fs.close();
  free(tmpStr);
}

void MenuPrincipal::_addPersonne(Personnes &persList) {
  Personne *tmp = new Personne();
  tmp->init();
  persList.push_front(tmp);
}

void MenuPrincipal::_printPersonne(Personnes &persList) {
  Personnes       *listPers = persList.next;

  while (listPers->pers != NULL) {
    listPers->pers->display();
    listPers = listPers->next;
  }
  std::string tmp;
  std::getline (std::cin, tmp);
}


void MenuPrincipal::_savePersonne(Personnes &persList) {
  std::ofstream   fs;
  t_personne      tmpPers;
  std::string     tmpStr;
  Personnes       *listPers = persList.next;


  fs.open("./save/save.sv");
  if (fs.is_open()) {
    while (listPers->pers != NULL) {
      listPers->pers->toStruct(tmpPers);
      tmpStr += std::string(((char*)&tmpPers), sizeof(t_personne));
      listPers = listPers->next;
    }
    std::cout << tmpStr.size() << std::endl;
    fs << tmpStr;
  }
  fs.close();
}

void MenuPrincipal::_printSalaire(Personnes &persList) {
  Personnes       *listPers = persList.next;
  double tmpSalaire;
  while (listPers->pers != NULL) {
    tmpSalaire = listPers->pers->_salaire * listPers->pers->_heureParSemaine;
    std::cout << listPers->pers->_prenom << " "
              << listPers->pers->_nom << " : "
              << tmpSalaire << std::endl;
    listPers = listPers->next;
  }
  std::string tmp;
  std::getline (std::cin, tmp);
}
