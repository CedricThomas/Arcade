/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** NCursesGraphicLib.hpp
*/

#ifndef ARCADE_NCURSESGRAPHICLIB_HPP
#define ARCADE_NCURSESGRAPHICLIB_HPP

#include <map>
#include <termio.h>
#include "IGraphicLib.hpp"

namespace Arcade
{
	class NCursesGraphicLib : public IGraphicLib {
	public:
		NCursesGraphicLib();
		virtual ~NCursesGraphicLib();
		std::string getName() const final;
		bool isOpen() const final;
		void closeRenderer() final;
		void openRenderer(const std::string &title) final;
		void clearWindow() final;
		void refreshWindow() final;
		void drawPixelBox(const PixelBox &box) final;
		void drawText(const TextBox &box) final;
		bool pollEvents() final;
		Keys getLastEvent() final;
		void clearEvents() final;
		Vect<size_t> getScreenSize() const final;
		size_t getMaxY() const final;
		size_t getMaxX() const final;
		size_t getColorIndex(Arcade::Color color);
		Color getAverageColor(const PixelBox &box, size_t x, size_t y);

	private:
		std::string _libName;
		bool _open;
		size_t _cursorXsize;
		size_t _cursorYsize;
		std::vector<Arcade::Keys> _events;
		static const std::map<int, Arcade::Keys> _keymap;
		struct termio _termios;
	};
}

#endif /* !ARCADE_NCURSESGRAPHICLIB_HPP */
