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
	#include "Player.hpp"
	#include "PacmanCommon.hpp"
	#include "Ghost.hpp"

namespace Arcade {

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

			// drawers
			using pacman_drawer =
			void (Arcade::Pacman::*)(const Vect<size_t> &,
			const Vect<size_t> &);

			void drawWall(const Vect <size_t> &pos,
			const Vect <size_t> &size);

			void drawBonus(const Vect <size_t> &pos,
				const Vect <size_t> &size);

			void drawPacgum(const Vect <size_t> &pos,
				const Vect <size_t> &size);

		private:
			// init
			void genBoard();
			void initPlayer();
			void initGhosts();
			void nextLevel();

			// refresh size change
			void resizeWin(const Arcade::Vect<size_t> &winsize);

			//update
			void updateGhosts();

			// refresh
			void drawBoard();
			void drawEntities(Vect<size_t>&);
			void drawGameOver();

			Vect<size_t> _boardSize;
			std::vector<std::vector<int>> _board;

			// game basics resources
			int _score;
			PixelBox _boardPixelbox;
			TextBox _scoreTextbox;
			Vect<size_t> _winsize;
			std::chrono::high_resolution_clock::time_point _last;
			bool _loose;
			int _lastScore;

			// entities
			std::vector<Ghost> _ghosts;
			Player _pacman;

			static const std::vector<std::vector<int>> _template;
	};
}


#endif //ARCADE_PACMAN_HPP
