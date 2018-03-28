##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


NAME = lib_arcade_sfml.so

SRC = entryPoint.cpp \
        SFML.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Wextra -fPIC
CXXFLAGS += -I../../include/

LDFLAGS	= -shared


all : $(NAME)

$(NAME): $(OBJ)
	g++ $(LDFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all