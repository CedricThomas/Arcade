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
		Core(const std::string &graph, const std::string &game,
		const std::string &selected);
		virtual ~Core() = default;
		void play(); // play loop (=> game/menu getionnary)
		void menu(); // menu subloop
	private:
		void loadGames(const std::string &directory);
		void loadLibs(const std::string &directory);

		void selectGraphByFilename(const std::string &name);
		void selectGraphByIdx(size_t idx);

		std::unique_ptr<DLLoader<IGraphicLib>> _lib;
		std::unique_ptr<DLLoader<IGameLib>> _game;

		std::vector<std::string> _libs;
		std::vector<std::string> _games;

		size_t _graphic_idx;
		size_t _game_idx;
	};

}


#endif /* !ARCADE_CORE_HPP */
