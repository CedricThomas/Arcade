/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Menu.cpp
*/

#include "Core.hpp"

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

void Arcade::Menu::applyEvent(Arcade::Keys key)
{
	if (Arcade::Menu::_keymap.count(key) > 0) {
		_player_name += _keymap.at(key);
		_player_name_box.setValue(_player_name);
	}
	if (key == BACKSPACE && !_player_name.empty()) {
		_player_name.pop_back();
		_player_name_box.setValue(_player_name);
	}
	if (key == UP) {
		_idxGame -= 1;
	}
	if (key == DOWN) {
		_idxGame += 1;
	}
}

Arcade::Menu::Menu()
: _board(),
_size(),
_player_name_box("", {0, 0}),
_player_name(),
_idxGame()
{
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
	drawLibs(graphicLib, core, winsize);
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
	for (size_t i = 0; i < libs.size(); i++) {
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
