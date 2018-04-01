/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SFML
*/
#include <string>
#include <iostream>
#include "SFMLGraphicLib.hpp"

const std::map<sf::Keyboard::Key, Arcade::Keys>
Arcade::SFMLGraphicLib::_keymap = {
	{sf::Keyboard::Key::A, Arcade::Keys::A},
	{sf::Keyboard::Key::B, Arcade::Keys::B},
	{sf::Keyboard::Key::C, Arcade::Keys::C},
	{sf::Keyboard::Key::D, Arcade::Keys::D},
	{sf::Keyboard::Key::E, Arcade::Keys::E},
	{sf::Keyboard::Key::F, Arcade::Keys::F},
	{sf::Keyboard::Key::G, Arcade::Keys::G},
	{sf::Keyboard::Key::H, Arcade::Keys::H},
	{sf::Keyboard::Key::I, Arcade::Keys::I},
	{sf::Keyboard::Key::J, Arcade::Keys::J},
	{sf::Keyboard::Key::K, Arcade::Keys::K},
	{sf::Keyboard::Key::L, Arcade::Keys::L},
	{sf::Keyboard::Key::M, Arcade::Keys::M},
	{sf::Keyboard::Key::N, Arcade::Keys::N},
	{sf::Keyboard::Key::O, Arcade::Keys::O},
	{sf::Keyboard::Key::P, Arcade::Keys::P},
	{sf::Keyboard::Key::Q, Arcade::Keys::Q},
	{sf::Keyboard::Key::R, Arcade::Keys::R},
	{sf::Keyboard::Key::S, Arcade::Keys::S},
	{sf::Keyboard::Key::T, Arcade::Keys::T},
	{sf::Keyboard::Key::U, Arcade::Keys::U},
	{sf::Keyboard::Key::V, Arcade::Keys::V},
	{sf::Keyboard::Key::W, Arcade::Keys::W},
	{sf::Keyboard::Key::X, Arcade::Keys::X},
	{sf::Keyboard::Key::Y, Arcade::Keys::Y},
	{sf::Keyboard::Key::Z, Arcade::Keys::Z},
	{sf::Keyboard::Key::Left, Arcade::Keys::LEFT},
	{sf::Keyboard::Key::Right, Arcade::Keys::RIGHT},
	{sf::Keyboard::Key::Up, Arcade::Keys::UP},
	{sf::Keyboard::Key::Down, Arcade::Keys::DOWN},
	{sf::Keyboard::Key::Return, Arcade::Keys::ENTER},
	{sf::Keyboard::Key::Space, Arcade::Keys::SPACE},
	{sf::Keyboard::Key::Delete, Arcade::Keys::DELETE},
	{sf::Keyboard::Key::BackSpace, Arcade::Keys::BACKSPACE},
	{sf::Keyboard::Key::Tab, Arcade::Keys::TAB},
	{sf::Keyboard::Key::Escape, Arcade::Keys::ESC}
};


Arcade::SFMLGraphicLib::SFMLGraphicLib()
: _texture(),
_sprite(),
_text(),
_libName("SFML"),
_window(),
_event(),
_lastEvent(NONE)
{
	if (!_font.loadFromFile("./assets/font/arial.ttf"))
		throw std::runtime_error("Font not found");
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
	auto map = &Arcade::SFMLGraphicLib::_keymap;
	auto ret = false;
	if (isOpen()) {
		_window.pollEvent(_event);
		ret = true;
		if (_event.type == sf::Event::KeyPressed &&
		    map->count(_event.key.code) > 0) {
			_lastEvent = map->at(_event.key.code);
		} else if (_event.type == sf::Event::Closed) {
			this->_lastEvent = ESC;
		} else
			ret = false;
	}
	return (ret);
}

Arcade::Keys Arcade::SFMLGraphicLib::getLastEvent()
{
	return _lastEvent;
}

void Arcade::SFMLGraphicLib::clearEvents()
{
	_lastEvent = NONE;
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

size_t Arcade::SFMLGraphicLib::getMaxY() const
{
	size_t ret = 0;

	if (isOpen())
		ret = _window.getSize().y;
	return ret;
}

size_t Arcade::SFMLGraphicLib::getMaxX() const
{
	size_t ret = 0;

	if (isOpen())
		ret = _window.getSize().x;
	return ret;
}
