/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SFML
*/
#include <string>
#include <iostream>
#include "SFMLGraphicLib.hpp"

Arcade::SFMLGraphicLib::SFMLGraphicLib()
: _texture(),
_sprite(),
_text(),
_lib_name(),
_window(),
_event()
{
	sf::Font font;
	if (!font.loadFromFile("./assets/font/arial.ttf"))
		throw ("No file for font found");
	_sprite.setTexture(_texture);
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
	_window.create(sf::VideoMode(1920, 1080), "ok");
}

void Arcade::SFMLGraphicLib::clearWindow()
{
	//TODO clean window
	_window.clear();
}

void Arcade::SFMLGraphicLib::refreshWindow()
{
	_window.draw(_sprite);
	_window.display();
}

void Arcade::SFMLGraphicLib::drawPixelBox(Arcade::PixelBox &box)
{
	auto list = &box.getPixelArray()[0];
	auto size = box.getSize();
	auto pos = box.getPos();

	_texture.update((unsigned char *)(list),
			static_cast<unsigned int>(size.getX()),
			static_cast<unsigned int>(size.getY()),
			static_cast<unsigned int>(pos.getX()),
			static_cast<unsigned int>(pos.getY()));
}

void Arcade::SFMLGraphicLib::drawText(Arcade::TextBox &box)
{
	sf::Text text(box.getValue(), _font, box.getFontSize());
	_window.draw(text);
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
