/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <iostream>
#include <dirent.h>
#include <fstream>
#include <functional>
#include "Core.hpp"


//TODO ncurses -> sdl -> ncurses resize = segv

const Arcade::Core::core_bindings Arcade::Core::_menu_actions = {
	{Arcade::Keys::RIGHT, &Arcade::Core::selectNextLib},
	{Arcade::Keys::LEFT, &Arcade::Core::selectPrevLib},
	{Arcade::Keys::ESC, &Arcade::Core::exitArcade},
	{Arcade::Keys::ENTER, &Arcade::Core::openGame}
};

const Arcade::Core::core_bindings Arcade::Core::_game_actions = {
	{Arcade::Keys::RIGHT, &Arcade::Core::selectNextLib},
	{Arcade::Keys::LEFT, &Arcade::Core::selectPrevLib},
	{Arcade::Keys::ESC, &Arcade::Core::exitArcade},
	{Arcade::Keys::BACKSPACE, &Arcade::Core::goBackMenu},
	{Arcade::Keys::DOWN, &Arcade::Core::selectNextGame},
	{Arcade::Keys::UP, &Arcade::Core::selectPrevGame},
	{Arcade::Keys::ENTER, &Arcade::Core::resetGame}
};

Arcade::Core::Core(const std::string &graph, const std::string &game,
const std::string &selected)
: _lib(nullptr),
  _game(nullptr),
  _libs(),
  _games(),
  _graphicIdx(0),
  _gameIdx(0),
  _status(MENU),
  _player(),
  _menu()
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
	_lib->getInstance()->openRenderer("Arcade");
	while (_status != EXIT) {
		Arcade::Keys key;
		_lib->getInstance()->pollEvents();
		do {
			key = _lib->getInstance()->getLastEvent();
			apply_events(key);
		} while (key != NONE);
		_lib->getInstance()->clearWindow();
		if (_status == MENU)
			_menu.refresh(*_lib->getInstance(), *this);
		else
			_game->getInstance()->refresh(*_lib->getInstance());
		_lib->getInstance()->refreshWindow();
	}
	_lib->getInstance()->closeRenderer();
}

void Arcade::Core::selectGraphByIdx(int idx)
{
	if (static_cast<size_t>(idx) > _libs.size() || idx < 0)
		throw LoadingError("the selected lib doesn't exist.");
	_graphicIdx = idx;
	_lib = std::make_unique<DLLoader<IGraphicLib>>(_libsPath + _libs[idx]);
}

void Arcade::Core::selectGameByIdx(int idx)
{
	if (static_cast<size_t>(idx) > _games.size() || idx < 0)
		throw LoadingError("the selected lib doesn't exist.");
	if (_game)
		_game->getInstance()->stop();
	_gameIdx = idx;
	_game = std::make_unique<DLLoader<IGameLib>>(_gamesPath + _games[idx]);
	_game->getInstance()->init();
}

void Arcade::Core::selectGraphByFilename(const std::string &name)
{
	bool found = false;

	for (size_t i = 0; i < _libs.size(); i++) {
		if (name == _libs[i]) {
			selectGraphByIdx(static_cast<int>(i));
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

int Arcade::Core::getGraphicIdx() const
{
	return _graphicIdx;
}

int Arcade::Core::getGameIdx() const
{
	return _gameIdx;
}

void Arcade::Core::exitArcade()
{
	_status = EXIT;
}

void Arcade::Core::openGame()
{
	auto idx = static_cast<int>(_menu.getGameIdx());
	if (_game == nullptr || _gameIdx != idx)
		selectGameByIdx(idx);
	_status = GAME;
	_game->getInstance()->open();
}

void Arcade::Core::goBackMenu()
{
	_game->getInstance()->close();
	_status = MENU;
}

void Arcade::Core::resetGame()
{
	_game->getInstance()->init();
}

void Arcade::Core::selectNextGame()
{
	selectGameByIdx((_gameIdx + 1) % static_cast<int>(_games.size()));
	_game->getInstance()->open();
}

void Arcade::Core::selectPrevGame()
{
	auto idx = (_gameIdx - 1) % static_cast<int>(_games.size());
	if (idx == -1)
		idx = static_cast<int>(_games.size() - 1);
	selectGameByIdx(idx);
}

void Arcade::Core::selectPrevLib()
{
	_lib->getInstance()->closeRenderer();
	auto idx = (_graphicIdx - 1) % static_cast<int>(_libs.size());
	if (idx == -1)
		idx = static_cast<int>(_libs.size() - 1);
	selectGraphByIdx(idx);
	_lib->getInstance()->openRenderer("Arcade");
}

void Arcade::Core::selectNextLib()
{
	_lib->getInstance()->closeRenderer();
	selectGraphByIdx((_graphicIdx + 1) % static_cast<int>(_libs.size()));
	_lib->getInstance()->openRenderer("Arcade");
}

void Arcade::Core::apply_events(Arcade::Keys key)
{
	const std::map<Status, const core_bindings *> actions = {
		{MENU, &Arcade::Core::_menu_actions},
		{GAME, &Arcade::Core::_game_actions},
	};
	const std::map<Status, std::function<void (Keys key)>> apply_keys = {
		{MENU, [this](Keys key){
			this->_menu.applyEvent(key);
		}},
		{GAME, [this](Keys key){
			_game->getInstance()->update();
			this->_game->getInstance()->applyEvent(key);
		}},
	};
	if (actions.count(_status) && actions.at(_status)->count(key) > 0) {
		(this->*(actions.at(_status)->at(key)))();
	} else if (actions.count(_status))
		apply_keys.at(_status)(key);
}
