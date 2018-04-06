/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler
*/

#include <map>
#include <zconf.h>
#include <iostream>
#include "Nibbler.hpp"
#include "IGameLib.hpp"

const std::vector<std::string> Arcade::Nibbler::_template = {
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"X  XXX        XXX       XXX  X",
	"X                            X",
	"X       X             X      X",
	"X       X             X      X",
	"X       X             X      X",
	"X                            X",
	"X                            X",
	"X  X                      X  X",
	"X   X                    X   X",
	"X   X        XXXXX       X   X",
	"X  X        XXXXXXX       X  X",
	"X           XXXXXXX          X",
	"X      X    XXXXXXX    X     X",
	"X     X      XXXXX      X    X",
	"X     X                 X    X",
	"X      X               X     X",
	"X                            X",
	"X                            X",
	"X       X             X      X",
	"X       X             X      X",
	"X       X             X      X",
	"X                            X",
	"X  XXX        XXX        XXX X",
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
};

Arcade::Nibbler::Nibbler()
: _mapSize(30, 25),
_map(_mapSize.getY(), std::vector<type_e>(_mapSize.getX())),
_snake(1, {15, 2}),
_score(-100),
_background(),
_scoreBox("score : 0", {0, 0}),
_winsize(),
_dir(0, 1),
_last(),
_loose(false),
_boost(false)
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

void Arcade::Nibbler::genWalls()
{
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	for (size_t i = 0; i < maxX * maxY; i++) {
		if (Arcade::Nibbler::_template[i / maxX][i % maxX] == 'X')
			_map[i / maxX][i % maxX] = WALL;
		else
			_map[i / maxX][i % maxX] = EMPTY;
	}
}

bool Arcade::Nibbler::init()
{
	_loose = false;
	_dir = {0, 1};
	_snake = std::vector<Vect<int>>(1, {15, 2});
	genWalls();
	for (int i = 0; i < 3; i++)
		moveSnake(true);
	genApple();
	_score = 0;
	_scoreBox.setValue("score : " + std::to_string(_score));
	_last = std::chrono::high_resolution_clock::now();
	return true;
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
	if (!_loose) {
		drawDrawWalls();
		drawSnake();
	} else
		drawGameOver();
	graphicLib.drawPixelBox(_background);
	graphicLib.drawText(_scoreBox);
}

const std::string Arcade::Nibbler::getName() const
{
	return "Nibbler";
}

bool Arcade::Nibbler::stop()
{
	return true;
}

bool Arcade::Nibbler::applyEvent(Arcade::Keys key)
{
	const std::map<Arcade::Keys, Vect<int>> event = {
		{DOWN, {0, 1}},
		{UP, {0, -1}},
		{RIGHT, {1, 0}},
		{LEFT, {-1, 0}}
	};
	auto ret = false;
	if (key == SPACE)
		_boost = true;
	if (event.count(key) && !(event.at(key).getX() == -_dir.getX() &&
		event.at(key).getY() == -_dir.getY()) && !_loose) {
		_dir = event.at(key);
		ret = true;
	}
	return ret;
}

bool Arcade::Nibbler::update()
{
	auto div = 1;
	if (_boost)
		div = 2;
	auto now = std::chrono::high_resolution_clock::now();
	auto time_span =
	std::chrono::duration_cast<std::chrono::duration<double>>(now - _last);
	if (time_span.count() < (0.5 / div - (0.01 * _score / 100)))
		return !_loose;
	_last = now;
	_loose = !moveSnake();
	_boost = false;
	return !_loose;
}

bool Arcade::Nibbler::moveSnake(bool append)
{
	auto back = _snake.back();
	auto front = _snake.at(0) + _dir;
	if (_map[front.getY()][front.getX()] == SNAKE ||
	_map[front.getY()][front.getX()] == WALL)
		return false;
	if (_map[front.getY()][front.getX()] != APPLE && !append) {
		_snake.pop_back();
		_map[back.getY()][back.getX()] = EMPTY;
	} else if (!append)
		genApple();
	_snake.insert(_snake.begin(), front);
	_map[front.getY()][front.getX()] = SNAKE;
	return true;
}

