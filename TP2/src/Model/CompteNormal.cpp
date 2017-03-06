#include "CompteNormal.hpp"

CompteNormal::CompteNormal(int id, std::string const &nom, std::string const &prenom,
            Date &naissance)
  : Compte(id, Compte::NORMAL, nom, prenom, naissance) {

}
CompteNormal::CompteNormal(std::vector<std::string> &listArg)
  : Compte(std::stoi(listArg[0]), Compte::NORMAL, listArg[2], listArg[3], Date(listArg[4])) {
    setTransaction(listArg);
}

CompteNormal::~CompteNormal() {

}

bool CompteNormal::makeTransaction(Transaction const &transaction) {
  return addTransaction(transaction);
}

std::string CompteNormal::toString() {
  return toCsv(0);
}
