#ifndef PERSONNES_HPP
#define PERSONNES_HPP

#include "Personne.hpp"

struct Personnes {
  Personne *pers;
  Personnes *root;
  Personnes *next;
  Personnes *prev;

  size_t    size;

  Personnes () {
    init();
  }

  Personnes (Personne *newPers) {
    init();
    pers = newPers;
  }

  void init() {
    size = 0;
    pers = NULL;
    root = this;
    next = this;
    prev = this;
  }

  void push_front(Personne *newPers) {
    ++size;
    Personnes *newElem = new Personnes(newPers);
    newElem->root = root;

    std::cout << (uint64_t) root<< std::endl;
    newElem->next = this->root->next;
    newElem->prev = this->root;
    newElem->next->prev = newElem;
    newElem->prev->next = newElem;

    std::cout << root->next->pers->_prenom << '\n';
  }

  void push_back(Personne *newPers) {
    ++size;

    Personnes *newElem = new Personnes(newPers);
    newElem->root = root;

    newElem->next = root;
    newElem->prev = root->prev;
    newElem->next->prev = newElem;
    newElem->prev->next = newElem;
  }

  Personne *pop_back() {
    --size;
    Personne *tmp = root->prev->pers;
    Personnes *tmpElem = root->prev;

    tmpElem->prev->next = root;
    root->prev = tmpElem->prev;

    delete tmpElem;
    return tmp;
  }

  Personne *pop_front() {
    --size;
    Personne *tmp = root->next->pers;
    Personnes *tmpElem = root->next;

    tmpElem->next->prev = root;
    root->next = tmpElem->next;

    delete tmpElem;
    return tmp;
  }
  Personnes *clear() {
    Personnes *iter = root->next;
    while (iter->root != iter) {
      iter = iter->erase();
      iter = iter->next;
    }
    return iter;
  }

  Personnes *erase() {
    if (root == this) {
      std::cout << "error" << std::endl;
      return NULL;
    }
    Personnes *tmp = prev;
    next->prev = tmp;
    tmp->next = next;

    prev = NULL;
    next = NULL;
    delete this;
    return tmp;
  }

  void remove(Personne *it) {
    if (root == this) {
      std::cout << "error" << std::endl;
    }
    Personnes *iter = root->next;
    while (iter->root != iter) {
      if (iter->pers == it) {
        iter->erase();
        return;
      }
    }
  }


  size_t length() {
    size_t i = 0;
    Personnes *iter = root->next;
    while (iter->root != iter) {
      iter = iter->next;
      i++;
    }
    return i;
  }

  Personnes *at(size_t index) {
    Personnes *iter = root->next;
    while (iter->root != iter) {
      if (index == 0)
        return iter;
      iter = iter->next;
      index--;
    }
    return NULL;
  }
/*
  Personnes  *find(Personne *pers) {
    Personnes *iter = root->next;
    while (iter->pers != NULL) {
      iter = iter->next;
    }
  }
*/
  Personnes  *findByNom(std::string &tmp) {
    Personnes *list = new Personnes();
    Personnes *iter = root->next;

    while (iter->root != iter) {
      std::cout << "nom :: " << iter->pers->_nom << "==" << tmp << std::endl;
      if (iter->pers->_nom == tmp) {
        list->push_back(iter->pers);
      }
      iter = iter->next;
    }
    return list;
  }

  Personnes  *findByPrenom(std::string &tmp) {
    Personnes *list = new Personnes();
    Personnes *iter = root->next;

    while (iter->root != iter) {
      if (iter->pers->_prenom == tmp) {
        list->push_front(iter->pers);
        std::cout << "prenom :: " << iter->pers->_prenom << "==" << tmp << "  "<< list->length()<<'\n';
      }
      iter = iter->next;
    }
    return list;
  }

  Personnes *findByDate(Date tmp) {
    Personnes *list = new Personnes();
    Personnes *iter = root->next;
    while (iter->pers != NULL) {
      std::cout << "nom :: " << iter->pers->_dateNaissance.toString() << "==" << tmp.toString() << std::endl;
      if (iter->pers->_dateNaissance == tmp) {
        list->push_front(iter->pers);
      }
      iter = iter->next;
    }
    return list;
  }
};

#endif //!PERSONNES_HPP
