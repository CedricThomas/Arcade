/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SDLGraphicLib.cpp
*/
#include <SDL2/SDL.h>
#include <iostream>
#include "SDLGraphicLib.hpp"

Arcade::SDLGraphicLib::SDLGraphicLib()
: _libName("SDL2"),
_window(nullptr),
_renderer(nullptr),
_texture(nullptr),
_font(nullptr)
{
}

std::string Arcade::SDLGraphicLib::getName() const
{
	return _libName;
}

bool Arcade::SDLGraphicLib::isOpen() const
{
	return false;
}

void Arcade::SDLGraphicLib::closeRenderer()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	SDL_Quit();
}

void Arcade::SDLGraphicLib::openRenderer()
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	_window = SDL_CreateWindow("Arcade",
	                           SDL_WINDOWPOS_CENTERED,
	                           SDL_WINDOWPOS_CENTERED,
	                           1920,
	                           1080,
	                           SDL_WINDOW_SHOWN);
	// TODO check window
	auto mod = SDL_RENDERER_PRESENTVSYNC;
	_renderer = SDL_CreateRenderer(_window, -1, mod);
	_texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA32,
	                         SDL_TEXTUREACCESS_STREAMING, 1280, 720);
	SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
	_font = TTF_OpenFont("./assets/font/arial.ttf", 30);
}

void Arcade::SDLGraphicLib::clearWindow()
{
	SDL_RenderClear(_renderer);
}

void Arcade::SDLGraphicLib::refreshWindow()
{
	SDL_RenderPresent(_renderer);
}

void Arcade::SDLGraphicLib::drawPixelBox(Arcade::PixelBox &box)
{
	SDL_Rect rect;
	auto arr = &box.getPixelArray()[0];

	rect.x = static_cast<int>(box.getX());
	rect.y = static_cast<int>(box.getY());
	rect.w = static_cast<int>(box.getWidth());
	rect.h = static_cast<int>(box.getHeight());
	SDL_UpdateTexture(_texture, &rect, arr, rect.w * 4);
	SDL_RenderCopy(_renderer, _texture, &rect, &rect);
}

void Arcade::SDLGraphicLib::drawText(Arcade::TextBox &box)
{
	auto raw = (unsigned char *)box.getColor();
	SDL_Color c = {raw[0], raw[1], raw[2], raw[3]};
	auto surface = TTF_RenderText_Solid(_font, box.getValue().c_str(), c);
	auto texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_Rect rect;
	rect.x = static_cast<int>(box.getX());
	rect.y = static_cast<int>(box.getY());
	rect.w = surface->w;
	rect.h = surface->h;
	SDL_RenderCopy(_renderer, texture, nullptr, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

bool Arcade::SDLGraphicLib::pollEvents()
{
	return false;
}

Arcade::Keys Arcade::SDLGraphicLib::getLastEvent()
{
	return N;
}

void Arcade::SDLGraphicLib::clearEvents()
{

}

Arcade::Vect<size_t> Arcade::SDLGraphicLib::getScreenSize() const
{
	int w = 0;
	int h = 0;
	SDL_GetWindowSize(_window, &w, &h);
	return Vect<size_t >(static_cast<size_t>(w), static_cast<size_t>(h));
}

int Arcade::SDLGraphicLib::getMaxY() const
{
	int w = 0;
	int h = 0;
	SDL_GetWindowSize(_window, &w, &h);
	return h;
}

int Arcade::SDLGraphicLib::getMaxX() const
{
	int w = 0;
	int h = 0;
	SDL_GetWindowSize(_window, &w, &h);
	return w;
}
