##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


NAME = lib_arcade_sdl2.so

SRC =	entry.cpp 		\
        SDLGraphicLib.cpp	\
        PixelBox.cpp		\
        Color.cpp		\
        TextBox.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -Wall -Wextra -fPIC

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