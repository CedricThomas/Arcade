/*
** EPITECH PROJECT, 2018
** Project
** File description:
** main.cpp
*/

#include <exception>
#include <iostream>
#include "Errors.hpp"
#include "SyntaxAnalyser.hpp"
#include "Core.hpp"

static const std::string graph_folder_g = "./lib/";
static const std::string games_folder_g = "./games/";

int main(int argc, char **argv)
{
	try {
		std::string filepath(Arcade::SyntaxAnalyser::syntaxAnalyse(argc, argv));
		Arcade::Core core(graph_folder_g, games_folder_g, filepath);
		core.play();
	} catch (Arcade::LoadingError &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
	return 0;
}