void Arcade::Nibbler::resizePixelbox(const Arcade::Vect<size_t> &winsize)
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
		if (_map[i / maxX][i % maxX] == WALL)
			_background.putRect(pos, size, blue);
		else if (_map[i / maxX][i % maxX] == APPLE)
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
	auto head = true;
	for (auto &n : _snake) {
		Vect<size_t> realPos(
			n.getX() * size.getX(),
			n.getY() * size.getY()
		);
		if (head)
			drawSnakeHead(realPos);
		else
			drawSnakeElem(realPos);
		head = false;
	}
}

void Arcade::Nibbler::genApple()
{
	_score += 100;
	_scoreBox.setValue("score : " + std::to_string(_score));
	bool generated = false;
	while (!generated) {
		auto x = rand() % _mapSize.getX();
		auto y = rand() % _mapSize.getY();
		if (_map[y][x] == EMPTY) {
			_map[y][x] = APPLE;
			generated = true;
		}
	}
}

size_t Arcade::Nibbler::getScore()
{
	return static_cast<size_t>(_score);
}

void Arcade::Nibbler::drawSnakeElem(const Arcade::Vect<size_t> &realpos)
{
	Color color(0, 255, 0, 255);
	if (_boost)
		color = Color(static_cast<unsigned char>(rand() % 255),
		static_cast<unsigned char>(rand() % 255),
		static_cast<unsigned char>(rand() % 255), 255);
	auto maxX = _mapSize.getX();
	auto maxY = _mapSize.getY();
	Vect<size_t> size(_winsize.getX() / maxX, _winsize.getY() / maxY);
	auto prc = 10;
	if (_winsize.getX() * _winsize.getY() < 10000)
		prc = 0;
	Vect<size_t> border(size.getX() * prc / 100, size.getY() * prc / 100);
	Vect<size_t> center(size.getX() * (100 - 2 * prc) / 100,
	size.getY() * (100 - 2 * prc) / 100);
	_background.putRect(realpos + border, center, color);}

void Arcade::Nibbler::drawSnakeHead(const Arcade::Vect<size_t> &realPos)
{
	Color color(0, 255, 0, 255);
	if (_boost)
		color = Color(static_cast<unsigned char>(rand() % 255),
		static_cast<unsigned char>(rand() % 255),
		static_cast<unsigned char>(rand() % 255), 255);
	Vect<size_t> size(_winsize.getX() / _mapSize.getX(),
	_winsize.getY() / _mapSize.getY());
	Vect<size_t> lSize(size.getX() / 6, size.getY()/ 6);
	_background.putRect(realPos, size, color);
	drawLeftEye(realPos, lSize);
	drawRightEye(realPos, lSize);
}

void Arcade::Nibbler::drawLeftEye(const Arcade::Vect<size_t> &rPos,
const Vect<size_t> &lSize)
{
	const std::map<std::pair<int, int>, Vect<size_t>> leyes = {
		{{0, -1}, {lSize.getX(), 4 * lSize.getY()}},
		{{0, 1}, {lSize.getX(), lSize.getY()}},
		{{1, 0}, {lSize.getX(), lSize.getY()}},
		{{-1, 0}, {4 * lSize.getX(), lSize.getY()}}
	};
	auto x = rPos.getX() + leyes.at({_dir.getX(), _dir.getY()}).getX();
	auto y = rPos.getY() + leyes.at({_dir.getX(), _dir.getY()}).getY();
	_background.putRect({x, y}, lSize, {0, 0, 0, 255});
}

void Arcade::Nibbler::drawRightEye(const Arcade::Vect<size_t> &rPos,
const Vect<size_t> &lSize)
{
	const std::map<std::pair<int, int>, Vect<size_t>> reyes = {
		{{0, -1}, {4 * lSize.getX(), 4 * lSize.getY()}},
		{{0, 1}, {4 * lSize.getX(), lSize.getY()}},
		{{1, 0}, {lSize.getX(), 4 * lSize.getY()}},
		{{-1, 0}, {4 * lSize.getX(), 4 *lSize.getY()}}
	};
	auto x = rPos.getX() + reyes.at({_dir.getX(), _dir.getY()}).getX();
	auto y = rPos.getY() + reyes.at({_dir.getX(), _dir.getY()}).getY();
	_background.putRect({x, y}, lSize, {0, 0, 0, 255});
}

void Arcade::Nibbler::drawGameOver()
{
	_scoreBox.setValue("GameOver");
}
