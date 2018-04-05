/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Ghost.cpp
*/

#include "Ghost.hpp"

Arcade::Ghost::Ghost(const Vect<int> &initPos,
std::vector<std::vector<int>> *board)
: _board(board),
  _initPos(initPos),
  _dir({0, -1}),
  _pos(initPos),
  _alive(true),
  _live()
{
	(*_board)[_pos.getY()][_pos.getX()] |= GHOST;
}

void Arcade::Ghost::draw(Arcade::PixelBox &pixebox,
const Arcade::Vect<size_t> &size, Player &pacman)
{
	Vect<size_t> pos(_pos.getX() * size.getX(),
	                 _pos.getY() * size.getY());
	if (pacman.isPowered())
		pixebox.putRect(pos, size, {0, 255, 255, 255});
	else
		pixebox.putRect(pos, size, {255, 0, 0, 255});
}

void Arcade::Ghost::init()
{
	(*_board)[_pos.getY()][_pos.getX()] &= ~GHOST;
	_pos = _initPos;
	(*_board)[_pos.getY()][_pos.getX()] |= GHOST;
	_dir = {0, -1};
	_pos =_initPos;
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
	moveAlive();
	checkDead(pacman);
}

void Arcade::Ghost::updateDead()
{

}

void Arcade::Ghost::moveAlive() // TODO upgrade
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
	} while ((*_board)[newY][newX] == WALL);
	_pos = {newX, newY};
}

void Arcade::Ghost::moveDead()
{

}

void Arcade::Ghost::checkDead(Player &pacman)
{
	if (((*_board)[_pos.getY()][_pos.getX()]) & PACMAN) {
		if (pacman.isPowered())
			_alive = false;
		else
			pacman.kill();
	}
}
