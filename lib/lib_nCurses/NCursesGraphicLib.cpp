/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** NCursesGraphicLib.cpp
*/

#include <cmath>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <iostream>
#include <zconf.h>
#include "NCursesGraphicLib.hpp"

const std::map<int, Arcade::Keys> Arcade::NCursesGraphicLib::_keymap = {
	{'a', Arcade::Keys::A},
	{'b', Arcade::Keys::B},
	{'c', Arcade::Keys::C},
	{'d', Arcade::Keys::D},
	{'e', Arcade::Keys::E},
	{'f', Arcade::Keys::F},
	{'g', Arcade::Keys::G},
	{'h', Arcade::Keys::H},
	{'i', Arcade::Keys::I},
	{'j', Arcade::Keys::J},
	{'k', Arcade::Keys::K},
	{'l', Arcade::Keys::L},
	{'m', Arcade::Keys::M},
	{'n', Arcade::Keys::N},
	{'o', Arcade::Keys::O},
	{'p', Arcade::Keys::P},
	{'q', Arcade::Keys::Q},
	{'r', Arcade::Keys::R},
	{'s', Arcade::Keys::S},
	{'t', Arcade::Keys::T},
	{'u', Arcade::Keys::U},
	{'v', Arcade::Keys::V},
	{'w', Arcade::Keys::W},
	{'x', Arcade::Keys::X},
	{'y', Arcade::Keys::Y},
	{'z', Arcade::Keys::Z},
	{KEY_LEFT, Arcade::Keys::LEFT},
	{KEY_RIGHT, Arcade::Keys::RIGHT},
	{KEY_UP, Arcade::Keys::UP},
	{KEY_DOWN, Arcade::Keys::DOWN},
	{'\n', Arcade::Keys::ENTER},
	{' ', Arcade::Keys::SPACE},
	{KEY_DC, Arcade::Keys::DELETE},
	{KEY_BACKSPACE, Arcade::Keys::BACKSPACE},
	{'\t', Arcade::Keys::TAB},
	{27, Arcade::Keys::ESC}
};

Arcade::NCursesGraphicLib::NCursesGraphicLib():
_libName("NCurse"),
_open(false),
_cursorXsize(1),
_cursorYsize(1),
_events(),
_termios()
{
}

std::string Arcade::NCursesGraphicLib::getName() const
{
	return _libName;
}

bool Arcade::NCursesGraphicLib::isOpen() const
{
	return _open;
}

void Arcade::NCursesGraphicLib::closeRenderer()
{
	if (!_open)
		return;
	endwin();
	_open = false;
}

void Arcade::NCursesGraphicLib::openRenderer(const std::string &title)
{
	static_cast<void>(title);
	if (_open)
		return;
	initscr();
	start_color();
	for (short i = 0; i < 8; i++)
		init_pair(i, i, COLOR_BLACK);
	for (short i = 8; i < 16; i++)
		init_pair(i, i - 8, i - 8);
	cbreak();
	timeout(1);
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	_open = true;
}

void Arcade::NCursesGraphicLib::clearWindow()
{
	if (_open)
		clear();
}

void Arcade::NCursesGraphicLib::refreshWindow()
{
	if (_open)
		refresh();
}

void Arcade::NCursesGraphicLib::drawPixelBox(const Arcade::PixelBox &box)
{
	if (!_open)
		return;
	auto size = box.getSize();
	auto full = size.getX() / _cursorXsize * size.getY() / _cursorYsize;
	auto window = getScreenSize();
	for (size_t glob = 0; glob < full; glob++) {
		size_t x = glob / (box.getHeight() / _cursorYsize);
		size_t y = glob % (box.getHeight() / _cursorYsize);
		if (x > window.getX() || y > window.getY())
			continue;
		auto idx = getColorIndex(getAverageColor(box, x, y));
		attron(COLOR_PAIR(idx + 8));
		mvprintw(
			static_cast<int>(box.getY() / _cursorYsize +  y),
			static_cast<int>(box.getX() / _cursorXsize + x),
			" "
		);
		attroff(COLOR_PAIR(idx + 8));
	}
}

