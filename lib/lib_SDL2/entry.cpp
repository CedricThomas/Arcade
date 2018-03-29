/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** entry.cpp
*/

#include "SDLGraphicLib.hpp"

/* "Arcade::lib_SDL" : For example, use the class of your lib */
Arcade::SDLGraphicLib *ret = nullptr;

__attribute__((constructor))
void enter()
{
	/* Again, it's for example, use the class of your lib */
	ret = new Arcade::SDLGraphicLib;
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
