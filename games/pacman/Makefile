##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


NAME = lib_arcade_pacman.so

SRC = entry.cpp \
      	Color.cpp	\
      	PixelBox.cpp	\
      	TextBox.cpp	\
             Pacman.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Wextra -fPIC

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