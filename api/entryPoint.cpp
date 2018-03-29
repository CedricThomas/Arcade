/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** entryPoint.cpp
*/

#include "SFML.hpp"

/* "Arcade::lib_SFML" : For example, use the class of your _lib */
Arcade::SFML *ret = nullptr;

__attribute__((constructor))
void enter()
{
	/* Again, it's for example, use the class of your _lib */
	ret = new Arcade::SFML;
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
