/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SyntaxAnalyser
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "SyntaxAnalyser.hpp"
#include "Errors.hpp"

void Arcade::SyntaxAnalyser::help(char **av)
{
	std::ostringstream oss;

	oss << "Usage : " << av[0] << " [GRAPHICLIB PATH]";
	std::cout << oss.str() << std::endl;
}


/**
* Check for main Parsing : if exist, if good extesion (.so) or if enough arg
* in main
* @param ac number of arg given in main
* @param av content of arg given in main
*/

std::string Arcade::SyntaxAnalyser::syntaxAnalyse(int ac, char **av)
{
	if (ac != 2) {
		help(av);
		throw ParseError("Invalid arguments.");
	}
	std::string libname(av[1]);
	if (libname.empty())
		throw ParseError("There is no filename in argument.");
	return libname;
}

