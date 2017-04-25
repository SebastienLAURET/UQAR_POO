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
    std::list<std::string> listGoodWord;

    for (auto it : _dictionaire){
      if (Arbitre::tryWordStatic(word, it) != -1) {
        listGoodWord.push_back(it);
      }
    }
    if (listGoodWord.size()) {
      std::cout << "------------------" << std::endl;
      std::cout << "nb mots trouvé:"<< listGoodWord.size() << std::endl;
      std::cout << "mot + long : ["<< listGoodWord.front() <<"]" << std::endl;
      listGoodWord.sort(comparePointString);
      std::cout << "mot + point : ["<< listGoodWord.front() <<"]" << std::endl;
      std::cout << "------------------" << std::endl;
      return listGoodWord.front();
    }
    return "";
  }

private:
  void loadDictionaire() {
    std::ifstream file("./Asset/Dico.txt");
    std::string str;

    while (std::getline(file, str)) {
      _dictionaire.push_front(str);
    }
    _dictionaire.sort(Robot::compareSizeString);
  }


  std::list<std::string> _dictionaire;
};


#endif //!ROBOT_HPP
