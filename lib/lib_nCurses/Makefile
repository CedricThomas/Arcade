##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


NAME = lib_arcade_ncurses.so

SRC =	entry.cpp				\
	NCursesGraphicLib.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -I../../api
CXXFLAGS += -W -Wall -Wextra -fPIC

LDFLAGS	= -shared -lm -lncurses

all : $(NAME)

$(NAME): $(OBJ)
	g++ $(LDFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all