/*
** EPITECH PROJECT, 2018
** Project
** File description:
** main.cpp
*/

#include <exception>
#include <iostream>
#include "MainParse.hpp"

int main(int argc, char **argv)
{
	try {
		Arcade::MainParse(argc, argv);
	}
	catch (const std::exception &e) { // TODO create Parse exception
		std::cerr << "ERROR: " << e.what() << std::endl;
		return 84;
	}
}