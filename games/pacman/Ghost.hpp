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
	public:
		Ghost(const Vect<int> &_initPos,
		std::vector<std::vector<int>> *board);

		void update(Player &pacman);
		void draw(PixelBox &pixebox, const Vect<size_t> &size,
		Player &pacman);
		void init();

	private:
		void updateDead();
		void updateAlive(Player &pacman);
		void moveAlive();
		void moveDead();
		void checkDead(Player &pacman);

		std::vector<std::vector<int>> *_board;
		Vect<int> _initPos;
		Vect<int> _dir;
		Vect<int> _pos;
		bool _alive;
		std::chrono::high_resolution_clock::time_point _live;

	};

}


#endif /* !ARCADE_GHOST_HPP */
