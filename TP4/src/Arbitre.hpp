#ifndef ARBITRE_HPP
# define ARBITRE_HPP

#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Arbitre {
public:
  Arbitre() {
    srand(time(NULL));
  }
  ~Arbitre() {

  }



  std::string const & getLetterString() const {
    return _letterString;
  }
  std::string const getNewWord() {
    if (askGenMode())
      return genLettreString();
    else
      return getPromptLetterString();
  }

  int tryWord(std::string const &str) const {
    return Arbitre::tryWordStatic(_letterString, str);
  }

  static int tryWordStatic(std::string strRef, std::string const &strTest) {
    for (size_t iter = 0; iter < strTest.size(); ++iter) {
      if (Arbitre::testCar(strRef, strTest[iter])) {
        return -1;
      }
    }
    return strTest.size();
  }

  static bool testCar(std::string &str, char car) {

    for (auto it = str.begin(); it!=str.end(); ++it){
      if (*it == car) {
        str.erase(it);
        return false;
      }
    }
    return true;
  }

private:
  bool  askGenMode() {
    std::string word;
    do {
      std::cout << "Voulez vous generer aleatoirement le mot ? (y/n)"<< '\n';
      std::getline (std::cin, word);
    } while (word != "y" && word != "n");
    return (word == "y");
  }

  std::string const getPromptLetterString() {
    std::string word;
    do {
      std::cout << "Faite une proposition de 10 lettres"<< '\n';
      std::getline (std::cin, word);
    } while (word.size() != 10);
    _letterString = word;
    return word;
  }

  std::string const & genLettreString() {
    char tmpCar;

    _letterString.clear();
    for (size_t iter = 0; iter < 10; iter++) {
        tmpCar = genLetter();
        _letterString.append(&tmpCar, 1);
    }
    return _letterString;
  }

  char genLetter() const {
    if (rand()%10 <= 4)
      return (_refLetterConsonne.at(rand() % _refLetterConsonne.size()));
    else
      return (_refLetterVoyelle.at(rand() % _refLetterVoyelle.size()));
  }


  const std::string _refLetterConsonne = "bcdfghjklmnpqrstvwxz";
  const std::string _refLetterVoyelle = "aeiouy";

  std::string _letterString;
};

#endif //!ARBITRE_HPP
