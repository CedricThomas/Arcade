/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Pacman
*/

#include <map>
#include <cmath>
#include <iostream>
#include "Pacman.hpp"

const std::vector<std::vector<int>> Arcade::Pacman::_template = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
{1, 5, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 5, 1},
{1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1},
{1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1},
{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
{1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1},
{1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1},
{1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2,
2, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1},
{1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2,
2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
1, 0, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 3,
0, 0, 0, 3, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0,
0, 0, 0, 0, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0,
0, 0, 0, 0, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 3,
0, 0, 0, 3, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1},
{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
{1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1},
{1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1},
{1, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2,
2, 4, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 1},
{1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1,
1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1},
{1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1,
1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1},
{1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2,
2, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1},
{1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
{1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 1},
{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Arcade::Pacman::Pacman()
: _boardSize(27, 28),
 _board(_boardSize.getY(), std::vector<int>(_boardSize.getX())),
 _score(0),
 _boardPixelbox(),
 _scoreTextbox("score : 0", {0, 0}),
 _winsize(),
 _last(),
 _loose(false),
 _lastScore(0),
 _pacman({13, 20}, &_board)
{
	_ghosts.push_back(Ghost({15, 15}, &_board));
	_ghosts.push_back(Ghost({11, 15}, &_board));
	_ghosts.push_back(Ghost({15, 12}, &_board));
	_ghosts.push_back(Ghost({11, 12}, &_board));
}

Arcade::Pacman::~Pacman()
{
}

const std::string Arcade::Pacman::getName() const
{
	return "Pacman";
}

bool Arcade::Pacman::init()
{
	_score = 0;
	_boardPixelbox = PixelBox();
	_scoreTextbox = TextBox("score : 0", {0, 0});
	_winsize = {0, 0};
	_last = std::chrono::high_resolution_clock::now();
	_loose = false;
	_lastScore = 0;
	genBoard();
	initGhosts();
	initPlayer();
	return true;
}

void Arcade::Pacman::genBoard()
{
	auto maxX = _boardSize.getX();
	for (size_t i = 0; i < maxX * _boardSize.getY(); i++) {
		auto val = Arcade::Pacman::_template[i / maxX][i % maxX];
		auto enumType = static_cast<type_e>(pow(2, val));
		if (enumType == 1)
			enumType = EMPTY;
		_board[i / maxX][i % maxX] = enumType;
	}
}


void Arcade::Pacman::nextLevel()
{
	auto save = _score + _lastScore;
	init();
	_lastScore = save;
}

void Arcade::Pacman::initGhosts()
{
	for (auto &n : _ghosts)
		n.init();
}

void Arcade::Pacman::initPlayer()
{
	_pacman.init();
}

bool Arcade::Pacman::stop()
{
	return true;
}

bool Arcade::Pacman::applyEvent(Arcade::Keys key)
{
	const std::map<Arcade::Keys, Vect<int>> events = {
		{DOWN, {0, 1}},
		{UP, {0, -1}},
		{RIGHT, {1, 0}},
		{LEFT, {-1, 0}}};
	if (events.count(key) > 0)
		_pacman.changeDir(events.at(key));
	return true;
}

bool Arcade::Pacman::update()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto time_span =
	std::chrono::duration_cast<std::chrono::duration<double>>(now - _last);
	if (time_span.count() < 0.25)
		return !_loose;
	_last = now;
	_pacman.update();
	_loose = !_pacman.isAlive();
	_score = _pacman.getAtePacgumns() * 50;
	updateGhosts();
	if (!_loose) {
		auto pacgums = _pacman.getAtePacgumns();
		if (pacgums == 268)
			nextLevel();
	}
	return !_loose;
}

void Arcade::Pacman::refresh(Arcade::IGraphicLib &graphicLib)
{
	auto winsize = graphicLib.getScreenSize();
	if (_winsize.getY() != winsize.getY() ||
		_winsize.getX() != winsize.getX())
		resizeWin(winsize);
	if (!_loose)
		drawBoard();
	else
		drawGameOver();
	graphicLib.drawPixelBox(_boardPixelbox);
	graphicLib.drawText(_scoreTextbox);
}

void Arcade::Pacman::resizeWin(const Arcade::Vect<size_t> &winsize)
{
	_winsize = winsize;
	_boardPixelbox = PixelBox(_winsize, {0, 0});
}

void Arcade::Pacman::drawGameOver()
{
	_scoreTextbox.setValue("GameOver");
}

void Arcade::Pacman::drawBoard()
{
	const std::map<int, pacman_drawer> events = {
		{PACGUM, &Arcade::Pacman::drawPacgum},
		{BONUS, &Arcade::Pacman::drawBonus},
		{WALL, &Arcade::Pacman::drawWall},
	};
	auto maxX = _boardSize.getX();
	auto maxY = _boardSize.getY();
	Vect<size_t> size(_winsize.getX() / maxX, _winsize.getY() / maxY);
	for (size_t i = 0; i < maxX * maxY; i++) {
		Vect<size_t> pos(i % maxX * size.getX(),
		i / maxX * size.getY());
		_boardPixelbox.putRect(pos, size, {0, 0, 0, 255});
		if (events.count(_board[i / maxX][i % maxX]) > 0) {
			auto ptr = events.at(_board[i / maxX][i % maxX]);
			(this->*(ptr))(pos, size);
		}
	}
	drawEntities(size);
	auto val = "Score : " + std::to_string(_score + _lastScore);
	_scoreTextbox.setValue(val);
}

void Arcade::Pacman::drawPacgum(const Vect<size_t> &pos,
const Vect<size_t> &size)
{
	auto prc = 20;
	if (_winsize.getX() * _winsize.getY() < 10000)
		prc = 0;
	Vect<size_t> border(size.getX() * prc / 100, size.getY() * prc / 100);
	Vect<size_t> center(size.getX() * (100 - 2 * prc) / 100,
	size.getY() * (100 - 2 * prc) / 100);
	_boardPixelbox.putRect(pos + border, center, {255, 255, 255, 255});
}

void Arcade::Pacman::drawBonus(const Vect<size_t> &pos,
const Vect<size_t> &size)
{
	auto prc = 10;
	if (_winsize.getX() * _winsize.getY() < 10000)
		prc = 0;
	Vect<size_t> border(size.getX() * prc / 100, size.getY() * prc / 100);
	Vect<size_t> center(size.getX() * (100 - 2 * prc) / 100,
	size.getY() * (100 - 2 * prc) / 100);
	_boardPixelbox.putRect(pos + border, center, {255, 0, 255, 255});
}

void Arcade::Pacman::drawWall(const Vect<size_t> &pos,
const Vect<size_t> &size)
{
	_boardPixelbox.putRect(pos, size, {0, 0, 255, 255});
}

void Arcade::Pacman::drawEntities(Vect<size_t> &size)
{
	_pacman.draw(_boardPixelbox, size);
	for (auto &n : _ghosts)
		n.draw(_boardPixelbox, size, _pacman);
}

size_t Arcade::Pacman::getScore()
{
	return static_cast<size_t>(_score);
}

void Arcade::Pacman::updateGhosts()
{
//	for (auto &n : _ghosts)
//		n.setupPacmanTrack();
	for (auto &n : _ghosts) {
		n.setupPacmanTrack();
		n.update(_pacman);
		_score += n.getDeathCounter() * 100;
		n.resetPacmanTrack();
	}
//	for (auto &n : _ghosts)
//		n.resetPacmanTrack();
}
