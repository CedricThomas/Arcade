//
// EPITECH PROJECT, 2018
// pacmancommon
// File description:
// pacmancommon
//

#ifndef ARCADE_PACMANCOMMON_HPP
	#define ARCADE_PACMANCOMMON_HPP

namespace Arcade {

	enum type_e {
		EMPTY = 0,
		WALL = 2,
		PACGUM = 4,
		GHOST = 8,
		PACMAN = 16,
		BONUS = 32,
		PASS = 64
	};

}
#endif /* ARCADE_PACMANCOMMON_HPP */