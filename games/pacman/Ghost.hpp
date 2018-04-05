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
		size_t getDeath() const;

	private:
		void changePos(Vect<int> pos);
		void updateDead();
		void updateAlive(Player &pacman);
		void moveAlive(Player &pacman);
		void moveDead();
		void checkDead(Player &pacman);
		bool searchPath(const Arcade::Vect<int> &pos, size_t deep,
		const Arcade::Vect<int> &size);
		bool outOfMap(const Vect<int> &pos, const Vect<int> &size);

		std::vector<Vect<int>> _pathHome;
		std::vector<std::vector<int>> *_board;
		Vect<int> _initPos;
		Vect<int> _dir;
		Vect<int> _pos;
		bool _alive;
		std::chrono::high_resolution_clock::time_point _live;
		size_t _death;
	};

}


#endif /* !ARCADE_GHOST_HPP */
