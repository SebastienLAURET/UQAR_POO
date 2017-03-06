#ifndef COMPTEENFANT_HPP
#define COMPTEENFANT_HPP

#include "Compte.hpp"
#include "CompteNormal.hpp"
#include <vector>

class CompteEnfant : public Compte {
public:
  CompteEnfant(uint64_t id, std::string const &nom, std::string const &prenom,
              Date &naissance, CompteNormal const &parent);
  CompteEnfant(std::vector<std::string> &listArg);
  ~CompteEnfant();
  bool makeTransaction(Transaction const &transaction);
  std::string toString();

private:
  bool isGoodTransaction(Transaction const &transaction);

  int const _idParent;
};

#endif //!COMPTENOMRAL_HPP
