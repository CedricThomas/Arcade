/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** entry.cpp
*/

#include "Pacman.hpp"

Arcade::Pacman *ret = nullptr;

__attribute__((constructor))
void enter()
{
	ret = new Arcade::Pacman;
}

__attribute__((destructor))
void out()
{
	delete ret;
}


extern "C" Arcade::Pacman *entryPoint()
{
	return ret;
}