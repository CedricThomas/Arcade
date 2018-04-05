/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.hpp
*/

#ifndef ARCADE_PLAYER_HPP
	#define ARCADE_PLAYER_HPP

	#include <chrono>
	#include "PixelBox.hpp"
	#include "Vect.hpp"
	#include "PacmanCommon.hpp"

namespace Arcade {

	class Player {
	public:
		Player();
		void changeDir(const Vect<int> &dir, std::vector<std::vector<int>> &map);
		void kill();
		void update(std::vector<std::vector<int>> &);
		void draw(PixelBox &pixebox, const Vect<size_t> &size);
		bool isPowered();
		bool isAlive();
		int getAtePacgumns();
	private:
		Vect<int> _dir;
		Vect<int> _posPlayer;
		bool _powered;
		bool _alive;
		std::chrono::high_resolution_clock::time_point _last;
		int _pacGumsEat;
	};

}


#endif /* !ARCADE_PLAYER_HPP */
