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
		size_t getDeathCounter() const;

		//track pacman
		void setupPacmanTrack();
		void resetPacmanTrack();

	private:
		// utils fcts
		void changePos(Vect<int> pos);
		bool checkPos(Vect<int> pos, int mask);
		bool outOfMap(const Vect<int> &pos, const Vect<int> &size);

		// update fcts
		void checkDead(Player &pacman);
		void updateDead();
		void updateAlive(Player &pacman);

		// move fct
		void moveAlive(Player &pacman);
		void moveDead();
		void moveRand();


		// pathfinding fcts

		bool searchHome(const Arcade::Vect<int> &pos, size_t deep,
		const Arcade::Vect<int> &size);

		bool searchPacman(const Arcade::Vect<int> &pos, size_t deep,
		const Arcade::Vect<int> &size);


		std::vector<Vect<int>> _pathHome;
		std::vector<Vect<int>> _pathPacman;
		std::vector<std::vector<int>> *_board;
		Vect<int> _initPos;
		Vect<int> _dir;
		Vect<int> _pos;
		bool _alive;
		std::chrono::high_resolution_clock::time_point _live;
		size_t _death;
		size_t _turn;
	};

}


#endif /* !ARCADE_GHOST_HPP */
