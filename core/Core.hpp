/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.hpp
*/

#ifndef ARCADE_CORE_HPP
	#define ARCADE_CORE_HPP

	#include <vector>
	#include <list>
	#include <string>
	#include <memory>
	#include <map>
	#include "DLLoader.hpp"
	#include "Menu.hpp"
	#include "../api/IGameLib.hpp"
	#include "../api/IGraphicLib.hpp"
#include "ScoreManager.hpp"

namespace Arcade {

	class Core {
	public:
		enum Status { // TODO check if xlegit
			MENU = 0,
			GAME = 1,
			EXIT = 2
		};

		Core(const std::string &graph, const std::string &game,
		const std::string &selected);
		virtual ~Core() = default;
		void start();

		void apply_events(Arcade::Keys key);

		//Commons

		void exitArcade();
		void selectNextLib();
		void selectPrevLib();

		void selectNextGame();
		void selectPrevGame();

		void selectGraphByIdx(int idx);
		void selectGameByIdx(int idx);

		// Game
		void resetGame();
		void goBackMenu();

		// Menu
		void openGame();

		//Getters
		const std::vector<std::string> &getLibs() const;
		const std::vector<std::string> &getGames() const;
		const std::vector<std::string> &getGamesPaths() const;
		int getGraphicIdx() const;
		int getGameIdx() const;

		using core_bindings =
		const std::map<Arcade::Keys, void (Arcade::Core::*)()>;

	private:

		void loadGames(const std::string &directory);
		void loadLibs(const std::string &directory);

		void selectGraphByFilename(const std::string &name);

		void updateGame();

		std::unique_ptr<DLLoader<IGraphicLib>> _graph;
		std::unique_ptr<DLLoader<IGameLib>> _game;
		std::vector<std::string> _libsPaths;
		std::vector<std::string> _gamesPaths;
		std::vector<std::string> _libsNames;
		std::vector<std::string> _gamesNames;

		std::string _libsPath;
		std::string _gamesPath;

		int _graphicIdx;
		int _gameIdx;

		Status _status;
		std::string _player;

		Menu _menu;
		bool _gameLoose;
		ScoreManager _scoreManager;

		static const core_bindings _menu_actions;
		static const core_bindings _game_actions;

	};


}

#endif /* !ARCADE_CORE_HPP */
