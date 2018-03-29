/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainParse
*/

#ifndef ARCADE_MAINPARSE_HPP
	#define ARCADE_MAINPARSE_HPP

namespace Arcade {
	class SyntaxAnalyser {
	public:
		static std::string syntaxAnalyse(int ac, char **av);
		static void help(char **av);
	};
}


#endif //ARCADE_MAINPARSE_HPP
