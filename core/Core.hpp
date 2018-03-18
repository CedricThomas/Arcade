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
	#include "DLLoader.hpp"

namespace Arcade {

	class Core {
	public:
		Core(const std::string &selectedLib);
		void loadGames(const std::string &directory);
		void loadLibs(const std::string &directory);
		void play(); // play loop (=> game/menu getionnary)
		void menu(); // menu subloop
	private:
		std::vector<void *> libs;
		std::vector<void *> games;
		size_t idxLib;
		size_t idxGame;
		const static std::string gamesDirectory;
		const static std::string libsDirectory;
	};

}


#endif /* !ARCADE_CORE_HPP */
