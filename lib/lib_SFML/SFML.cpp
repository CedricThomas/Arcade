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

Arcade::SFML::~SFML() {

}

std::string Arcade::SFML::getName() const {
	return _lib_name;
}

bool Arcade::SFML::isOpen() const {
	return _window->isOpen();
}

void Arcade::SFML::closeRenderer() {
	_window->close();
}

void Arcade::SFML::openRenderer(const std::string &title) {
	_window = new sf::RenderWindow (sf::VideoMode(200, 200), title);
}

void Arcade::SFML::clearWindow() {
	_window->clear();
}

void Arcade::SFML::refreshWindow() {
	_window->display();
}

void Arcade::SFML::drawPixelBox(Arcade::PixelBox &box) {
	//_window->draw((const sf::Drawable &) &box);
}

void Arcade::SFML::drawText(Arcade::TextBox &box) {
	//_window->draw(&box);
}

bool Arcade::SFML::pollEvents() {
	_window->pollEvent(_event);
}

Arcade::Keys Arcade::SFML::getLastEvent() {
	//return _event.type;
}

void Arcade::SFML::clearEvents() {
	_window->clear();
}

Arcade::Vect<size_t> Arcade::SFML::getScreenSize() const {
}

int Arcade::SFML::getMaxY() const {

}

int Arcade::SFML::getMaxX() const {

}
