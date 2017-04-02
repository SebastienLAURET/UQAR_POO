#include <iostream>

#include <cmath> // pour M_PI et M_E
#include "egyptienne.hpp"


int main()
 {
  fraction_egyptienne f(M_PI);
  fraction_egyptienne g(M_E);
  fraction_egyptienne h(1.986728);

  std::cout
   << "f=" << (float)f << " = " << f << std::endl
   << "g=" << (float)g << " = " << g << std::endl
   << "h=" << (float)h << " = " << h << std::endl
   << "f+g=" << f + g << std::endl
   << "f+g=" << (float)(f+g) << std::endl
   << "f-g=" << (fraction_egyptienne)f-g << std::endl
   << "f-g=" << (float)(f-g) << std::endl
   << "f-f=" << (fraction_egyptienne)f-f << std::endl
   << "f-f=" << (float)(f-f) << std::endl
   << "f*g=" << (fraction_egyptienne)f*g << std::endl
   << "f*g=" << (float)(f*g) << std::endl
   << "f/g=" << (fraction_egyptienne)f/g << std::endl
   << "f/g=" << (float)(f/g) << std::endl
   ;


  return 0;
 }
