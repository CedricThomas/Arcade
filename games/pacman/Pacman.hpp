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
	#include "Ghost.hpp"

//init
	//construct Pacman with map and position
	//construct Ghosts with map and position

	//apply event
		//player change dir with a map (like nibbler)

//update map

	//update player => &map (if not at normal emplacement kill player)
		// try go in dir
		// try to take a pacgum and erase it from map
			// if bonus chrono + status

	//get Score

	//update ghost => &map (if not at normal emplacement kill player)

		// if alive
			// choose a dir with pacman smell or ameliorated rand
			// chase or flee the dir in consequence of pacman consequence
				// => kill pacman if can or die if under bonus
		// else
			// go init pos and wait

	//check player  (if not at normal emplacement kill player)
		//check if dead => getter on alive

//refresh

	//draw map

	//draw player => &pixelbox

	//draw ghosts => &pixelbox


// communication


namespace Arcade {

	enum type_e {
		WALL = 1,
		EMPTY = 2,
		PACGUM = 4,
		GHOST = 8,
		PACMAN = 16,
		BONUS = 32
	};

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

			// refresh size change
			void resizeWin(const Arcade::Vect<size_t> &winsize);

			// refresh => gameStatus

			void drawBoard();

			void drawEntities();

			void drawGameOver();

			Vect<size_t> _boardSize;
			std::vector<std::vector<type_e>> _board;

			// game basics resources
			int _score;
			PixelBox _boardPixelbox;
			TextBox _scoreTextbox;
			Vect<size_t> _winsize;
			std::chrono::high_resolution_clock::time_point _last;
			bool _loose;

			// entities
			std::vector<Ghost> _ghosts;
			Player _pacman;

			static const std::vector<std::vector<int>> _template;
	};
}


#endif //ARCADE_PACMAN_HPP
