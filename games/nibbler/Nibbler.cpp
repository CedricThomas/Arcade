/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler
*/

#include <iostream>
#include <map>
#include "Nibbler.hpp"
#include "IGameLib.hpp"

Arcade::Nibbler::Nibbler()
: _mapSize(30, 25),
_map(_mapSize.getY(), std::vector<board_t >(_mapSize.getX())),
_snake(4),
_level(0),
_score(0),
_pixelbox(),
_winsize(),
_dir()
{
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	for (size_t i = 0; i < maxX * maxY; i++) {
		if (i % maxX == 0 || i % maxX == maxX - 1 ||
		i / maxX == 0 || i / maxX == maxY - 1)
			_map[i / maxX][i % maxX].type = WALL;
	}
}

Arcade::Nibbler::~Nibbler()
{
}

void Arcade::Nibbler::refresh(Arcade::IGraphicLib &graphicLib)
{
	auto winsize = graphicLib.getScreenSize();
	if (_winsize.getY() != winsize.getY() ||
	_winsize.getX() != winsize.getX())
		recalculate(winsize);
	graphicLib.drawPixelBox(_pixelbox);
	Color blue(0, 0, 255, 255);
	/*Vect<size_t> pos(4, 2);
	_pixelbox = PixelBox(pos, {0, 0}, blue);
	graphicLib.drawPixelBox(_pixelbox);*/

	graphicLib.refreshWindow();
}

void Arcade::Nibbler::recalculate(Arcade::Vect<size_t> winsize)
{
	_winsize = winsize;
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	Vect<size_t> size(winsize.getX() / maxX, winsize.getY() / maxY);
	Color red(255, 0, 0, 255);
	Color blue(0, 0, 255, 255);
	_pixelbox = PixelBox(_winsize, {0, 0}, red);
	for (size_t i = 0; i < maxX * maxY; i++)
		if (_map[i / maxX][i % maxX].type == WALL) {
			Vect<size_t> pos(
				i % maxX * size.getX(),
				i / maxX * size.getY()
			);
			_pixelbox.putRect(pos, size, blue);
		}
}

const std::string Arcade::Nibbler::getName() const
{
	return "Nibbler";
}

bool Arcade::Nibbler::init()
{
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	for (size_t i = 0; i < maxX * maxY; i++) {
		if (i % maxX == 0 || i % maxX == maxX - 1 ||
		    i / maxX == 0 || i / maxX == maxY - 1) {
			_map[i / maxX][i % maxX].type = WALL;
			std::cerr << "X";
		} else
			std::cerr << "O";
		if (i % maxX == maxX - 1)
			std::cerr << std::endl;
	}
	return false;
}

bool Arcade::Nibbler::stop()
{
	return false;
}

bool Arcade::Nibbler::close()
{
	return false;
}

bool Arcade::Nibbler::open()
{

	return false;
}

void Arcade::Nibbler::applyEvent(Arcade::Keys key)
{
	//TODO: erase these comments
	const std::map<Arcade::Keys, Vect<int>> event = {
		{S, {0, 1}}, // up
		{Z, {0, -1}}, // down
		{D, {1, 0}}, // right
		{Q, {-1, 0}} // left
	};
	if (event.count(key))
		_dir = event.at(key);
}

void Arcade::Nibbler::update()
{
	// TODO pop_back() snake and push_front(snake[O] + _dir)
	_snake.pop_back();
	_snake.insert(_snake.begin(), _snake.at(0) + _dir);

}
