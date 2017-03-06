NAME			= bin

FILE			= src/Model/Adresse.cpp \
					src/Model/Personne.cpp \
					src/Model/Date.cpp \
					src/main.cpp \
					src/Menu/MenuPrincipal.cpp \
					src/Menu/MenuPersonnes.cpp \
					src/Menu/input.cpp

OBJ				= $(FILE:.cpp=.o)

CPPFLAGS	+= -std=c++11 -W -Wall -Wextra -g3 -I src/Menu/ -I src/Model/

GCC				= g++

RM				= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $(NAME) $(CPPFLAGS)

fclean:
	$(RM) $(OBJ)
clean: fclean
	$(RM) $(NAME)

re: clean all

.PHONY: fclean clean all re
