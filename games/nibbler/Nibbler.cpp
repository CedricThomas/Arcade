/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler
*/

#include <iostream>
#include <map>
#include <zconf.h>
#include "Nibbler.hpp"
#include "IGameLib.hpp"

static const char	**map_nibbler = {"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n",
"X                              X",
"X   XXX       XXX        XXX   X",
"X                              X",
"X        X             X       X",
"X        X             X       X",
"X        X             X       X",
"X                              X",
"X                              X",
"X   X                      X   X",
"X    X                    X    X",
"X    X        XXXXX       X    X",
"X   X        XXXXXXX       X   X",
"X            XXXXXXX           X",
"X       X    XXXXXXX    X      X",
"X      X      XXXXX      X     X",
"X      X                 X     X",
"X       X               X      X",
"X                              X",
"X                              X",
"X        X             X       X",
"X        X             X       X",
"X        X             X       X",
"X                              X",
"X   XXX       XXX        XXX   X",
"X                              X",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};

Arcade::Nibbler::Nibbler()
: _mapSize(30, 25),
_map(_mapSize.getY(), std::vector<board_t >(_mapSize.getX())),
_snake(1, {1, 1}),
_level(0),
_score(0),
_background(),
_winsize(),
_dir(0, 1)
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

void Arcade::Nibbler::genWalls()
{
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	auto border = [maxX, maxY](size_t i) {
		return (i % maxX == 0 || i % maxX == maxX - 1 ||
		       i / maxX == 0 || i / maxX == maxY - 1);
	};
	for (size_t i = 0; i < maxX * maxY; i++) {
		if (border(i))
			_map[i / maxX][i % maxX].type = WALL;
		else {
			_map[i / maxX][i % maxX].type = EMPTY;
			_map[i / maxX][i % maxX].connections = SELF;
		}
	}
}

bool Arcade::Nibbler::init()
{
	_dir = {0, 1};
	_level = 0;
	_score = 0;
	_snake = std::vector<Vect<int>>(1, {1, 1});
	genWalls();
	for (int i = 0; i < 3; i++)
		moveSnake(true);
	genApple();
}

Arcade::Nibbler::~Nibbler()
{
}

void Arcade::Nibbler::refresh(Arcade::IGraphicLib &graphicLib)
{
	auto winsize = graphicLib.getScreenSize();
	if (_winsize.getY() != winsize.getY() ||
	_winsize.getX() != winsize.getX())
		resizePixelbox(winsize);
	drawDrawWalls();
	drawSnake();
	graphicLib.drawPixelBox(_background);
}

const std::string Arcade::Nibbler::getName() const
{
	return "Nibbler";
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
	const std::map<Arcade::Keys, Vect<int>> event = {
		{S, {0, 1}},
		{Z, {0, -1}},
		{D, {1, 0}},
		{Q, {-1, 0}}
	};
	if (event.count(key))
		_dir = event.at(key);
}

void Arcade::Nibbler::update()
{
	if (!moveSnake())
		exit(84);
}

bool Arcade::Nibbler::moveSnake(bool append)
{
	auto back = _snake.back();
	auto front = _snake.at(0) + _dir;
	if (_map[front.getY()][front.getX()].type == SNAKE ||
	_map[front.getY()][front.getX()].type == WALL)
		return false;
	if (_map[front.getY()][front.getX()].type != APPLE && !append) {
		_snake.pop_back();
		_map[back.getY()][back.getX()].type = EMPTY;
	} else if (!append)
		genApple();
	_snake.insert(_snake.begin(), front);
	_map[front.getY()][front.getX()].type = SNAKE;
	return true;
}

void Arcade::Nibbler::resizePixelbox(Arcade::Vect<size_t> winsize)
{
	_winsize = winsize;
	_background = PixelBox(_winsize, {0, 0});
}

void Arcade::Nibbler::drawDrawWalls()
{
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	Vect<size_t> size(_winsize.getX() / maxX, _winsize.getY() / maxY);
	Color blue(0, 0, 255, 255);
	Color red(255, 0, 0, 255);
	Color white(255, 255, 255, 255);
	for (size_t i = 0; i < maxX * maxY; i++) {
		Vect<size_t> pos(
			i % maxX * size.getX(),
			i / maxX * size.getY()
		);
		if (_map[i / maxX][i % maxX].type == WALL)
			_background.putRect(pos, size, blue);
		else if (_map[i / maxX][i % maxX].type == APPLE)
			_background.putRect(pos, size, red);
		else
			_background.putRect(pos, size, white);
	}
}

void Arcade::Nibbler::drawSnake()
{
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	Vect<size_t> size(_winsize.getX() / maxX, _winsize.getY() / maxY);
	Color green(0, 255, 0, 255);
	for (auto &n : _snake) {
		Vect<size_t> real_pos(
			n.getX() * size.getX(),
			n.getY() * size.getY()
		);
		_background.putRect(real_pos, size, green);
	}
}

void Arcade::Nibbler::genApple()
{
	bool generated = false;
	while (!generated) {
		auto x = rand() % _mapSize.getX();
		auto y = rand() % _mapSize.getY();
		if (_map[y][x].type == EMPTY) {
			_map[y][x].type = APPLE;
			generated = true;
		}
	}
}


