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
: _lib(nullptr),
  _game(nullptr),
  _libs(),
  _games(),
  _graphicIdx(0),
  _gameIdx(0),
  _status(MENU),
  _player()
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
	_gamesPath = directory;
	while (entry) {
		if ((entry->d_type & DT_REG) == DT_REG) {
			auto f = std::string(entry->d_name);
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
	_libsPath = directory;
	while (entry) {
		if ((entry->d_type & DT_REG) == DT_REG) {
			auto f = std::string(entry->d_name);
			_libs.push_back(f);
		}
		entry = readdir(dir);
	}
	closedir(dir);
}

void Arcade::Core::start()
{
	_lib->getInstance()->openRenderer();
	while (_status != EXIT) {
		if (_status == MENU) {
			std::cout << "menu" << std::endl;
		} else {
			std::cout << "game" << std::endl;
		}
	}
	_lib->getInstance()->closeRenderer();
}

void Arcade::Core::selectGraphByIdx(size_t idx, bool open)
{
	if (idx > _libs.size())
		throw LoadingError("the selected lib doesn't exist.");
	if (open)
		_lib->getInstance()->closeRenderer();
	_graphicIdx = idx;
	_lib = std::make_unique<DLLoader<IGraphicLib>>(_libsPath + _libs[idx]);
	if (open)
		_lib->getInstance()->openRenderer();
}

void Arcade::Core::selectGraphByFilename(const std::string &name)
{
	bool found = false;

	for (size_t i = 0; i < _libs.size(); i++) {
		if (name == _libs[i]) {
			selectGraphByIdx(i, false);
			found = true;
			break;
		}
	}
	if (!found)
		throw LoadingError("the selected lib doesn't exist.");
}

const std::vector<std::string> &Arcade::Core::getLibs() const
{
	return _libs;
}

const std::vector<std::string> &Arcade::Core::getGames() const
{
	return _games;
}

size_t Arcade::Core::getGraphicIdx() const
{
	return _graphicIdx;
}

size_t Arcade::Core::getGameIdx() const
{
	return _gameIdx;
}

