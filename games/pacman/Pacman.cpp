/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Pacman
*/

#include <map>
#include "Pacman.hpp"

// 0 walls
// 1 empty
// 2 ghosts
// 3 pacgums
// 5 pacman

const std::vector<std::vector<int>> Arcade::Pacman::_template = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,3,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,3,0},
	{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
	{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
	{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
	{0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,1,0,0,0,2,2,0,0,0,1,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,0,0,2,2,2,2,0,0,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,1,0,0,2,2,2,2,0,0,1,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
	{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
	{0,1,1,1,0,0,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,0,0,1,1,1,0},
	{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
	{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
	{0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0},
	{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,3,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,3,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Arcade::Pacman::Pacman() : _mapSize(28, 28),
			   _map(_mapSize.getY(), std::vector<type_e>(_mapSize.getX())),
			   _pacman(5, {0, 0}),
			   _level(0),
			   _score(-100),
			   _background(),
			   _scoreBox("score : 0", {0, 0}),
			   _winsize(),
			   _dir(0, 1),
			   _last(),
			   _loose(false)
{
_ghost = {{1, {3,1}}, {2, {3, 26}},{3, {3, 26}}, {4, {26, 3}}};
}

Arcade::Pacman::~Pacman()
{

}

void Arcade::Pacman::drawGameOver()
{
	_scoreBox.setValue("Game Over");
}

void Arcade::Pacman::drawMaps()
{
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	Vect<size_t> size(_winsize.getX() / maxX, _winsize.getY() / maxY);
	Color blue(0, 0, 255, 255);
	Color red(255, 0, 0, 255);
	Color white(255, 255, 255, 255);
	Color yellow(255,255,0,255);
	Color black(0, 0, 0, 255);
	std::map<type_e , Color> colorMap= {{PACMAN,  yellow},
					    {WALL,    blue},
					    {EMPTY,   black},
					    {PACGUMS, red},
					    {GHOST, white}};

	for (size_t i = 0; i < maxX * maxY; i++) {
		Vect<size_t> pos(
			i % maxX * size.getX(),
			i / maxX * size.getY()
		);
		_background.putRect(pos, size, colorMap[_map[i / maxX][i % maxX]]);
	}
}

const std::string Arcade::Pacman::getName() const
{
	return "Pacman";
}

bool Arcade::Pacman::init()
{
	_loose = false;
	_dir = {0, 1};
	_level = 0;
	_pacman = std::vector<Vect<int>>(1, {15, 2});
	_ghost = {{1, {3,1}}, {2, {3, 26}},{3, {3, 26}}, {4, {26, 3}}};
	genMaps();
	/*for (int i = 0; i < 3; i++)
		moveSnake(true);*/
	_score = 0;
	_scoreBox.setValue("score : " + std::to_string(_score));
	_last = std::chrono::high_resolution_clock::now();
	return true;
}

bool Arcade::Pacman::stop()
{
	return false;
}

bool Arcade::Pacman::applyEvent(Arcade::Keys key)
{
	return false;
}

bool Arcade::Pacman::update()
{
	return false;
}

void Arcade::Pacman::refresh(Arcade::IGraphicLib &graphicLib)
{
	auto winsize = graphicLib.getScreenSize();
	if (_winsize.getY() != winsize.getY() ||
	    _winsize.getX() != winsize.getX())
		resizePixelbox(winsize);
	if (!_loose) {
		drawMaps();
		//drawSnake();
	} else
		drawGameOver();
	graphicLib.drawPixelBox(_background);
	graphicLib.drawText(_scoreBox);
}

size_t Arcade::Pacman::getScore()
{
	return static_cast<size_t>(_score);
}

void Arcade::Pacman::genMaps()
{
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	for (size_t i = 0; i < maxX * maxY; i++) {
		type_e enu = static_cast<type_e>(Arcade::Pacman::_template[i / maxX][i % maxX]);
		_map[i / maxX][i % maxX] = enu;
		printf("%d\n", enu);
	}
}

void Arcade::Pacman::resizePixelbox(const Arcade::Vect<size_t> &winsize)
{
	_winsize = winsize;
	_background = PixelBox(_winsize, {0, 0});
}