void Arcade::NCursesGraphicLib::drawText(const Arcade::TextBox &box)
{
	if (!_open)
		return;
	auto idx = getColorIndex(box.getColor());
	attron(COLOR_PAIR(idx));
	mvprintw(
		static_cast<int>(box.getY() / _cursorYsize),
		static_cast<int>(box.getX() / _cursorXsize),
		box.getValue().c_str()
        );
	attroff(COLOR_PAIR(idx));
}

bool Arcade::NCursesGraphicLib::pollEvents()
{
	auto map = &Arcade::NCursesGraphicLib::_keymap;
	auto ret = false;
	int input = 0;
	if (isOpen()) {
		input = getch();
		ret = true;
		if (map->count(input) > 0) {
			_events.push_back(map->at(input));
		} else
			ret = false;
	}
	return (ret);
}

Arcade::Keys Arcade::NCursesGraphicLib::getLastEvent()
{
	auto elem = Arcade::Keys::NONE;

	if (this->isOpen() && !_events.empty()) {
		elem = _events.front();
		_events.erase(_events.begin());
	}
	return elem;
}

void Arcade::NCursesGraphicLib::clearEvents()
{
	if (this->isOpen())
		_events.clear();
}

Arcade::Vect<size_t> Arcade::NCursesGraphicLib::getScreenSize() const
{
	struct winsize size;

	ioctl(0, TIOCGWINSZ, &size);
	return Vect<size_t>(size.ws_col *_cursorXsize,
	size.ws_row * _cursorYsize);
}

size_t Arcade::NCursesGraphicLib::getMaxY() const
{
	struct winsize	size;

	ioctl(0, TIOCGWINSZ, &size);
	return static_cast<size_t>(size.ws_row * _cursorYsize);
}

size_t Arcade::NCursesGraphicLib::getMaxX() const
{
	struct winsize	size;

	ioctl(0, TIOCGWINSZ, &size);
	return static_cast<size_t>(size.ws_col * _cursorXsize);
}

size_t Arcade::NCursesGraphicLib::getColorIndex(Arcade::Color color)
{
	auto raw = (unsigned char *)color;
	float sum = raw[0] + raw[1] + raw[2];

	if (sum  > (90.0 / 100.0 * 3.0 * 255.0))
		return 7;
	for (size_t i = 0; i < 3; i++)
		if (raw[i] * 100.0 / sum > 80.0)
			return static_cast<size_t>(pow(2, i));
	for (size_t i = 0; i < 9; i++)
		if ((raw[i / 3] + raw[i % 3]) * 100.0 / sum > 80.0 &&
			(i / 3 != i % 3))
			return static_cast<size_t>
			(pow(2, i % 3) + pow(2, i / 3));
	return 0;
}

Arcade::Color Arcade::NCursesGraphicLib::getAverageColor(
const Arcade::PixelBox &box, size_t x, size_t y)
{
	size_t s = 0;
	size_t r = 0;
	size_t g = 0;
	size_t b = 0;

	for (size_t idx = 0; idx < _cursorXsize * _cursorYsize; idx++) {
		auto pos = Vect<size_t>(
			x * _cursorXsize + (idx % _cursorXsize),
			y * _cursorYsize + (idx / _cursorXsize));
		auto color = box.getPixel(pos);
		r += color.getRed();
		g += color.getGreen();
		b += color.getBlue();
		s++;
	}
	if (s == 0)
		s = static_cast<size_t>(-1);
	return Arcade::Color(static_cast<unsigned char>(r / s),
	static_cast<unsigned char>(g / s), static_cast<unsigned char>(b / s),
	0);
}

Arcade::NCursesGraphicLib::~NCursesGraphicLib()
{
	if (isOpen())
		closeRenderer();
}
