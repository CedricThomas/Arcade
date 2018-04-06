/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Menu.cpp
*/

#include "Core.hpp"

const Arcade::Menu::menu_bindings Arcade::Menu::_menu_actions = {
	{Arcade::Keys::UP, &Arcade::Menu::applyArrows},
	{Arcade::Keys::DOWN, &Arcade::Menu::applyArrows},
	{Arcade::Keys::BACKSPACE, &Arcade::Menu::applyBackSpace},
	{Arcade::Keys::TAB, &Arcade::Menu::applyTab},
};

const std::map<Arcade::Keys, char> Arcade::Menu::_keymap = {
	{Arcade::Keys::A, 'a'},
	{Arcade::Keys::B, 'b'},
	{Arcade::Keys::C, 'c'},
	{Arcade::Keys::D, 'd'},
	{Arcade::Keys::E, 'e'},
	{Arcade::Keys::F, 'f'},
	{Arcade::Keys::G, 'g'},
	{Arcade::Keys::H, 'h'},
	{Arcade::Keys::I, 'i'},
	{Arcade::Keys::J, 'j'},
	{Arcade::Keys::K, 'k'},
	{Arcade::Keys::L, 'l'},
	{Arcade::Keys::M, 'm'},
	{Arcade::Keys::N, 'n'},
	{Arcade::Keys::O, 'o'},
	{Arcade::Keys::P, 'p'},
	{Arcade::Keys::Q, 'q'},
	{Arcade::Keys::R, 'r'},
	{Arcade::Keys::S, 's'},
	{Arcade::Keys::T, 't'},
	{Arcade::Keys::U, 'u'},
	{Arcade::Keys::V, 'v'},
	{Arcade::Keys::W, 'w'},
	{Arcade::Keys::X, 'x'},
	{Arcade::Keys::Y, 'y'},
	{Arcade::Keys::Z, 'z'},
	{Arcade::Keys::SPACE, ' '}
};

Arcade::Menu::Menu()
: _board(),
  _size(),
  _player_name_box(" Player : player", {0, 0}),
  _player_name("player"),
  _idxGame(),
  _highscores(false),
  _scoresManager()
{
}

void Arcade::Menu::applyEvent(Arcade::Keys key)
{
	if (Arcade::Menu::_keymap.count(key) > 0 && _player_name.size() < 20) {
		_player_name += _keymap.at(key);
		_player_name_box.setValue(" Player : " + _player_name);
	}
	else if (Arcade::Menu::_menu_actions.count(key) > 0)
		(this->*(Arcade::Menu::_menu_actions.at(key)))(key);
}

Arcade::Menu::~Menu()
{
}

void Arcade::Menu::refresh(Arcade::IGraphicLib &graphicLib, const Core &core)
{
	auto winsize = graphicLib.getScreenSize();
	if (_size.getY() != winsize.getY() || _size.getX() != winsize.getX())
		recalculate(winsize);
	graphicLib.drawPixelBox(_board);
	graphicLib.drawText(_player_name_box);
	drawGames(graphicLib, core, winsize);
	if (!_highscores)
		drawLibs(graphicLib, core, winsize);
	else
		drawHighscores(graphicLib, core, winsize);
}

void Arcade::Menu::recalculate(Arcade::Vect<size_t> winsize)
{
	Color black(100, 100, 100, 255);
	Color white(255, 255, 255, 255);
	_board = PixelBox(winsize, {0, 0}, black);
	Vect<size_t> pos(
		static_cast<size_t>(winsize.getX() * 0.025),
		static_cast<size_t>(winsize.getY() * 0.05)
	);
	Vect<size_t> size(
		static_cast<size_t>(winsize.getX() / 2 * 0.90),
		static_cast<size_t>(winsize.getY() * 0.90)
	);
	_board.putRect(pos, size, white);
	pos = Vect<size_t>(pos.getX() + winsize.getX() / 2, pos.getY());
	_board.putRect(pos, size, white);
}

void Arcade::Menu::drawLibs(Arcade::IGraphicLib &graphicLib,
const Arcade::Core &core,
const Vect<size_t> &winsize)
{
	const auto &libs = core.getLibs();
	size_t idxLibs = static_cast<size_t>(core.getGraphicIdx());
	for (size_t i = 0; i < libs.size() && i < 20; i++) {
		Color color(
			255,
			static_cast<unsigned char>(255 * (i == idxLibs)),
			0,
			255
		);
		TextBox box(libs[i], {
			static_cast<size_t>(winsize.getX() * 0.03),
			static_cast<size_t>((winsize.getY() * 0.05) * (2 + i))
		}, 30, color);
		graphicLib.drawText(box);
	}
}

void Arcade::Menu::drawGames(Arcade::IGraphicLib &graphicLib,
const Arcade::Core &core,
const Arcade::Vect<size_t> &winsize)
{
	const auto &games = core.getGames();
	size_t idxGames = static_cast<size_t>(core.getGameIdx());
	auto s = games.size();
	for (size_t i = 0; i < s; i++) {
		Color color(
			static_cast<unsigned char>(255 * (i != idxGames)),
			static_cast<unsigned char>(255 * (i == _idxGame % s)),
			0,
			255
		);
		TextBox box(games[i], {
			static_cast<size_t>(
				winsize.getX() * 0.03 + winsize.getX() / 2),
			static_cast<size_t>((winsize.getY() * 0.05) * (2 + i))
		}, 30, color);
		graphicLib.drawText(box);
	}
}

size_t Arcade::Menu::getGameIdx() const
{
	return _idxGame;
}

const std::string &Arcade::Menu::getPlayerName() const
{
	return _player_name;
}

void Arcade::Menu::applyBackSpace(Keys k)
{
	static_cast<void>(k);
	if (!_player_name.empty()) {
		_player_name.pop_back();
		_player_name_box.setValue(" Player : " + _player_name);
	}
}

void Arcade::Menu::applyArrows(Keys k)
{
	if (k == UP)
		_idxGame -= 1;
	if (k == DOWN)
		_idxGame += 1;
}

void Arcade::Menu::drawHighscores(Arcade::IGraphicLib &graphicLib,
const Arcade::Core &core, const Arcade::Vect<size_t> &w)
{
	const auto &games = core.getGames();
	Color red(255, 0, 0, 255);
	_scoresManager.loadMap(games[_idxGame]);
	auto scores = _scoresManager.getScoreMap();
	for (size_t i = 0; i < scores.size() && i < 10; i++) {
		auto value = std::to_string(scores[i].second);
		TextBox box(scores[i].first + " " + value,
		{
			static_cast<size_t>(w.getX() * 0.03),
			static_cast<size_t>((w.getY() * 0.05) * (2 + i))
		},
		30, red);
		graphicLib.drawText(box);
	}
	_scoresManager.unloadScores();
}

void Arcade::Menu::applyTab(Arcade::Keys k)
{
	static_cast<void>(k);
	_highscores = !_highscores;
}
