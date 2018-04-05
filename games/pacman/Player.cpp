/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.cpp
*/

#include "Player.hpp"

Arcade::Player::Player(const Arcade::Vect<int> &pos,
					   std::vector<std::vector<int>> &board)
	: _dir(0, -1), _posPlayer(pos), _powered(false),
	  _alive(true), _last(), _pacGumsEat(0)
{
	board[_posPlayer.getY()][_posPlayer.getX()] |= PACMAN;
}

void Arcade::Player::changeDir(const Arcade::Vect<int> &dir,
							   std::vector<std::vector<int>> &board)
{
	auto newX = _posPlayer.getX() + dir.getX();
	auto newY = _posPlayer.getY() + dir.getY();
	if (board[newY][newX] != WALL)
	{
		_dir = dir;
	}
}

void Arcade::Player::kill()
{
	_alive = false;
}

void Arcade::Player::update(std::vector<std::vector<int>> &board)
{
	updatePos(board);
	updatePacgum(board);
	auto now = std::chrono::high_resolution_clock::now();
	auto time_span =
		std::chrono::duration_cast<std::chrono::duration<double>>(now - _last);
	if (time_span.count() > 10 && _powered)
		_powered = false;
}

void Arcade::Player::draw(Arcade::PixelBox &pixebox, const Vect<size_t> &size)
{
	Vect<size_t> pos(_posPlayer.getX() * size.getX(),
					 _posPlayer.getY() * size.getY());
	if (!_powered)
		pixebox.putRect(pos, size, {255, 255, 0, 255});
	else
		pixebox.putRect(pos, size, {255, 0, 0, 255});
}

bool Arcade::Player::isPowered()
{
	return _powered;
}

int Arcade::Player::getAtePacgumns()
{
	return _pacGumsEat;
}

bool Arcade::Player::isAlive()
{
	return _alive;
}

void Arcade::Player::updatePos(std::vector<std::vector<int>> &board)
{
	auto newX = _posPlayer.getX() + _dir.getX();
	auto newY = _posPlayer.getY() + _dir.getY();
	if (board[newY][newX] & (EMPTY | PACGUM | BONUS))
	{
		board[_posPlayer.getY()][_posPlayer.getX()] &= ~PACMAN;
		_posPlayer += _dir;
		board[_posPlayer.getY()][_posPlayer.getX()] |= PACMAN;
	}
}

void Arcade::Player::updatePacgum(std::vector<std::vector<int>> &board)
{
	auto x = _posPlayer.getX();
	auto y = _posPlayer.getY();
	if (board[y][x] & BONUS)
	{
		board[y][x] &= ~BONUS;
		_powered = true;
		_last = std::chrono::high_resolution_clock::now();
		_pacGumsEat += 2;
	}
	if (board[y][x] & PACGUM)
	{
		board[y][x] &= ~PACGUM;
		_pacGumsEat += 1;
	}
}