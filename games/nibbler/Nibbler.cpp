/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler
*/

#include <iostream>
#include "Nibbler.hpp"
#include "../../api/IGameLib.hpp"

Arcade::Nibbler::Nibbler() : _snakeSize(4), _score(0), _level(1)
{
	std::cout << "Construction" << std::endl;
}

Arcade::Nibbler::~Nibbler()
{

}

void Arcade::Nibbler::refresh(Arcade::IGraphicLib &graphicLib)
{
	auto size = graphicLib.getScreenSize();
	if (!(_size == size))
		recalculate(size);
	graphicLib.drawPixelBox(_board);
}

void Arcade::Nibbler::recalculate(Arcade::Vect<size_t> size)
{
	Color left(255, 0, 0, 255);
	Color right(0, 0, 255, 255);
	_board = PixelBox(size, {0, 0}, right);
	_board.putRect({0, 0}, {size.getX() / 2 - 10, size.getY()}, left);

}

const std::string Arcade::Nibbler::getName() const
{
	return nullptr;
}

bool Arcade::Nibbler::init()
{
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

}

void Arcade::Nibbler::update()
{

}
