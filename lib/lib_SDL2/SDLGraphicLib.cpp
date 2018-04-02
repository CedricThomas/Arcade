/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SDLGraphicLib.cpp
*/
#include <SDL2/SDL.h>
#include <iostream>
#include <map>
#include "SDLGraphicLib.hpp"

const std::map<SDL_Keycode, Arcade::Keys> Arcade::SDLGraphicLib::_keymap = {
	{SDLK_a, Arcade::Keys::A},
        {SDLK_b, Arcade::Keys::B},
        {SDLK_c, Arcade::Keys::C},
        {SDLK_d, Arcade::Keys::D},
        {SDLK_e, Arcade::Keys::E},
        {SDLK_f, Arcade::Keys::F},
        {SDLK_g, Arcade::Keys::G},
        {SDLK_h, Arcade::Keys::H},
        {SDLK_i, Arcade::Keys::I},
        {SDLK_j, Arcade::Keys::J},
        {SDLK_k, Arcade::Keys::K},
        {SDLK_l, Arcade::Keys::L},
        {SDLK_m, Arcade::Keys::M},
        {SDLK_n, Arcade::Keys::N},
        {SDLK_o, Arcade::Keys::O},
        {SDLK_p, Arcade::Keys::P},
        {SDLK_q, Arcade::Keys::Q},
        {SDLK_r, Arcade::Keys::R},
        {SDLK_s, Arcade::Keys::S},
        {SDLK_t, Arcade::Keys::T},
        {SDLK_u, Arcade::Keys::U},
        {SDLK_v, Arcade::Keys::V},
        {SDLK_w, Arcade::Keys::W},
        {SDLK_x, Arcade::Keys::X},
        {SDLK_y, Arcade::Keys::Y},
        {SDLK_z, Arcade::Keys::Z},
        {SDLK_LEFT, Arcade::Keys::LEFT},
        {SDLK_RIGHT, Arcade::Keys::RIGHT},
        {SDLK_UP, Arcade::Keys::UP},
        {SDLK_DOWN, Arcade::Keys::DOWN},
        {SDLK_RETURN, Arcade::Keys::ENTER},
        {SDLK_SPACE, Arcade::Keys::SPACE},
        {SDLK_DELETE, Arcade::Keys::DELETE},
        {SDLK_BACKSPACE, Arcade::Keys::BACKSPACE},
        {SDLK_TAB, Arcade::Keys::TAB},
        {SDLK_ESCAPE, Arcade::Keys::ESC}
};

Arcade::SDLGraphicLib::SDLGraphicLib()
: _open(false),
_libName("SDL2"),
_window(nullptr),
_renderer(nullptr),
_texture(nullptr),
_font(nullptr),
_events()
{
}

std::string Arcade::SDLGraphicLib::getName() const
{
	return _libName;
}

bool Arcade::SDLGraphicLib::isOpen() const
{
	return _open;
}

void Arcade::SDLGraphicLib::closeRenderer()
{
	SDL_DestroyTexture(_texture);
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	TTF_CloseFont(_font);
	TTF_Quit();
	SDL_Quit();
	_open = false;
}

void Arcade::SDLGraphicLib::openRenderer(const std::string &title)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	_window = SDL_CreateWindow(title.c_str(),
	                           SDL_WINDOWPOS_CENTERED,
	                           SDL_WINDOWPOS_CENTERED,
	                           1920,
	                           1080,
	                           SDL_WINDOW_SHOWN);
	// TODO check window
	auto mod = SDL_RENDERER_PRESENTVSYNC;
	_renderer = SDL_CreateRenderer(_window, -1, mod);
	_texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA32,
	                         SDL_TEXTUREACCESS_STREAMING, 1920, 1080);
	SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
	_font = TTF_OpenFont("./assets/font/arial.ttf", 30);
	if (!_font)
		throw std::runtime_error("Font not found");
	_open = true;
}

void Arcade::SDLGraphicLib::clearWindow()
{
	if (_open)
		SDL_RenderClear(_renderer);
}

void Arcade::SDLGraphicLib::refreshWindow()
{
	if (_open)
		SDL_RenderPresent(_renderer);
}

void Arcade::SDLGraphicLib::drawPixelBox(Arcade::PixelBox &box)
{
	if (_open) {
		SDL_Rect rect;
		auto arr = &box.getPixelArray()[0];

		rect.x = static_cast<int>(box.getX());
		rect.y = static_cast<int>(box.getY());
		rect.w = static_cast<int>(box.getWidth());
		rect.h = static_cast<int>(box.getHeight());
		SDL_UpdateTexture(_texture, &rect, arr, rect.w * 4);
		SDL_RenderCopy(_renderer, _texture, &rect, &rect);
	}
}

void Arcade::SDLGraphicLib::drawText(Arcade::TextBox &box)
{
	if (!_open || box.getValue().empty())
		return;
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
	auto map = &Arcade::SDLGraphicLib::_keymap;
	auto ret = false;
	while (isOpen() && SDL_PollEvent(&_event)) {
		if (_event.type == SDL_KEYDOWN &&
		    map->count(_event.key.keysym.sym) > 0) {
			_events.push_back(map->at(_event.key.keysym.sym));
			ret = true;
		} else if (_event.type == SDL_QUIT) {
			_events.push_back(ESC);
			ret = true;
		}
	}
	return (ret);
}

Arcade::Keys Arcade::SDLGraphicLib::getLastEvent()
{
	auto elem = Arcade::Keys::NONE;

	if (isOpen() && !_events.empty()) {
		elem = _events.front();
		_events.erase(_events.begin());
	}
	return elem;
}

void Arcade::SDLGraphicLib::clearEvents()
{
	if (isOpen())
		_events.clear();
}

Arcade::Vect<size_t> Arcade::SDLGraphicLib::getScreenSize() const
{
	int w = 0;
	int h = 0;
	if (_open)
		SDL_GetWindowSize(_window, &w, &h);
	return Vect<size_t >(static_cast<size_t>(w), static_cast<size_t>(h));
}

size_t Arcade::SDLGraphicLib::getMaxY() const
{
	int w = 0;
	int h = 0;
	if (_open)
		SDL_GetWindowSize(_window, &w, &h);
	return static_cast<size_t>(h);
}

size_t Arcade::SDLGraphicLib::getMaxX() const
{
	int w = 0;
	int h = 0;
	if (_open)
		SDL_GetWindowSize(_window, &w, &h);
	return static_cast<size_t>(w);
}

Arcade::SDLGraphicLib::~SDLGraphicLib()
{
	if (isOpen())
		closeRenderer();
}
