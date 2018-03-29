/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SFML
*/
#include <string>
#include <iostream>
#include "SFMLGraphicLib.hpp"

Arcade::SFMLGraphicLib::SFMLGraphicLib() : _event()
{
}

Arcade::SFMLGraphicLib::~SFMLGraphicLib()
= default;

std::string Arcade::SFMLGraphicLib::getName() const
{
	return _lib_name;
}

bool Arcade::SFMLGraphicLib::isOpen() const
{
	return _window.isOpen();
}

void Arcade::SFMLGraphicLib::closeRenderer()
{
	_window.close();
}

void Arcade::SFMLGraphicLib::openRenderer()
{
	_window.create(sf::VideoMode(200, 200), "ok");
}

void Arcade::SFMLGraphicLib::clearWindow()
{
	_window.clear();
}

void Arcade::SFMLGraphicLib::refreshWindow()
{
	_window.display();
}

void Arcade::SFMLGraphicLib::drawPixelBox(Arcade::PixelBox &box)
{

}

void Arcade::SFMLGraphicLib::drawText(Arcade::TextBox &box)
{
//	sf::Font font;
//	if (!font.loadFromFile("./font/arial.ttf"))
//		throw ("No file for font found");
//	sf::Text text(box.getValue(), font, box.getFontSize());
//	_window.draw(text);
}

bool Arcade::SFMLGraphicLib::pollEvents()
{
	_window.pollEvent(_event);
}

Arcade::Keys Arcade::SFMLGraphicLib::getLastEvent()
{
//	Arcade::Keys keys;
//	return _event.type;
}

void Arcade::SFMLGraphicLib::clearEvents()
{
	_window.clear();
}

Arcade::Vect<size_t> Arcade::SFMLGraphicLib::getScreenSize() const
{
	Vect<size_t> vector;
	vector.setY(_window.getSize().y);
	vector.setX(_window.getSize().x);
	return vector;
}

int Arcade::SFMLGraphicLib::getMaxY() const
{
	_window.getSize().y;
}

int Arcade::SFMLGraphicLib::getMaxX() const
{
	_window.getSize().x;
}
