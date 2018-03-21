/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Error
*/

#ifndef ARCADE_ERROR_HPP
#define ARCADE_ERROR_HPP

#include <iostream>

class Error : public std::exception
{
public:
	Error(std::string const &message = "Unknown") noexcept;
	const char *what() const noexcept;

protected:
	const std::string _message;
};


#endif //ARCADE_ERROR_HPP
