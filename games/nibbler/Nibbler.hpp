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
	SELF = 0,
	LEFT = 2,
	RIGHT = 4,
	DOWN = 8,
	UP = 16,
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
		// gen methods
		void genWalls();
		void genApple();

		// refresh methods
		void resizePixelbox(Vect<size_t> size);
		void drawDrawWalls();
		void drawSnake();

		// utils methods
		bool moveSnake(bool append = false);

		Vect<size_t> _mapSize;
		std::vector<std::vector<board_t>> _map;
		std::vector<Vect<int>> _snake;
		size_t _level;
		size_t _score;
		PixelBox _background;
		Vect<size_t> _winsize;
		Vect<int> _dir;
	};
}


#endif //ARCADE_NIBBLER_HPP
