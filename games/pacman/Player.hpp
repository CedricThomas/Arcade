/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.hpp
*/

#ifndef ARCADE_PLAYER_HPP
	#define ARCADE_PLAYER_HPP

	#include "PixelBox.hpp"
	#include "Vect.hpp"

namespace Arcade {

	class Player {
	public:
		Player();
		void changeDir(const Vect<int> &dir);
		void Kill();
		void update();
		void draw(const PixelBox &pixebox);
		void isPowered();
		int getEatedPacgumns();
	private:
		Vect<int> _dir;
	};

}


#endif /* !ARCADE_PLAYER_HPP */
