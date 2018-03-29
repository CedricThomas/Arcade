/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SFML
*/

#include "../../api/PixelBox.hpp"
#include "../../api/TextBox.hpp"
#include "../../api/Keys.hpp"
#include "SFML.hpp"

Arcade::SFML::SFML() : _lib_name("SFML")
{
}

Arcade::SFML::~SFML()
{

}

std::string Arcade::SFML::getName() const
{
	return _lib_name;
}

bool Arcade::SFML::isOpen() const
{
	return _window->isOpen();
}

void Arcade::SFML::closeRenderer()
{
	_window->close();
}

void Arcade::SFML::openRenderer(const std::string &title)
{
	_window->create(sf::VideoMode(200, 200), title);
}

void Arcade::SFML::clearWindow()
{
	_window->clear();
}

void Arcade::SFML::refreshWindow()
{
	_window->display();
}

void Arcade::SFML::drawPixelBox(Arcade::PixelBox &box)
{

}

void Arcade::SFML::drawText(Arcade::TextBox &box)
{
	sf::Font font;
	if (!font.loadFromFile("./font/arial.ttf"))
		throw ("No file for font found");
	sf::Text text(box.getValue(), font, box.getFontSize());
	_window->draw(text);
}

bool Arcade::SFML::pollEvents()
{
	_window->pollEvent(_event);
}

Arcade::Keys Arcade::SFML::getLastEvent()
{
	Arcade::Keys keys;
	//return _event.type;
}

void Arcade::SFML::clearEvents()
{
	_window->clear();
}

Arcade::Vect<size_t> Arcade::SFML::getScreenSize() const
{
	Vect<size_t> vector;
	vector.setY(_window->getSize().y);
	vector.setX(_window->getSize().x);
	return vector;
}

int Arcade::SFML::getMaxY() const
{
	_window->getSize().y;
}

int Arcade::SFML::getMaxX() const
{
	_window->getSize().x;
}
