/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Ghost.hpp
*/

#ifndef ARCADE_GHOST_HPP
	#define ARCADE_GHOST_HPP

	#include <vector>
	#include "Vect.hpp"
	#include "PixelBox.hpp"
	#include "Player.hpp"

namespace Arcade {

	class Ghost {
		void init();

		public:
		Ghost(const Vect<int> &_initPos, std::vector<std::vector<int>> &board);
		void changeDir(const Vect<int> &dir);
		void kill();
		void update(Player &pacman);
		void draw(PixelBox &pixebox, const Vect<size_t> &size);

		private:
		Vect<int> _initPos;
		Vect<int> _dir;
		Vect<int> _pos;
		std::chrono::high_resolution_clock::time_point _last;
		std::vector<std::vector<int>> _board;

	};

}


#endif /* !ARCADE_GHOST_HPP */
