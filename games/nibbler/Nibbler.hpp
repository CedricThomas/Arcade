/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler
*/

#ifndef ARCADE_NIBBLER_HPP
	#define ARCADE_NIBBLER_HPP

	#include <string>
	#include <vector>

	#include "IGameLib.hpp"
	#include "IGraphicLib.hpp"

enum type_e {
	EMPTY = 0,
	SNAKE = 2,
	APPLE = 4,
	WALL = 8
};

enum connected_e {
	LEFT = 1,
	RIGHT = 2,
	DOWN = 4,
	UP = 8,
};

struct board_s {

	connected_e connections;
	type_e type;
};

using board_t = struct board_s;

namespace Arcade {

	class Nibbler : public IGameLib {
	public:
		bool init() override;
		bool stop() override;
		bool close() override;
		bool open() override;
		void applyEvent(Keys key) override;
		void update() override;
		const std::string getName() const override;
		Nibbler();
		virtual ~Nibbler();
		void refresh(IGraphicLib &graphicLib) override;
	private:
		void recalculate(Vect<size_t> size);
		Vect<size_t> _mapSize;
		std::vector<std::vector<board_t>> _map;
		std::vector<Vect<int>> _snake;
		size_t _level;
		size_t _score;
		PixelBox _pixelbox;
		Vect<size_t> _winsize;
		Vect<int> _dir;
	};
}


#endif //ARCADE_NIBBLER_HPP
