/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** entryPoint.cpp
*/

#pragma clang diagnostic push
#pragma ide diagnostic ignored "CannotResolve"
#include <IGraphicLib.hpp>
#include "SFML.hpp"

/* "Arcade::SFML" : For example, use the class of your lib */
Arcade::SFML *ret = nullptr;

__attribute__((constructor))
void enter()
{
	/* Again, it's for example, use the class of your lib */
	ret = new Arcade::SFML;
}

__attribute__((destructor))
void out()
{
	delete ret;
}


extern "C" Arcade::IGraphicLib *entryPoint()
{
	//return ret;
}

#pragma clang diagnostic pop