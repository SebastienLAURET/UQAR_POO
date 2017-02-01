#include <curses.h>
#include <term.h>
#include "Menu.hpp"

int main(/*int argc, char const *argv[]*/) {
  tgetent(NULL, NULL);
  Menu menu;

  menu();

  return 0;
}
