#ifndef ADRESSE_HPP
# define ADRESSE_HPP

#include <string>


class Adresse {
public:
  Adresse();
  Adresse(std::string &,std::string &,std::string &,std::string &);
  ~Adresse();

  std::string toString();
  const std::string &getNCivique();
  const std::string &getRue();
  const std::string &getVille();
  const std::string &getPays();

private:
  std::string _nCivique;
  std::string _rue;
  std::string _ville;
  std::string _pays;
};

#endif //!ADRESSE_HPP
