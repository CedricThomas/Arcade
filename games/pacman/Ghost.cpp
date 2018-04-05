/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Ghost.cpp
*/

#include <iostream>
#include "Ghost.hpp"

Arcade::Ghost::Ghost(const Vect<int> &initPos,
std::vector<std::vector<int>> *board)
: _board(board),
_initPos(initPos),
_dir(0, -1),
_pos(initPos),
_alive(false),
_live(),
_death(0)
{
	(*_board)[_pos.getY()][_pos.getX()] |= GHOST;
}

void Arcade::Ghost::draw(Arcade::PixelBox &pixebox,
const Arcade::Vect<size_t> &size, Player &pacman)
{
	Vect<size_t> pos(_pos.getX() * size.getX(),
	                 _pos.getY() * size.getY());
	if (_alive && pacman.isPowered())
		pixebox.putRect(pos, size, {0, 255, 255, 255});
	else if (_alive)
		pixebox.putRect(pos, size, {255, 0, 0, 255});
	else
		pixebox.putRect(pos, size, {0, 255, 0, 255});
}

void Arcade::Ghost::init()
{
	changePos(_initPos);
	_dir = {0, -1};
	_live = std::chrono::high_resolution_clock::now();
	_alive = true;
}

void Arcade::Ghost::update(Player &pacman)
{
	if (_alive)
		updateAlive(pacman);
	else
		updateDead();
}

void Arcade::Ghost::updateAlive(Arcade::Player &pacman)
{
	checkDead(pacman);
	auto now = std::chrono::high_resolution_clock::now();
	auto diff =
	std::chrono::duration_cast<std::chrono::duration<double>>(now - _live);
	if (diff.count() < 10)
		return;
	moveAlive(pacman);
	checkDead(pacman);
}

void Arcade::Ghost::moveAlive(Player &pacman) // TODO upgrade
{
	const std::vector<Vect<int>> events = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0}
	};
	int newX;
	int newY;
	do {
		auto idx = rand() % 4;
		newX = _pos.getX() + events.at(idx).getX();
		newY = _pos.getY() + events.at(idx).getY();
	} while ((*_board)[newY][newX] & (WALL | GHOST));
	_pos = {newX, newY};
}

void Arcade::Ghost::moveDead()
{
	if (!_pathHome.empty()) {
		changePos(_pathHome.front());
		_pathHome.erase(_pathHome.begin());
	}
}

void Arcade::Ghost::updateDead()
{
	if (_pos == _initPos)
		init();
	else
		moveDead();
}

void Arcade::Ghost::checkDead(Player &pacman)
{
	if (((*_board)[_pos.getY()][_pos.getX()]) & PACMAN) {
//		if (pacman.isPowered()) {
			_alive = false;
			_death += 1;
			auto y = static_cast<int>((*_board).size());
			auto x = static_cast<int>((*_board)[0].size());
			for (size_t i = 0; !searchPath(_pos, i, {x, y}); i++);
//		} else
//			pacman.kill();
	}
}

bool Arcade::Ghost::searchPath(const Arcade::Vect<int> &pos, size_t deep,
const Arcade::Vect<int> &size)
{
	const std::vector<Vect<int>> dirs = {
		{pos.getX(), pos.getY() + 1},
		{pos.getX(), pos.getY() - 1},
		{pos.getX() + 1, pos.getY()},
		{pos.getX() - 1, pos.getY()}
	};
	if ((deep == 0 && !(pos == _initPos)) || outOfMap(pos, size) ||
	(*_board)[pos.getY()][pos.getX()] & (WALL | PASS))
		return false;
	auto ret = (pos == _initPos);
	(*_board)[pos.getY()][pos.getX()] |= PASS;
	for (size_t i = 0; i < dirs.size() && !ret && deep; i++) {
		_pathHome.push_back(dirs.at(i));
		if (searchPath(dirs.at(i), deep - 1, size))
			ret = true;
		else
			_pathHome.pop_back();
	}
	(*_board)[pos.getY()][pos.getX()] &= ~PASS;
	return ret;
}

void Arcade::Ghost::changePos(Arcade::Vect<int> pos)
{
	(*_board)[_pos.getY()][_pos.getX()] &= ~GHOST;
	_pos = pos;
	(*_board)[_pos.getY()][_pos.getX()] |= GHOST;
}

bool Arcade::Ghost::outOfMap(const Vect<int> &pos, const Vect<int> &size)
{
	return pos.getX() < 0 || pos.getY() > size.getY() ||
	pos.getX() > size.getX() || pos.getY() < 0;
}

size_t Arcade::Ghost::getDeath() const
{
	return _death;
}
