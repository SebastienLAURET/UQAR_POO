#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <vector>
# include <fstream>
# include "CompteNormal.hpp"
# include "CompteEnfant.hpp"
# include "CompteEpargne.hpp"

class FactoryCSV {
public:
  FactoryCSV(std::string const &filePath)
  : _filePath(filePath) {
    load();
  }
  ~FactoryCSV() {
    save();
  }

  void load() {
    std::string line;
    std::ifstream file;
    file.open(_filePath);

    if (file.is_open()) {
      std::vector<std::string> listArg;

      while (std::getline(file, line)) {
        std::cout << line << '\n';
        listArg = FactoryCSV::split(line, ',');

        switch (listArg[1].at(0)) {
          case Compte::NORMAL:
            _list.push_back(new CompteNormal(listArg));
            break;
          case Compte::EPARGNE:
            _list.push_back(new CompteEpargne(listArg));
            break;
          case Compte::ENFANT:
            _list.push_back(new CompteEnfant(listArg));
            break;
          default:
            std::cerr << "Error input File (Type of Compte)" << std::endl;
            break;
        }
      }
      file.close();
    }
  }

  void save() const {

  }

  std::list<Compte*> &getList(){
    return _list;
  }

  static FactoryCSV &getFactory(std::string const path = std::string("./save/banque.csv")) {
    static FactoryCSV *factory = nullptr;

    if (!factory) {
      factory = new FactoryCSV(path);
    }
    return *factory;
  }

  static std::vector<std::string> split(std::string const &str, char car) {
    std::vector<std::string> list;
    size_t pos, posPrev = 0;

    while ((pos = str.find_first_of(car, posPrev)) != std::string::npos) {
      list.push_back(str.substr(posPrev, pos - posPrev));
      posPrev = pos + 1;
    }
    list.push_back(str.substr(posPrev, str.length()));
    return list;
  }

private:
  std::list<Compte*>          _list;
  std::string                _filePath;
};

#endif //!FACTORY_HPP
