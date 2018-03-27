##
## EPITECH PROJECT, 2018
## cpp_arcade
## File description:
## Makefile
##

NAME	=		arcade


CORE	=		core

CORE_FOLDER	=	core

CORE_DEST_FOLDER =	$(shell pwd)


NCURSES	=		lib_arcade_ncurses.so

NCURSES_FOLDER	=	lib/nCurses

NCURSES_DEST_FOLDER =	lib


SDL	=		lib_arcade_sdl2.so

SDL_FOLDER	=	lib/SDL2

SDL_DEST_FOLDER =	lib


SFML	=		lib_arcade_sfml.so

SFML_FOLDER	=	lib/SFML

SFML_DEST_FOLDER =	lib



GAME1	=		lib_arcade_pacman.so

GAME1_FOLDER	=	games/pacman

GAME1_DEST_FOLDER =	games


GAME2	=		lib_arcade_nibbler.so

GAME2_FOLDER	=	games/nibbler

GAME2_DEST_FOLDER =	games


all: $(NAME)

games: $(GAME1) $(GAME2)

graphicals: $(SFML) $(SDL) $(NCURSES)

$(NAME): $(CORE) $(SFML) $(SDL) $(NCURSES) $(GAME1) $(GAME2)

clean: clean_core clean_sfml clean_ncurses clean_sdl clean_game1 clean_game2

fclean: fclean_core fclean_sfml fclean_ncurses fclean_sdl fclean_game1 fclean_game2

re: fclean all

.PHONY: clean fclean re all





$(CORE):
	make -C $(CORE_FOLDER)
	cp $(CORE_FOLDER)/$(CORE) $(CORE_DEST_FOLDER)/$(NAME)

clean_core:
	make -C $(CORE_FOLDER) clean

fclean_core:
	make -C $(CORE_FOLDER) fclean
	rm -f $(CORE_DEST_FOLDER)/$(NAME)

re_core: fclean_core $(CORE)


.PHONY: clean_core fclean_core re_core core



$(SFML):
	make -C $(SFML_FOLDER)
	cp $(SFML_FOLDER)/$(SFML) $(SFML_DEST_FOLDER)

clean_sfml:
	make -C $(SFML_FOLDER) clean

fclean_sfml:
	make -C $(SFML_FOLDER) fclean
	rm -f $(SFML_DEST_FOLDER)/$(SFML)

re_sfml: fclean_sfml $(SFML)

.PHONY: clean_sfml fclean_sfml re_sfml



$(NCURSES):
	make -C $(NCURSES_FOLDER)
	cp $(NCURSES_FOLDER)/$(NCURSES) $(NCURSES_DEST_FOLDER)

clean_ncurses:
	make -C $(NCURSES_FOLDER) clean

fclean_ncurses:
	make -C $(NCURSES_FOLDER) fclean
	rm -f $(NCURSES_DEST_FOLDER)/$(NCURSES)

re_ncurses: fclean_ncurses $(NCURSES)

.PHONY: clean_ncurses fclean_ncurses re_ncurses



$(SDL):
	make -C $(SDL_FOLDER)
	cp $(SDL_FOLDER)/$(SDL) $(SDL_DEST_FOLDER)

clean_sdl:
	make -C $(SDL_FOLDER) clean

fclean_sdl:
	make -C $(SDL_FOLDER) fclean
	rm -f $(SDL_DEST_FOLDER)/$(SDL)

re_sdl: fclean_sdl $(SDL)

.PHONY: clean_sdl fclean_sdl re_sdl




$(GAME1):
	make -C $(GAME1_FOLDER)
	cp $(GAME1_FOLDER)/$(GAME1) $(GAME1_DEST_FOLDER)

clean_game1:
	make -C $(GAME1_FOLDER) clean

fclean_game1:
	make -C $(GAME1_FOLDER) fclean
	rm -f $(GAME1_DEST_FOLDER)/$(GAME1)

re_game1: fclean_game1 $(GAME1)

.PHONY: clean_game1 fclean_game1 re_game1



$(GAME2):
	make -C $(GAME2_FOLDER)
	cp $(GAME2_FOLDER)/$(GAME2) $(GAME2_DEST_FOLDER)

clean_game2:
	make -C $(GAME2_FOLDER) clean

fclean_game2:
	make -C $(GAME2_FOLDER) fclean
	rm -f $(GAME2_DEST_FOLDER)/$(GAME2)

re_game2: fclean_game2 $(GAME2)

.PHONY: clean_game2 fclean_game2 re_game2
