/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** entry.cpp
*/

#include <IGraphicLib.hpp>
#include "SFMLGraphicLib.hpp"

/* "Arcade::lib_SFML" : For example, use the class of your lib */
Arcade::SFMLGraphicLib *ret = nullptr;

__attribute__((constructor))
void enter()
{
	/* Again, it's for example, use the class of your lib */
	ret = new Arcade::SFMLGraphicLib;
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
