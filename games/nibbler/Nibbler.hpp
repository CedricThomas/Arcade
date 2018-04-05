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
#include <chrono>

#include "IGameLib.hpp"
	#include "IGraphicLib.hpp"

namespace Arcade {

	enum type_e {
		EMPTY = 0,
		SNAKE = 2,
		APPLE = 4,
		WALL = 8
	};

	struct board_s {
		int connect;
		type_e type;
	};

	using board_t = struct board_s;

	class Nibbler : public IGameLib {
	public:
		bool init() override;
		bool stop() override;
		bool applyEvent(Keys key) override;
		bool update() override;
		const std::string getName() const override;
		Nibbler();
		virtual ~Nibbler();
		void refresh(IGraphicLib &graphicLib) override;
		size_t getScore() override;
	private:
		// gen methods
		void genWalls();
		void genApple();

		// refresh methods
		void resizePixelbox(const Vect<size_t> &size);
		void drawDrawWalls();
		void drawGameOver();
		void drawSnake();
		void drawSnakeHead(const Vect<size_t> &realPos);
		void drawLeftEye(const Arcade::Vect<size_t> &rPos,
		const Vect<size_t> &lSize);
		void drawRightEye(const Arcade::Vect<size_t> &rPos,
		const Vect<size_t> &lSize);
		void drawSnakeElem(const Vect<size_t> &realpos);

		// utils methods
		bool moveSnake(bool append = false);

		Vect<size_t> _mapSize;
		std::vector<std::vector<type_e>> _map;
		std::vector<Vect<int>> _snake;
		int _score;
		PixelBox _background;
		TextBox _scoreBox;
		Vect<size_t> _winsize;
		Vect<int> _dir;
		std::chrono::high_resolution_clock::time_point _last;
		bool _loose;

		static const std::vector<std::string> _template;
	};
}


#endif //ARCADE_NIBBLER_HPP
