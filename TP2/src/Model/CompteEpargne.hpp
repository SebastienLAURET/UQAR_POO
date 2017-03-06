#ifndef COMPTEEPARGNE_HPP
#define COMPTEEPARGNE_HPP

#include "Compte.hpp"
#include "Autorisation.hpp"
#include <vector>

class CompteEpargne : public Compte {
public:
  CompteEpargne(uint64_t id, std::string const &nom, std::string const &prenom, Date naissance);
  CompteEpargne(std::vector<std::string> &listArg);

  ~CompteEpargne();

  bool makeTransaction(Transaction const &transaction);
  std::string toString();
};

#endif //!COMPTENOMRAL_HPP
