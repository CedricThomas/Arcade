/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SDLGraphicLib.hpp
*/

#ifndef ARCADE_SDLGRAPHICLIB_HPP
	#define ARCADE_SDLGRAPHICLIB_HPP

	#include "../../api/IGraphicLib.hpp"


namespace Arcade {

	class SDLGraphicLib : public IGraphicLib {
	public:
		SDLGraphicLib();
		virtual ~SDLGraphicLib() = default;
		std::string getName() const override;
		bool isOpen() const override;
		void closeRenderer() override;
		void openRenderer() override;
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
	};
};


#endif /* !ARCADE_SDLGRAPHICLIB_HPP */
