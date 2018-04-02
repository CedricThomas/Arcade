/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

void Arcade::Menu::applyEvent(Arcade::Keys key)
{

}

void Arcade::Menu::refresh(Arcade::IGraphicLib &graphicLib)
{
	auto size = graphicLib.getScreenSize();
	if (!(_size == size))
		recalculate(size);
	graphicLib.drawPixelBox(_board);
}

Arcade::Menu::Menu(): _board(), _size()
{

}

Arcade::Menu::~Menu()
{

}

void Arcade::Menu::recalculate(Arcade::Vect<size_t> size)
{
	Color left(255, 0, 0, 255);
	Color right(0, 0, 255, 255);
	_board = PixelBox(size, {0, 0}, right);
	_board.putRect({0, 0}, {size.getX() / 2 - 10, size.getY()}, left);
}
