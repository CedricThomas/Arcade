/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Pacman
*/

#ifndef ARCADE_PACMAN_HPP
	#define ARCADE_PACMAN_HPP

	#include <chrono>
	#include "IGameLib.hpp"
	#include "IGraphicLib.hpp"

namespace Arcade {

	enum type_e {
		WALL = 0,
		EMPTY = 1,
		GHOST = 2,
		PACGUMS = 3,
		PACMAN = 5
	};

	struct board_s {
		int connect;
		type_e type;
	};

	using board_t = struct board_s;
	class Pacman : public IGameLib{
		public:
		const std::string getName() const override;

		bool init() override;

		bool stop() override;

		bool applyEvent(Keys key) override;

		bool update() override;

		void refresh(IGraphicLib &graphicLib) override;

		size_t getScore() override;

		Pacman();

		virtual ~Pacman();

		private:
		void genMaps();
		void drawGameOver();
		void resizePixelbox(const Arcade::Vect<size_t> &winsize);
		void drawMaps();
		Vect<size_t> _mapSize;
		std::vector<std::vector<type_e>> _map;
		std::vector<Vect<int>> _pacman;
		std::vector<std::vector<Vect<int>>> _ghost;

		size_t _level;
		int _score;
		PixelBox _background;
		TextBox _scoreBox;
		Vect<size_t> _winsize;
		Vect<int> _dir;
		std::chrono::high_resolution_clock::time_point _last;
		bool _loose;

		static const std::vector<std::vector<int>> _template;

	};
}


#endif //ARCADE_PACMAN_HPP
