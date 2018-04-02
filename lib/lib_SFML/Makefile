##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


NAME = lib_arcade_sfml.so

SRC =	entry.cpp 		\
        SFMLGraphicLib.cpp	\
        PixelBox.cpp		\
        Color.cpp		\
        TextBox.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -W -Wall -Wextra -fPIC -g

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