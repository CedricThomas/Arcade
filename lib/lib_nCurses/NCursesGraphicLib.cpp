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
#include "NCursesGraphicLib.hpp"

Arcade::NCursesGraphicLib::NCursesGraphicLib():
_libName("NCurse"),
_open(false),
_cursorXsize(10),
_cursorYsize(20)
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

void Arcade::NCursesGraphicLib::openRenderer()
{
	if (_open)
		return;
	initscr();
	start_color();
	for (short i = 0; i < 8; i++)
		init_pair(i, i, COLOR_BLACK);
	for (short i = 8; i < 16; i++)
		init_pair(i, i - 8, i - 8);
	cbreak();
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



void Arcade::NCursesGraphicLib::drawPixelBox(Arcade::PixelBox &box)
{
	if (!_open)
		return;
	auto size = box.getSize();
	auto full = size.getX() / _cursorXsize * size.getY() / _cursorYsize;
	for (size_t glob = 0; glob < full; glob++) {
		size_t x = glob / (box.getHeight() / _cursorYsize);
		size_t y = glob % (box.getHeight() / _cursorYsize);
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

void Arcade::NCursesGraphicLib::drawText(Arcade::TextBox &box)
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
	return false;
}

Arcade::Keys Arcade::NCursesGraphicLib::getLastEvent()
{
	//return nullptr;
}

void Arcade::NCursesGraphicLib::clearEvents()
{
}

Arcade::Vect<size_t> Arcade::NCursesGraphicLib::getScreenSize() const
{
	struct winsize size;

	ioctl(0, TIOCGWINSZ, &size);
	return Vect<size_t>(size.ws_col *_cursorXsize,
	size.ws_row * _cursorYsize);
}

int Arcade::NCursesGraphicLib::getMaxY() const
{
	struct winsize	size;

	ioctl(0, TIOCGWINSZ, &size);
	return size.ws_row * _cursorYsize;
}

int Arcade::NCursesGraphicLib::getMaxX() const
{
	struct winsize	size;

	ioctl(0, TIOCGWINSZ, &size);
	return size.ws_col * _cursorXsize;
}

size_t Arcade::NCursesGraphicLib::getColorIndex(Arcade::Color color)
{
	auto raw = (unsigned char *)color;
	float sum = raw[0] + raw[1] + raw[2];

	if (sum  > (90.0 / 100.0 * 3.0 * 255.0))
		return 7;
	for (size_t i = 0; i < 3; i++)
		if (raw[i] * 100.0 / sum > 60.0)
			return static_cast<size_t>(pow(2, i));
	for (size_t i = 0; i < 9; i++)
		if ((raw[i / 3] + raw[i % 3]) * 100.0 / sum > 60.0 &&
			(i / 3 != i % 3))
			return static_cast<size_t>
			(pow(2, i % 3) + pow(2, i / 3));
	return 0;
}

Arcade::Color Arcade::NCursesGraphicLib::getAverageColor(Arcade::PixelBox &box, size_t x, size_t y)
{
	size_t size = 0;
	size_t r = 0;
	size_t g = 0;
	size_t b = 0;

	for (size_t idx = 0; idx < _cursorXsize * _cursorYsize; idx++) {
		auto pos = Vect<size_t>(x * _cursorXsize + idx % _cursorYsize, y * _cursorYsize + idx / _cursorYsize);
		auto color = box.getPixel(pos);
		r += color.getRed();
		g += color.getGreen();
		b += color.getBlue();
		size++;
	}
	if (size == 0)
		size = 1;
	return Arcade::Color(
		static_cast<unsigned char>(r / size),
		static_cast<unsigned char>(g / size),
		static_cast<unsigned char>(b / size),
		0
	);
}
