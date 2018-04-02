/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** entry.cpp
*/

#include "Nibbler.hpp"

Arcade::Nibbler *ret = nullptr;

__attribute__((constructor))
void enter()
{
	ret = new Arcade::Nibbler;
}

__attribute__((destructor))
void out()
{
	delete ret;
}


extern "C" Arcade::Nibbler *entryPoint()
{
	return ret;
}