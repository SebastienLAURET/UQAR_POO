#ifndef COMPTENOMRAL_HPP
#define COMPTENOMRAL_HPP

#include "Compte.hpp"
#include <vector>

class CompteNormal : public Compte {
public:
  CompteNormal(int id, std::string const &nom, std::string const &prenom,
              Date &naissance);
  CompteNormal(std::vector<std::string> &listArg);
  ~CompteNormal();

  bool makeTransaction(Transaction const &transaction);
  std::string toString();
};

#endif //!COMPTENOMRAL_HPP
