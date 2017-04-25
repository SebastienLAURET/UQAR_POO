#ifndef ROBOT_HPP
# define ROBOT_HPP

#include <fstream>
#include <list>
#include "points.hpp"
#include "Arbitre.hpp"

class Robot {
public:
  Robot() {
    loadDictionaire();
  }
  ~Robot() {

  }

  static bool compareSizeString (const std::string& first, const std::string& second)
  {
    return (first.length() > second.length());
  }
  static bool comparePointString (const std::string& first, const std::string& second)
  {
    return (scrabble::score(first) > scrabble::score(second));
  }

  std::string searchWord(std::string const &word) {

    searchLongWord(word);
    return searchScoreWord(word);
  }

  std::string searchLongWord(std::string const &word) {
    int i = 0;

    for (auto it : _dictionaireMotLong){
      ++i;
      if (Arbitre::tryWordStatic(word, it) != -1) {
        std::cout << "------------------" << std::endl;
        std::cout << "nb mots analysé :"<< i << std::endl;
        std::cout << "mot +  : long ["<< it <<"]" << std::endl;
        std::cout << "------------------" << std::endl;
        return it;
      }
    }
    return "";
  }

  std::string searchScoreWord(std::string const &word) {
    int i = 0;

    for (auto it : _dictionaireMotPoint){
      ++i;
      if (Arbitre::tryWordStatic(word, it) != -1) {
        std::cout << "------------------" << std::endl;
        std::cout << "nb mots analysé :"<< i << std::endl;
        std::cout << "mot + de points : ["<< it <<"]" << std::endl;
        std::cout << "------------------" << std::endl;
        return it;
      }
    }
    return "";
  }

private:
  void loadDictionaire() {
    std::ifstream file("./Asset/Dico.txt");
    std::string str;

    while (std::getline(file, str)) {
      _dictionaireMotLong.push_front(str);
      _dictionaireMotPoint.push_front(str);
    }
    _dictionaireMotLong.sort(Robot::compareSizeString);
    _dictionaireMotPoint.sort(Robot::comparePointString);
  }


  std::list<std::string> _dictionaireMotLong;
  std::list<std::string> _dictionaireMotPoint;

};


#endif //!ROBOT_HPP
