/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainPars
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "MainPars.hpp"
#include "Error.hpp"

/**
* Check for main Parsing : if exist, if good extesion (.so) or if enough arg
* in main
* @param ar number of arg given in main
* @param av content of arg given in main
*/

MainPars::MainPars(int ar, char **av)
{
	if (ar != 2) {
		std::cout << "Print Usage" << std::endl;
		exit(84);
	}
	std::string libname(av[1]);
	if (libname.empty())
		throw Error ("There is no filename in argument");
	size_t size = libname.find_last_of('.');
	std::string ext = libname.substr(size);
	if (ext != ".so")
		throw Error ("Wrong extension of library");
	std::ifstream libstream(libname);
	if (!libstream)
		throw Error ("No such File exist");

}
