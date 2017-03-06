#include "Factory.hpp"

int main(int argc, char const *argv[]) {
  FactoryCSV &toto = FactoryCSV::getFactory();
  std::list<Compte*> &list = toto.getList();

  std::string str;
  for (auto elem : list) {
    str = elem->toString();
    std::cout << str << '\n';
  }

  return 0;
}
