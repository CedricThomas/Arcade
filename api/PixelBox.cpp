/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PixelBox
*/
#include <cstddef>
#include "Vect.hpp"
#include "Color.hpp"
#include "PixelBox.hpp"

Arcade::PixelBox::PixelBox(Arcade::Vect<size_t> size, Arcade::Vect<size_t> pos,
			   Arcade::Color col) {

}

size_t Arcade::PixelBox::getHeight() const
{
	return _pos.getY();
}

size_t Arcade::PixelBox::getY() const
{
	return _size.getY();
}

void Arcade::PixelBox::setHeight(size_t height)
{
	_pos.setY(height);
}

void Arcade::PixelBox::setY(size_t y)
{
	_size.setY(y);
}

size_t Arcade::PixelBox::getWidth() const
{
	return _pos.getX();
}

size_t Arcade::PixelBox::getX() const
{
	return _size.getX();
}

void Arcade::PixelBox::setWidth(size_t width)
{
	_pos.setX(width);
}

void Arcade::PixelBox::setX(size_t x)
{
	_size.setX(x);
}

Arcade::Vect<size_t> Arcade::PixelBox::getSize() const
{
	return _size;
}

void Arcade::PixelBox::setSize(Arcade::Vect<size_t> size)
{
	_size = size
}

Arcade::Vect<size_t> Arcade::PixelBox::getPos() const
{
	return _pos;
}

void Arcade::PixelBox::setPos(Arcade::Vect<size_t> pos)
{
	_pos = pos;
}

void Arcade::PixelBox::putPixel(Arcade::Vect<size_t> pos, Arcade::Color col)
{
}

Arcade::Color Arcade::PixelBox::getPixel(Arcade::Vect<size_t> pos) const
{
}

void
Arcade::PixelBox::putRect(Arcade::Vect<size_t> pos, Arcade::Vect<size_t> size,
			  Arcade::Color col)
{

}

std::vector<Arcade::Color> &Arcade::PixelBox::getPixelArray()
{
	return _colorFrame;
}
