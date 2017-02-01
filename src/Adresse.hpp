#ifndef ADRESSE_HPP
# define ADRESSE_HPP

#include <string>
#include <cstring>

typedef struct  s_adresse {
  char          nCivique[20];
  char          rue[50];
  char          ville[20];
  char          pays[20];
}               t_adresse;

class Adresse {
public:
  Adresse();
  Adresse(std::string &,std::string &,std::string &,std::string &);
  ~Adresse();

  void        toStruct(t_adresse &addr);
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
