/*
** EPITECH PROJECT, 2018
** Project
** File description:
** main.cpp
*/

#include <exception>
#include <iostream>
#include "MainPars.hpp"

int main(int argc, char **argv)
{
	try {
		MainPars(argc, argv);

	}
	catch (const std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return 84;
	}
}