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

NCURSES_FOLDER	=	lib/lib_nCurses

NCURSES_DEST_FOLDER =	lib


SDL	=		lib_arcade_sdl2.so

SDL_FOLDER	=	lib/lib_SDL2

SDL_DEST_FOLDER =	lib


SFML	=		lib_arcade_sfml.so

SFML_FOLDER	=	lib/lib_SFML

SFML_DEST_FOLDER =	lib



PACMAN	=		lib_arcade_pacman.so

PACMAN_FOLDER	=	games/pacman

PACMAN_DEST_FOLDER =	games


NIBBLER	=		lib_arcade_nibbler.so

NIBBLER_FOLDER	=	games/nibbler

NIBBLER_DEST_FOLDER =	games


all: $(NAME)

games: $(PACMAN) $(NIBBLER)

graphicals: $(SFML) $(SDL) $(NCURSES)

$(NAME): $(CORE) $(SDL) $(NCURSES) $(PACMAN) $(NIBBLER)  $(SFML)

clean: clean_core clean_sfml clean_ncurses clean_sdl clean_pacman clean_nibbler

fclean: fclean_core fclean_sfml fclean_ncurses fclean_sdl fclean_pacman fclean_nibbler

re: fclean all

.PHONY: clean fclean re all



$(CORE):
	make -sC $(CORE_FOLDER)
	cp $(CORE_FOLDER)/$(CORE) $(CORE_DEST_FOLDER)/$(NAME)

clean_core:
	make -sC $(CORE_FOLDER) clean

fclean_core:
	make -sC $(CORE_FOLDER) fclean
	rm -f $(CORE_DEST_FOLDER)/$(NAME)

re_core: fclean_core $(CORE)


.PHONY: clean_core fclean_core re_core core



$(SFML):
	make -sC $(SFML_FOLDER)
	cp $(SFML_FOLDER)/$(SFML) $(SFML_DEST_FOLDER)

clean_sfml:
	make -sC $(SFML_FOLDER) clean

fclean_sfml:
	make -sC $(SFML_FOLDER) fclean
	rm -f $(SFML_DEST_FOLDER)/$(SFML)

re_sfml: fclean_sfml $(SFML)

.PHONY: clean_sfml fclean_sfml re_sfml



$(NCURSES):
	make -sC $(NCURSES_FOLDER)
	cp $(NCURSES_FOLDER)/$(NCURSES) $(NCURSES_DEST_FOLDER)

clean_ncurses:
	make -sC $(NCURSES_FOLDER) clean

fclean_ncurses:
	make -sC $(NCURSES_FOLDER) fclean
	rm -f $(NCURSES_DEST_FOLDER)/$(NCURSES)

re_ncurses: fclean_ncurses $(NCURSES)

.PHONY: clean_ncurses fclean_ncurses re_ncurses



$(SDL):
	make -sC $(SDL_FOLDER)
	cp $(SDL_FOLDER)/$(SDL) $(SDL_DEST_FOLDER)

clean_sdl:
	make -sC $(SDL_FOLDER) clean

fclean_sdl:
	make -sC $(SDL_FOLDER) fclean
	rm -f $(SDL_DEST_FOLDER)/$(SDL)

re_sdl: fclean_sdl $(SDL)

.PHONY: clean_sdl fclean_sdl re_sdl




$(PACMAN):
	make -sC $(PACMAN_FOLDER)
	cp $(PACMAN_FOLDER)/$(PACMAN) $(PACMAN_DEST_FOLDER)

clean_pacman:
	make -sC $(PACMAN_FOLDER) clean

fclean_pacman:
	make -sC $(PACMAN_FOLDER) fclean
	rm -f $(PACMAN_DEST_FOLDER)/$(PACMAN)

re_pacman: fclean_pacman $(PACMAN)

.PHONY: clean_pacman fclean_pacman re_pacman



$(NIBBLER):
	make -sC $(NIBBLER_FOLDER)
	cp $(NIBBLER_FOLDER)/$(NIBBLER) $(NIBBLER_DEST_FOLDER)

clean_nibbler:
	make -sC $(NIBBLER_FOLDER) clean

fclean_nibbler:
	make -sC $(NIBBLER_FOLDER) fclean
	rm -f $(NIBBLER_DEST_FOLDER)/$(NIBBLER)

re_nibbler: fclean_nibbler $(NIBBLER)

.PHONY: clean_nibbler fclean_nibbler re_nibbler
