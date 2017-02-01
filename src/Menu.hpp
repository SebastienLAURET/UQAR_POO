#ifndef MENU_HPP
# define MENU_HPP

#include <list>
#include <fstream>
#include <curses.h>
#include <term.h>

#include "Personne.hpp"

class Menu {
public:
  void operator()();

private:
  void _displayMenu();
  void _loadFile();
  void _addPersonne();
  void _printPersonne();
  void _savePersonne();

  std::list<Personne> _persList;
};

#endif //!MENU_HPP
