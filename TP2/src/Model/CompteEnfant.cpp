#include "CompteEnfant.hpp"


CompteEnfant::CompteEnfant(uint64_t id, std::string const &nom, std::string const &prenom, Date &naissance, CompteNormal const &parent)
  : Compte(id, Compte::ENFANT, nom, prenom, naissance), _idParent(parent.getId()) {

}
CompteEnfant::CompteEnfant(std::vector<std::string> &listArg)
  : Compte(std::stoi(listArg[0]), Compte::ENFANT, listArg[2], listArg[3], Date(listArg[4])), _idParent(std::stoi(listArg[5])) {
    setTransaction(listArg);
}

CompteEnfant::~CompteEnfant() {

}

bool CompteEnfant::makeTransaction(Transaction const &transaction) {
  if (isGoodTransaction(transaction)) {
    return addTransaction(transaction);
  }
  return false;
}

bool CompteEnfant::isGoodTransaction(Transaction const &transaction) {
  std::cout << "montant" << transaction.getMontant() << '\n';
  if (transaction.getMontant() > 0)
    return true;
  if (transaction.getMontant() < -10)
    return false;

  float montant = 0;
  Date dateAct;

  for (auto transac : _listTransaction) {
    if (dateAct == transac.getDate())
      return false;
    if (transac.getDate().getYear() == dateAct.getYear()
        && transac.getDate().getMonth() == dateAct.getMonth())
      montant += transac.getMontant();
  }
  if (montant + transaction.getMontant() > 50)
    return false;
  return true;
}

std::string CompteEnfant::toString() {
  return toCsv(_idParent);
}
