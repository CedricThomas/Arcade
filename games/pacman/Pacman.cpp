/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Pacman
*/

#include <map>
#include <cmath>
#include "Pacman.hpp"

// 0 walls
// 1 empty
// 2 pacgums
// 3 ghosts
// 4 pacman
// 5 bonus

const std::vector<std::vector<int>> Arcade::Pacman::_template = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{0,5,0,0,0,0,2,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,5,0},
	{0,2,0,0,0,0,2,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
	{0,2,0,0,0,0,2,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
	{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{0,2,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0},
	{0,2,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0},
	{0,2,2,2,2,2,2,0,0,2,2,2,2,0,2,2,2,2,0,0,2,2,2,2,2,2,0},
	{0,0,0,0,0,0,2,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,2,0,0,2,2,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,2,0,0,2,0,0,0,1,0,0,0,2,0,0,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,2,2,2,2,0,3,1,1,1,3,0,2,2,2,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,2,0,0,2,0,1,1,1,1,1,0,2,0,0,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,2,0,0,2,0,1,1,1,1,1,0,2,0,0,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,2,0,0,2,0,3,1,1,1,3,0,2,0,0,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0},
	{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{0,2,0,0,0,0,2,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
	{0,2,0,0,0,0,2,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
	{0,2,2,2,0,0,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,0,0,2,2,2,0},
	{0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0},
	{0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0},
	{0,2,2,2,2,2,2,0,0,2,2,2,2,0,2,2,2,2,0,0,2,2,2,2,2,2,0},
	{0,2,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,2,0},
	{0,5,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,5,0},
	{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
//Vect<size_t> _boardSize;
//std::vector<std::vector<type_e>> _board;
//
//// game basics resources
//int _score;
//PixelBox _boardPixelbox;
//TextBox _scoreTextbox;
//Vect<size_t> _winsize;
//std::chrono::high_resolution_clock::time_point _last;
//bool _loose;
//
//// entities
//std::vector<Ghost> _ghosts;
//Player _pacman;

Arcade::Pacman::Pacman()
: _boardSize(27, 28),
_board(_boardSize.getY(), std::vector<type_e>(_boardSize.getX())),
_score(0),
_boardPixelbox(),
_scoreTextbox("score : 0", {0, 0}),
_winsize(),
_last(),
_loose(false),
_ghosts(4),
_pacman()
{
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
	genBoard();
	initGhosts();
	initPlayer();
	return true;
}

void Arcade::Pacman::initGhosts()
{
// init all vector with map and pos
}

void Arcade::Pacman::initPlayer()
{
// init pacman with map and pos
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
		{LEFT, {-1, 0}}
	};

	// set pacman dir
	return true;
}

bool Arcade::Pacman::update()
{
	return true;
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

void Arcade::Pacman::drawGameOver()
{
	// draw game over
}

void Arcade::Pacman::drawBoard()
{
	const std::map<type_e, pacman_drawer> events = {
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
		if (events.count(_board[i / maxX ][i % maxX ]) > 0) {
			auto ptr = events.at(_board[i / maxX][i % maxX]);
			(this->*(ptr))(pos, size);
		}
	}
	drawEntities();
}

void
Arcade::Pacman::drawPacgum(const Vect <size_t> &pos, const Vect <size_t> &size)
{
	auto prc = 20;
	if (_winsize.getX() * _winsize.getY() < 10000)
		prc = 0;
	Vect<size_t> border(size.getX() * prc / 100, size.getY() * prc / 100);
	Vect<size_t> center(size.getX() * (100 - 2 * prc) / 100,
	                    size.getY() * (100 - 2 * prc) / 100);
	_boardPixelbox.putRect(pos + border, center, {255, 255, 0, 255});
}

void
Arcade::Pacman::drawBonus(const Vect <size_t> &pos, const Vect <size_t> &size)
{
	auto prc = 10;
	if (_winsize.getX() * _winsize.getY() < 10000)
		prc = 0;
	Vect<size_t> border(size.getX() * prc / 100, size.getY() * prc / 100);
	Vect<size_t> center(size.getX() * (100 - 2 * prc) / 100,
	                    size.getY() * (100 - 2 * prc) / 100);
	_boardPixelbox.putRect(pos + border, center, {255, 0, 255, 255});
}

void
Arcade::Pacman::drawWall(const Vect <size_t> &pos, const Vect <size_t> &size)
{
	_boardPixelbox.putRect(pos, size, {0, 0, 255, 255});
}

void Arcade::Pacman::drawEntities()
{
	// draw each ghost
	// draw each player
}

size_t Arcade::Pacman::getScore()
{
	return static_cast<size_t>(_score);
}

void Arcade::Pacman::genBoard()
{
	auto maxX = _boardSize.getX();
	for (size_t i = 0; i < maxX * _boardSize.getY(); i++) {
		auto val = Arcade::Pacman::_template[i / maxX][i % maxX];
		_board[i / maxX][i % maxX] = static_cast<type_e>(pow(2, val));
	}
}

void Arcade::Pacman::resizeWin(const Arcade::Vect<size_t> &winsize)
{
	_winsize = winsize;
	_boardPixelbox = PixelBox(_winsize, {0, 0});
}

