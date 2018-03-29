/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <iostream>
#include <dirent.h>
#include <fstream>
#include "Core.hpp"

Arcade::Core::Core(const std::string &graph, const std::string &game,
const std::string &selected)
: _lib(nullptr), _game(nullptr), _libs(), _games(), _graphic_idx(0), _game_idx(0)
{
	loadLibs(graph);
	loadGames(game);
	selectGraphByFilename(selected);
}

void Arcade::Core::loadGames(const std::string &directory)
{
	auto dir = opendir(directory.c_str());
	if (dir == nullptr)
		throw LoadingError("Can't open games path " + directory);
	auto entry = readdir(dir);
	while (entry) {
		if ((entry->d_type & DT_REG) == DT_REG) {
			auto f = directory +  entry->d_name;
			_games.push_back(f);
		}
		entry = readdir(dir);
	}
	closedir(dir);
}

void Arcade::Core::loadLibs(const std::string &directory)
{
	auto dir = opendir(directory.c_str());
	if (dir == nullptr)
		throw LoadingError("Can't open libs path " + directory);
	auto entry = readdir(dir);
	while (entry) {
		if ((entry->d_type & DT_REG) == DT_REG) {
			auto f = directory +  entry->d_name;
			_libs.push_back(f);
		}
		entry = readdir(dir);
	}
	closedir(dir);
}

void Arcade::Core::play()
{
	std::cout << "play" << std::endl;
	//std::cout <<
	_lib->getInstance()->openRenderer();// << std::endl;
	while (1);
}

void Arcade::Core::menu()
{
	std::cout << "menu" << std::endl;
}

void Arcade::Core::selectGraphByIdx(size_t idx)
{
	if (idx > _libs.size())
		throw LoadingError("the selected lib doesn't exist.");
	_graphic_idx = idx;
	_lib = std::make_unique<DLLoader<IGraphicLib>>(_libs[idx]);
}

void Arcade::Core::selectGraphByFilename(const std::string &name)
{
	bool found = false;

	for (size_t i = 0; i < _libs.size(); i++) {
		if (name == _libs[i]) {
			selectGraphByIdx(i);
			found = true;
			break;
		}
	}
	if (!found)
		throw LoadingError("the selected lib doesn't exist.");
}

