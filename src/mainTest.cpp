#include "Personnes.hpp"

int main(int argc, char const *argv[]) {
  Personnes pers;

  for (size_t i = 0; i < 9; i++) {
      pers.push_front(new Personne());
      /* code */
  }

  std::cout << "STR :: "<<  pers.next->pers->_prenom << '\n';
  std::cout << "size : " << pers.length() << '\n';

  Personnes *tmp = pers.root->next;
  int i = 0;
  while (tmp->pers != NULL && i < 5) {
      tmp = tmp->erase();
      tmp = tmp->next;
      i++;
  }
  std::cout << "size : " << pers.length() << '\n';

  for (size_t i = 0; i < 9; i++) {
      pers.push_front(new Personne());
      /* code */
  }
  std::cout << "size : " << pers.length() << '\n';

  pers.clear();

  std::cout << "size : " << pers.length() << '\n';

  return 0;
}
