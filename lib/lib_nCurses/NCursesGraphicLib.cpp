/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** NCursesGraphicLib.cpp
*/

#include <math.h>
#include <ncurses.h>
#include <iostream>
#include "NCursesGraphicLib.hpp"

Arcade::NCursesGraphicLib::NCursesGraphicLib() : _libName("NCurses")
{
}

std::string Arcade::NCursesGraphicLib::getName() const
{
	return _libName;
}

bool Arcade::NCursesGraphicLib::isOpen() const
{
	return false;
}

void Arcade::NCursesGraphicLib::closeRenderer()
{
	endwin();
}

void Arcade::NCursesGraphicLib::openRenderer()
{
	initscr();
	start_color();
	for (int i = 0; i < 8; i++)
		init_pair(i, i, COLOR_BLACK);
	for (int i = 8; i < 16; i++)
		init_pair(i, i - 8, i - 8);
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
}

void Arcade::NCursesGraphicLib::clearWindow()
{
	clear();
}

void Arcade::NCursesGraphicLib::refreshWindow()
{
	refresh();
}

void Arcade::NCursesGraphicLib::drawPixelBox(Arcade::PixelBox &box)
{
	auto idx = getColorIndex(box.getColor());

	attron(COLOR_PAIR(idx + 8));
	mvprintw(0, 0, "prout"); // TODO coord
	attroff(COLOR_PAIR(idx + 8));
}

void Arcade::NCursesGraphicLib::drawText(Arcade::TextBox &box)
{
	auto idx = getColorIndex(box.getColor());

	attron(COLOR_PAIR(idx));
	mvprintw(0, 0, "prout"); // TODO coord
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
//	return nullptr;
}

int Arcade::NCursesGraphicLib::getMaxY() const
{
	return LINES;
}

int Arcade::NCursesGraphicLib::getMaxX() const
{
	return COLS;
}

size_t Arcade::NCursesGraphicLib::getColorIndex(Arcade::Color color)
{
	auto raw = (unsigned char *)color;
	float sum = raw[0] + raw[1] + raw[2];

	if (sum  > (90.0 / 100.0 * 3.0 * 255.0))
		return 7;
	for (int i = 0; i < 3; i++)
		if (raw[i] * 100.0 / sum > 60.0)
			return pow(2, i);
	for (int i = 0; i < 9; i++)
		if ((raw[i / 3] + raw[i % 3]) * 100.0 / sum > 60.0 &&
			(i / 3 != i % 3))
			return (pow(2, i % 3) + pow(2, i / 3));
	return 0;
}