#ifndef MENUPRINCIPAL_HPP
# define MENUPRINCIPAL_HPP

#include <fstream>
#include "input.hpp"
#include "Personnes.hpp"

namespace MenuPrincipal {
  void run();
  void _displayMenuPrincipal();
  void _loadFile(Personnes &);
  void _addPersonne(Personnes &);
  void _printPersonne(Personnes &);
  void _savePersonne(Personnes &);
  void _printSalaire(Personnes &);
};

#endif //!MENUPRINCIPAL_HPP
