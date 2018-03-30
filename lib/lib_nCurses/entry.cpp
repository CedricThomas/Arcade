/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** entry.cpp
*/

#include "NCursesGraphicLib.hpp"

/* "Arcade::lib_NCurses" : For example, use the class of your lib */
Arcade::NCursesGraphicLib *ret = nullptr;

__attribute__((constructor))
void enter()
{
	/* Again, it's for example, use the class of your lib */
	ret = new Arcade::NCursesGraphicLib;
}

__attribute__((destructor))
void out()
{
	delete ret;
}


extern "C" Arcade::IGraphicLib *entryPoint()
{
	return ret;
}