/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SFML
*/

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include "../../api/PixelBox.hpp"
#include "../../api/TextBox.hpp"
#include "../../api/Keys.hpp"
#include "../../api/IGraphicLib.hpp"
#include <SFML/Graphics.hpp>

namespace Arcade {
	class SFML : public IGraphicLib {
		public:
		SFML();

		virtual ~SFML();

		std::string getName() const override;

		bool isOpen() const override;

		void closeRenderer() override;

		void openRenderer(const std::string &title) override;

		void clearWindow() override;

		void refreshWindow() override;

		void drawPixelBox(PixelBox &box) override;

		void drawText(TextBox &box) override;

		bool pollEvents() override;

		Keys getLastEvent() override;

		void clearEvents() override;

		Vect<size_t> getScreenSize() const override;

		int getMaxY() const override;

		int getMaxX() const override;

		private:
		std::string _lib_name;
		sf::RenderWindow *_window;
		sf::Event _event;
	};
}


#endif //ARCADE_SFML_HPP
