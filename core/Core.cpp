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
: _lib(nullptr), _game(nullptr), _libs(), _games(), _graphicIdx(0), _gameIdx(0)
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

void Arcade::Core::play()
{

	auto box1 = PixelBox(Vect<size_t>(200, 200), Vect<size_t>(100,100), Color(0, 255, 0, 255));
	box1.putRect(Vect<size_t>(10, 10), Vect<size_t>(10, 10), Color(0, 0, 255, 255));

	auto box2 = PixelBox(Vect<size_t>(50,50), Vect<size_t>(250, 250), Color(255, 255, 0, 255));

	auto text1 = TextBox("Prout", Vect<size_t >(80, 80));

	for (size_t i = 0; i < _libs.size(); i++) {
//		std::cout << _libs[i] << std::endl;
//		selectGraphByIdx(i);

		_lib->getInstance()->openRenderer();

		_lib->getInstance()->drawPixelBox(box1);
		_lib->getInstance()->drawPixelBox(box2);
		_lib->getInstance()->drawText(text1);

		_lib->getInstance()->refreshWindow();

		getchar();

		_lib->getInstance()->closeRenderer();
	}
}

void Arcade::Core::menu()
{
	std::cout << "menu" << std::endl;
}

void Arcade::Core::selectGraphByIdx(size_t idx)
{
	if (idx > _libs.size())
		throw LoadingError("the selected lib doesn't exist.");
	_graphicIdx = idx;
	_lib = std::make_unique<DLLoader<IGraphicLib>>(_libsPath + _libs[idx]);
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

