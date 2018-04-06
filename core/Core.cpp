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

const Arcade::Core::core_bindings Arcade::Core::_menu_actions = {
	{Arcade::Keys::RIGHT, &Arcade::Core::selectNextLib},
	{Arcade::Keys::LEFT, &Arcade::Core::selectPrevLib},
	{Arcade::Keys::ESC, &Arcade::Core::exitArcade},
	{Arcade::Keys::ENTER, &Arcade::Core::openGame}
};

const Arcade::Core::core_bindings Arcade::Core::_game_actions = {
	{Arcade::Keys::D, &Arcade::Core::selectNextLib},
	{Arcade::Keys::Q, &Arcade::Core::selectPrevLib},
	{Arcade::Keys::ESC, &Arcade::Core::exitArcade},
	{Arcade::Keys::BACKSPACE, &Arcade::Core::goBackMenu},
	{Arcade::Keys::S, &Arcade::Core::selectNextGame},
	{Arcade::Keys::Z, &Arcade::Core::selectPrevGame},
	{Arcade::Keys::R, &Arcade::Core::resetGame}
};

Arcade::Core::Core(const std::string &graph, const std::string &game,
const std::string &selected)
:_graph(nullptr),
_game(nullptr),
_libsPaths(),
_gamesPaths(),
_libsNames(),
_gamesNames(),
_graphicIdx(0),
_gameIdx(-1),
_status(MENU),
_player(),
_menu(),
_gameLoose(false),
 _scoreManager()
{
	loadLibs(graph);
	loadGames(game);
	selectGraphByFilename(selected);
}

void Arcade::Core::start()
{
	_graph->getInstance()->openRenderer("Arcade");
	while (_status != EXIT) {
		Arcade::Keys key;
		_graph->getInstance()->pollEvents();
		do {
			key = _graph->getInstance()->getLastEvent();
			apply_events(key);
		} while (key != NONE);
		_graph->getInstance()->clearWindow();
		if (_status == MENU)
			_menu.refresh(*_graph->getInstance(), *this);
		else if (_status == GAME)
			updateGame();
		_graph->getInstance()->refreshWindow();
	}
	_graph->getInstance()->closeRenderer();
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
			_game->getInstance()->applyEvent(key);
		}},
	};
	if (actions.count(_status) && actions.at(_status)->count(key) > 0) {
		(this->*(actions.at(_status)->at(key)))();
	} else if (actions.count(_status))
		apply_keys.at(_status)(key);
}

void Arcade::Core::exitArcade()
{
	_status = EXIT;
}

void Arcade::Core::selectNextLib()
{
	auto idx = (_graphicIdx + 1) % static_cast<int>(_libsPaths.size());
	selectGraphByIdx(idx);
}

void Arcade::Core::selectPrevLib()
{
	auto idx = (_graphicIdx - 1) % static_cast<int>(_libsPaths.size());
	if (idx == -1)
		idx = static_cast<int>(_libsPaths.size() - 1);
	selectGraphByIdx(idx);
}

void Arcade::Core::selectNextGame()
{
	selectGameByIdx((_gameIdx + 1) % static_cast<int>(_gamesPaths.size()));
}

void Arcade::Core::selectPrevGame()
{
	auto idx = (_gameIdx - 1) % static_cast<int>(_gamesPaths.size());
	if (idx == -1)
		idx = static_cast<int>(_gamesPaths.size() - 1);
	selectGameByIdx(idx);
}

void Arcade::Core::selectGraphByIdx(int idx)
{
	if (static_cast<size_t>(idx) > _libsPaths.size() || idx < 0)
		throw LoadingError("the selected lib doesn't exist.");
	if (_graph)
		_graph->getInstance()->closeRenderer();
	_graphicIdx = idx;
	_graph = std::make_unique<DLLoader<IGraphicLib>>(_libsPaths[idx]);
	_graph->getInstance()->openRenderer("Arcade");
}

void Arcade::Core::selectGameByIdx(int idx)
{
	if (static_cast<size_t>(idx) > _gamesPaths.size() || idx < 0)
		throw LoadingError("the selected lib doesn't exist.");
	if (_gameIdx >= 0)
		_game->getInstance()->stop();
	_gameLoose = false;
	_gameIdx = idx;
	_game = std::make_unique<DLLoader<IGameLib>>(_gamesPaths[idx]);
	_game->getInstance()->init();
}

void Arcade::Core::resetGame()
{
	_game->getInstance()->init();
	_gameLoose = false;
}

void Arcade::Core::goBackMenu()
{
	_game->getInstance()->stop();
	_status = MENU;
}

void Arcade::Core::openGame()
{
	auto idx = static_cast<int>(_menu.getGameIdx() % _gamesPaths.size());
	if (_gameIdx != idx)
		selectGameByIdx(idx);
	_status = GAME;
}

const std::vector<std::string> &Arcade::Core::getLibs() const
{
	return _libsNames;
}

const std::vector<std::string> &Arcade::Core::getGames() const
{
	return _gamesNames;
}

int Arcade::Core::getGraphicIdx() const
{
	return _graphicIdx;
}

int Arcade::Core::getGameIdx() const
{
	return _gameIdx;
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
			auto f = std::string(_gamesPath + entry->d_name);
			auto tmp = std::make_unique<DLLoader<IGameLib>>(f);
			_gamesNames.push_back(tmp->getInstance()->getName());
			_gamesPaths.push_back(f);
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
			auto f = std::string(_libsPath + entry->d_name);
			auto tmp = std::make_unique<DLLoader<IGraphicLib>>(f);
			_libsNames.push_back(tmp->getInstance()->getName());
			_libsPaths.push_back(f);
		}
		entry = readdir(dir);
	}
	closedir(dir);
}

void Arcade::Core::selectGraphByFilename(const std::string &name)
{
	bool found = false;

	for (size_t i = 0; i < _libsPaths.size(); i++) {
		if (_libsPath + name == _libsPaths[i]) {
			selectGraphByIdx(static_cast<int>(i));
			found = true;
			break;
		}
	}
	if (!found)
		throw LoadingError("the selected lib doesn't exist.");
}

void Arcade::Core::updateGame()
{
	auto status = _game->getInstance()->update();
	if (_gameLoose != !status) {
		_scoreManager.loadMap(_game->getInstance()->getName());
		_scoreManager.insertScore(
			_menu.getPlayerName(),
			_game->getInstance()->getScore()
		);
		_scoreManager.writeScore();
		_scoreManager.unloadScores();
	}
	_gameLoose = !status;
	_game->getInstance()->refresh(*_graph->getInstance());
}

const std::vector<std::string> &Arcade::Core::getGamesPaths() const
{
	return _gamesPaths;
}
