#include "Menu.hpp"

void Menu::operator()() {
  std::string nbTmp;

  while (true) {
      _displayMenu();
      getline(std::cin, nbTmp);
      switch (std::stoi(nbTmp)) {
        case 1:
          // Load
          _loadFile();
          break;
        case 2:
          _addPersonne();
          // Add
          break;
        case 3:
          _printPersonne();
          // Print
          break;
        case 4:
          _savePersonne();
          // Save
          break;
        case 5:
          // Exit
          putp(tgetstr("cl", NULL));
          return;
          break;
        default:
          break;
      }
  }
}
void Menu::_displayMenu() {
  putp(tgetstr("cl", NULL));
  std::cout << "1 - Load persone list" << '\n';
  std::cout << "2 - Add persone" << '\n';
  std::cout << "3 - Print persone list" << '\n';
  std::cout << "4 - Save persone list" << '\n';
  std::cout << "5 - Exit" << '\n';
  std::cout << "select : " << std::flush;
}

void Menu::_loadFile() {
/*  ifstream  fs;
  fs.open("./save/save.sv");
  if (fs.is_open()) {
    for (auto pers : _persList) {
    }
  }
  fs.close();*/
}

void Menu::_addPersonne() {
  Personne tmp;
  tmp.init();
  _persList.push_front(tmp);
}

void Menu::_printPersonne() {
  for (auto pers : _persList) {
    pers.display();
  }
}

void Menu::_savePersonne() {
  std::ofstream  fs;
  fs.open("./save/save.sv");
  if (fs.is_open()) {
    for (auto pers : _persList) {
      char *tmp = new char[sizeof(t_personne)];
      pers.toStruct(*((struct s_personne*)tmp));
      fs.write(tmp, sizeof(t_personne));
      delete tmp;
    }
  }
  fs.close();
}
