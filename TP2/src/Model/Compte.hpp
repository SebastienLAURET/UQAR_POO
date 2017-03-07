#ifndef COMPTE_HPP
# define COMPTE_HPP

#include <sstream>
#include <list>
#include <vector>
#include "Transaction.hpp"
#include "Date.hpp"

class Compte {
public:
  enum e_compte {
    NORMAL = 'A',
    ENFANT = 'E',
    EPARGNE = 'R'
  };

  Compte(int id, e_compte type,
    std::string const &nom, std::string const &prenom,
    Date naissance);

    virtual ~Compte() {};
  // GETTER

  int                                 getId() const;
  enum e_compte                       getType() const;
  std::string const                   &getNom() const;
  std::string const                   &getPrenom() const;
  Date const                          &getNaissance() const;
  double                              getSold() const;
  std::list<Transaction> const  &getListTransaction() const;

  // SETTER
  virtual bool makeTransaction(Transaction const &transaction) = 0;
  virtual std::string toString() = 0;

protected:
  bool addTransaction(Transaction const &transaction);
  std::string toCsv(int idParent = 0);
  void  setTransaction(std::vector<std::string> &v);
//protected::
  int const               _id;
  enum e_compte const     _type;
  std::string const       _nom;
  std::string const       _prenom;
  Date const              _naissance;
  double                  _sold;
  std::list<Transaction>  _listTransaction;

};

#endif //!COMPTE_HPP
