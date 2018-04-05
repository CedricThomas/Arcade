/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Ghost.cpp
*/

#include "Ghost.hpp"

void Arcade::Ghost::init()
{

}

void Arcade::Ghost::changeDir(const Arcade::Vect<int> &dir)
{
	auto newX = _pos.getX() + dir.getX();
	auto newY = _pos.getY() + dir.getY();
	if (_board[newY][newX] != WALL) {
		_dir = dir;
	}
}

void Arcade::Ghost::kill()
{

}

void Arcade::Ghost::update(Player &pacman)
{
	//if (pacman)
}

void Arcade::Ghost::draw(Arcade::PixelBox &pixebox,
			 const Arcade::Vect<size_t> &size)
{

}

Arcade::Ghost::Ghost(const Vect<int> &initPos,
		     std::vector<std::vector<int>> &board) :
	_initPos(initPos),
	_dir({0, -1}),
	_pos(initPos),
	_last(),
	_board(board)
{}
