/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SFML
*/

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include <SFML/Graphics.hpp>
#include "../../api/PixelBox.hpp"
#include "../../api/TextBox.hpp"
#include "../../api/Keys.hpp"
#include "../../api/IGraphicLib.hpp"

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
		int getMaxY() const final;
		int getMaxX() const final;
	private:

		sf::Texture _texture;
		sf::Sprite _sprite;
		sf::Text _text;
		sf::Font _font;

		std::string _lib_name;
		sf::RenderWindow _window;
		sf::Event _event;
	};
}

#endif //ARCADE_SFML_HPP
