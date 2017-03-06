#include "CompteEpargne.hpp"

CompteEpargne::CompteEpargne(uint64_t id, std::string const &nom, std::string const &prenom, Date naissance)
  : Compte(id, Compte::EPARGNE, nom, prenom, naissance) {
}
CompteEpargne::CompteEpargne(std::vector<std::string> &listArg)
  : Compte(std::stoi(listArg[0]), Compte::EPARGNE, listArg[2], listArg[3], Date(listArg[4])) {
    setTransaction(listArg);
}

CompteEpargne::~CompteEpargne() {

}


bool CompteEpargne::makeTransaction(Transaction const &transaction) {
  if (Autorisation::getAutorisation()) {
    return addTransaction(transaction);
  }
  return false;
}

std::string CompteEpargne::toString() {
  return toCsv(0);
}
