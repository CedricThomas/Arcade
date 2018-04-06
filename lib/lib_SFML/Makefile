##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


NAME = lib_arcade_sfml.so

SRC =	entry.cpp 		\
        SFMLGraphicLib.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -I../../api
CXXFLAGS += -W -Wall -Wextra -fPIC

LDFLAGS	= -shared -lsfml-graphics -lsfml-window -lsfml-system

all : $(NAME)

$(NAME): $(OBJ)
	g++ $(LDFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all