/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Menu.hpp
*/

#ifndef ARCADE_MENU_HPP
	#define ARCADE_MENU_HPP

	#include <map>
	#include "../api/IGraphicLib.hpp"
	#include "../api/Keys.hpp"

namespace Arcade {

	class Core;

	class Menu {
	public:
		Menu();
		virtual ~Menu();
		void applyEvent(Keys key);
		void refresh(IGraphicLib &graphicLib, const Core &core);
		size_t getGameIdx() const;

	private:
		void recalculate(Vect<size_t> winsize);
		void drawLibs(Arcade::IGraphicLib &graphicLib,
		const Core &core, const Vect<size_t> &winsize);
		void drawGames(Arcade::IGraphicLib &graphicLib, const Core &core,
		const Vect<size_t> &winsize);
		PixelBox _board;
		Vect<size_t> _size;
		TextBox _player_name_box;
		std::string _player_name;
		static const std::map<Arcade::Keys, char> _keymap;
		size_t _idxGame;
	};
};


#endif /* !ARCADE_MENU_HPP */
