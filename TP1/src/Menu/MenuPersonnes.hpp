#ifndef MENUPERSONNES_HPP
# define MENUPERSONNES_HPP

#include "Personnes.hpp"

namespace MenuPersonnes {
  void searchPersonne(Personnes *listPers);
  void _displayMenuSearch();
  bool search(Personnes *listPers);
  Personnes *_selectPersonne(Personnes *listPers);
  void _displayMenuPersonne(Personnes *pers);
  void edit(Personnes *pers);
  void deletePers(Personnes *, Personnes *pers);
};

#endif //!MENUPERSONNES_HPP
