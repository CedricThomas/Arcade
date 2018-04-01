/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.hpp
*/

#ifndef ARCADE_CORE_HPP
	#define ARCADE_CORE_HPP

	#include <vector>
	#include <string>
	#include <memory>
	#include "DLLoader.hpp"
	#include "../api/IGameLib.hpp"
	#include "../api/IGraphicLib.hpp"

namespace Arcade {

	class Core {
	public:
		enum Status { // TODO check if xlegit
			MENU,
			GAME,
			EXIT
		};

		Core(const std::string &graph, const std::string &game,
		const std::string &selected);
		virtual ~Core() = default;
		void start();


		//Selectors

		void selectNextLib();
		void selectPrevLib();

		void selectNextGame();
		void selectPrevGame();


		//Getters
		const std::vector<std::string> &getLibs() const;
		const std::vector<std::string> &getGames() const;
		size_t getGraphicIdx() const;
		size_t getGameIdx() const;

	private:

		void loadGames(const std::string &directory);
		void loadLibs(const std::string &directory);

		void selectGraphByFilename(const std::string &name);
		void selectGraphByIdx(size_t idx, bool open = true);

		std::unique_ptr<DLLoader<IGraphicLib>> _lib;
		std::unique_ptr<DLLoader<IGameLib>> _game;

		std::vector<std::string> _libs;
		std::vector<std::string> _games;

		std::string _libsPath;
		std::string _gamesPath;

		size_t _graphicIdx;
		size_t _gameIdx;

		Status _status;
		std::string _player;


	};

}


#endif /* !ARCADE_CORE_HPP */
