##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= core

CC	= g++

RM	= rm -f

SRCS	= ./Core.cpp		\
	  ./Menu.cpp		\
	  ./SyntaxAnalyser.cpp	\
	  ./ScoreManager.cpp	\
	  ./Errors.cpp		\
	  ./main.cpp      	\
	  ../api/Color.cpp  	\
	  ../api/PixelBox.cpp  \
	  ../api/TextBox.cpp

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS += -W -Wall -Wextra

LDFLAGS = -ldl -rdynamic

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
