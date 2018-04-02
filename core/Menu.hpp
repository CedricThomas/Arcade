/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Menu.hpp
*/

#ifndef ARCADE_MENU_HPP
	#define ARCADE_MENU_HPP

	#include "../api/IGraphicLib.hpp"
	#include "../api/Keys.hpp"

namespace Arcade {

	class Menu {
	public:
		Menu();
		virtual ~Menu();
		void applyEvent(Keys key);
		void refresh(IGraphicLib &graphicLib);
	private:
		void recalculate(Vect<size_t> size);
		PixelBox _board;
		Vect<size_t> _size;
	};
};


#endif /* !ARCADE_MENU_HPP */
