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
_libName("SFML"),
_window(),
_event()
{
	if (!_font.loadFromFile("./assets/font/arial.ttf"))
		throw ("No file for font found"); // TODO search a solution
	_text.setFont(_font);
}

Arcade::SFMLGraphicLib::~SFMLGraphicLib()
= default;

std::string Arcade::SFMLGraphicLib::getName() const
{
	return _libName;
}

bool Arcade::SFMLGraphicLib::isOpen() const
{
	return _window.isOpen();
}

void Arcade::SFMLGraphicLib::closeRenderer()
{
	if (isOpen())
		_window.close();
}

void Arcade::SFMLGraphicLib::openRenderer()
{
	auto title = "Arcade";
	_window.create(sf::VideoMode(1920, 1080, 32), title, sf::Style::Close);
	_texture.create(1920, 1080);
	_sprite.setTexture(_texture, true);
}

void Arcade::SFMLGraphicLib::clearWindow()
{
	if (isOpen())
		_window.clear();
}

void Arcade::SFMLGraphicLib::refreshWindow()
{
	if (isOpen())
		_window.display();
}

void Arcade::SFMLGraphicLib::drawPixelBox(Arcade::PixelBox &box)
{
	if (isOpen()) {
		auto list = &box.getPixelArray()[0];
		auto size = box.getSize();
		auto pos = box.getPos();

		_texture.update((unsigned char *)(list),
	                static_cast<unsigned int>(size.getX()),
	                static_cast<unsigned int>(size.getY()),
			0, 0);
		sf::IntRect rect(0, 0,
			static_cast<unsigned int>(size.getX()),
			static_cast<unsigned int>(size.getY()));
		_sprite.setTextureRect(rect);
		_sprite.setPosition(pos.getX(), pos.getY());
		_window.draw(_sprite);
	}
}

void Arcade::SFMLGraphicLib::drawText(Arcade::TextBox &box)
{
	if (isOpen()) {
		_text.setString(box.getValue());
		auto c = box.getColor();
		sf::Color color(
			c.getRed(),
			c.getGreen(),
			c.getGreen(),
			c.getAlpha()
		);
		_text.setFillColor(color);
		_text.setCharacterSize(
			static_cast<unsigned int>(box.getFontSize())
		);
		auto pos = box.getPos();
		_text.setPosition(pos.getX(), pos.getY());
		_window.draw(_text);
	}
}

bool Arcade::SFMLGraphicLib::pollEvents()
{
	if (isOpen()) {
		_window.pollEvent(_event);
		return true;
	}
}

Arcade::Keys Arcade::SFMLGraphicLib::getLastEvent()
{
//	Arcade::Keys keys;
//	return _event.type;
}

void Arcade::SFMLGraphicLib::clearEvents()
{
	if (isOpen()) {
		_window.clear();
	}
}

Arcade::Vect<size_t> Arcade::SFMLGraphicLib::getScreenSize() const
{
	Vect<size_t> vector;

	if (isOpen()) {
		vector.setY(_window.getSize().y);
		vector.setX(_window.getSize().x);
	}
	return vector;
}

int Arcade::SFMLGraphicLib::getMaxY() const
{
	int ret = 0;

	if (isOpen())
		ret = _window.getSize().y;
	return ret;
}

int Arcade::SFMLGraphicLib::getMaxX() const
{
	int ret = 0;

	if (isOpen())
		ret = _window.getSize().x;
	return ret;
}
