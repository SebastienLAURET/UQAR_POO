#include <iostream>
#include "Robot.hpp"
#include "Arbitre.hpp"

int main(int, char const **) {
  Arbitre arb;
  Robot   robot;
  std::string letterTest, wordTest;
  int   nbTest;

  while (1) {
    system("clear");
    letterTest = arb.getNewWord();
    std::cout << "Les lettres disponible sont :" << letterTest << std::endl;

    nbTest  = 1;
    do {
      std::cout << "Faite une proposition [" << nbTest << "/10]" << '\n';
      std::getline (std::cin, wordTest);
    } while ((wordTest.size() == 0
              || arb.tryWord(wordTest) == -1)
            && nbTest++ < 10);

    do {
      std::cout << "Les lettres disponible sont :" << letterTest << std::endl;
      wordTest = robot.searchWord(letterTest);
      std::cout << "Word selectionner par robot : ["<< wordTest <<"]" << '\n';
    } while (arb.tryWord(wordTest) == -1);

    std::getline (std::cin, wordTest);
  }

  return 0;
}
