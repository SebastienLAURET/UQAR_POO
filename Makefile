NAME	= bin

FILE	= src/Adresse.cpp \
	src/Personne.cpp \
	src/Menu.cpp \
	src/Date.cpp \
	src/main.cpp

OBJ	= $(FILE:.cpp=.o)

CPPFLAGS	+= -std=c++11 -W -Wall -Wextra -lncurses

GCC	= g++

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $(NAME) $(CPPFLAGS)

fclean:
	$(RM) $(OBJ)
clean: fclean
	$(RM) $(NAME)

re: clean all

.PHONY: fclean clean all re
