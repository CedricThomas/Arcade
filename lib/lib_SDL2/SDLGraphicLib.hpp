/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SDLGraphicLib.hpp
*/

#ifndef ARCADE_SDLGRAPHICLIB_HPP
	#define ARCADE_SDLGRAPHICLIB_HPP

	#include <SDL2/SDL.h>
	#include <SDL2/SDL_ttf.h>
#include <map>
#include "IGraphicLib.hpp"


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
		size_t getMaxY() const override;
		size_t getMaxX() const override;
	private:
		bool _open;
		std::string _libName;
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Texture *_texture;
		TTF_Font *_font;
		SDL_Event _event;
		Arcade::Keys _lastEvent;
		static const std::map<SDL_Keycode, Arcade::Keys> _keymap;
	};
};


#endif /* !ARCADE_SDLGRAPHICLIB_HPP */
