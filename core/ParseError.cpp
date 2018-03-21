/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Error
*/

#include "ParseError.hpp"

/**
 * Constructor for Error
 * @param message to print
 */

Arcade::ParseError::ParseError(std::string const &message) noexcept : _message(message)
{
}

/**
* Function to return what in char*
* @return message to print
*/

const char *Arcade::ParseError::what() const noexcept
{
	return _message.c_str();
}