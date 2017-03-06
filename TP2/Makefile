NAME			= bin

FILE			= src/Model/CompteEnfant.cpp \
					src/Model/CompteEpargne.cpp \
					src/Model/CompteNormal.cpp \
					src/Model/Compte.cpp \
					src/main.cpp

OBJ				= $(FILE:.cpp=.o)

CPPFLAGS	+= -std=c++11 -W -Wall -Wextra -g3 -I src/Controller/ -I src/Model/

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
