##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


NAME = lib_arcade_sdl2.so

SRC =	entry.cpp 		\
        SDLGraphicLib.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -I../../api
CXXFLAGS += -W  -Wall -Wextra -fPIC -g

LDFLAGS	= -shared -lSDL2_ttf -lSDL2

all : $(NAME)

$(NAME): $(OBJ)
	g++ $(LDFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all