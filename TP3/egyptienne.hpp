#ifndef EGYPTIENNE_HPP_
# define EGYPTIENNE_HPP_

# include <string>
# include <list>
# include <stdexcept>


class fraction_egyptienne {
public:
  fraction_egyptienne(double nb)
    : _nb(nb) {
    makeList();
  }

  ~fraction_egyptienne() {
  }

  fraction_egyptienne &operator=(fraction_egyptienne const & tmp) {
    _nb = tmp._nb;
    makeList();
    return *this;
  }

  fraction_egyptienne operator+(fraction_egyptienne const & tmp) {
    double tmpNb = _nb + tmp._nb;
    if (tmpNb < 0) {
      throw std::runtime_error("Error: resultat negatif");
    }
    return fraction_egyptienne(tmpNb);
  }

  fraction_egyptienne operator-(fraction_egyptienne const & tmp) {
    double tmpNb = _nb - tmp._nb;
    if (tmpNb < 0) {
      throw std::runtime_error("Error: resultat negatif");
    }
    return fraction_egyptienne(tmpNb);
  }


  fraction_egyptienne operator*(fraction_egyptienne const & tmp) {
    double tmpNb = _nb * tmp._nb;
    if (tmpNb < 0) {
      throw std::runtime_error("Error: resultat negatif");
    }
    return fraction_egyptienne(tmpNb);
  }

  fraction_egyptienne operator/(fraction_egyptienne const & tmp) {
    if (tmp._nb == 0) {
      throw std::runtime_error("Error: division par zero");
    }

    double tmpNb = _nb / tmp._nb;
    if (tmpNb < 0) {
      throw std::runtime_error("Error: resultat negatif");
    }
    return fraction_egyptienne(tmpNb);
  }

  operator float () const {
    return (float)_nb;
  }

  void makeList() {
    _first = (int)_nb;
    int     divIter = 2;
    double  tmpNb = _nb - _first;

    while (divIter < 10000 && tmpNb > 0) {
      if ((tmpNb - (1.0 / (double)divIter)) > 0) {
        _list.push_back(divIter);
        tmpNb -= (1.0 / (double)divIter);
      }
      ++divIter;
    }
  }

  std::string toString() {
    std::string tmpStr;
    if (_first > 0) {
      tmpStr +=  std::to_string(_first);
    }
    for (auto iter : _list) {
      tmpStr += " + 1 / ";
      tmpStr +=  std::to_string(iter);
    }
    return tmpStr;
  }

private:
  double _nb;

  int _first;
  std::list<int> _list;
};

std::ostream &operator<<(std::ostream &out, fraction_egyptienne tmp) {
  out << tmp.toString();
  return out;
}

#endif //EGIPTIENNE_HPP_
