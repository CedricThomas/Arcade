##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= core

CC	= g++

RM	= rm -f

SRCS	= ./Core.cpp \
	  ./Error.cpp \
	  ./MainParse.cpp \
	  ./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
