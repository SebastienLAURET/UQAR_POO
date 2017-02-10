#ifndef MENUPRINCIPAL_HPP
# define MENUPRINCIPAL_HPP

#include <fstream>

#include "Personnes.hpp"

namespace MenuPrincipal {
  std::string getPromptValue(std::string);
  void run();
  void _displayMenuPrincipal();
  void _loadFile(Personnes &);
  void _addPersonne(Personnes &);
  void _printPersonne(Personnes &);
  void _savePersonne(Personnes &);
};

#endif //!MENUPRINCIPAL_HPP
