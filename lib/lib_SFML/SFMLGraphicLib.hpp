/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SFML
*/

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include <SFML/Graphics.hpp>
#include "PixelBox.hpp"
#include "TextBox.hpp"
#include "Keys.hpp"
#include "IGraphicLib.hpp"

namespace Arcade {
	class SFMLGraphicLib : public IGraphicLib {
	public:
		SFMLGraphicLib();
		virtual ~SFMLGraphicLib();
		std::string getName() const final;
		bool isOpen() const final;
		void closeRenderer() final;
		void openRenderer() final;
		void clearWindow() final;
		void refreshWindow() final;
		void drawPixelBox(PixelBox &box) final;
		void drawText(TextBox &box) final;
		bool pollEvents() final;
		Keys getLastEvent() final;
		void clearEvents() final;
		Vect<size_t> getScreenSize() const final;
		size_t getMaxY() const final;
		size_t getMaxX() const final;
	private:

		sf::Texture _texture;
		sf::Sprite _sprite;
		sf::Text _text;
		sf::Font _font;

		std::string _libName;
		sf::RenderWindow _window;
		sf::Event _event;

		Arcade::Keys _lastEvent;
		static const std::map<sf::Keyboard::Key, Arcade::Keys> _keymap;
	};
}

#endif //ARCADE_SFML_HPP
