/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** NCursesGraphicLib.hpp
*/

#ifndef ARCADE_NCURSESGRAPHICLIB_HPP
	#define ARCADE_NCURSESGRAPHICLIB_HPP

#include "../../api/IGraphicLib.hpp"

namespace Arcade {
	class NCursesGraphicLib : public IGraphicLib {
	public:
		NCursesGraphicLib();
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
	};
}


#endif /* !ARCADE_NCURSESGRAPHICLIB_HPP */
