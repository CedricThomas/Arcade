/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** TextBox
*/

#include <cstddef>
#include "Vect.hpp"
#include "Color.hpp"
#include "TextBox.hpp"
#include <string>

Arcade::TextBox::TextBox(const std::string &text, Arcade::Vect<size_t> pos,
			 size_t fontSize, Arcade::Color color,
			 Arcade::Color backgroundColor)
{
	setValue(text);
	setPos(pos);
	setFontSize(fontSize);
	setColor(color);
	setBackgroundColor(backgroundColor);
}

const std::string &Arcade::TextBox::getValue() const
{
	return _value;
}

void Arcade::TextBox::setValue(std::string const &text)
{
	_value = text;
}

Arcade::Vect<size_t> Arcade::TextBox::getPos() const
{
	return _pos;
}

void Arcade::TextBox::setPos(Arcade::Vect<size_t> pos)
{
	_pos = pos;
}

size_t Arcade::TextBox::getX() const
{
	return _pos.getX();
}

size_t Arcade::TextBox::getY() const
{
	return _pos.getY();
}

void Arcade::TextBox::setX(size_t x)
{
	_pos.setX(x);
}

void Arcade::TextBox::setY(size_t y)
{
	_pos.setY(y);
}

size_t Arcade::TextBox::getFontSize() const
{
	return _size;
}

void Arcade::TextBox::setFontSize(size_t size)
{
	_size = size;
}

Arcade::Color Arcade::TextBox::getColor() const
{
	return _color;
}

void Arcade::TextBox::setColor(Arcade::Color color)
{
	_color = color;
}

Arcade::Color Arcade::TextBox::getBackgroundColor() const {
	return _bgColor;
}

void Arcade::TextBox::setBackgroundColor(Arcade::Color color)
{
	_bgColor = color;
}