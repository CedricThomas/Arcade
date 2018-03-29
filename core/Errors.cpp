/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Error
*/

#include "Errors.hpp"

//
// ParseError
//

//
// Constructor for ParseError
// @param message to print
//

Arcade::ParseError::ParseError(std::string const &message) noexcept
: _message("ParseError : " + message)
{
}

//
// Function to return what in char*
// @return message to print
//

const char *Arcade::ParseError::what() const noexcept
{
	return _message.c_str();
}

//
// LoadingError
//

//
// Constructor for LoadingError
// @param message to print
//

Arcade::LoadingError::LoadingError(const std::string &message) noexcept
: _message("LoadingError : " + message)
{
}

//
// Function to return what in char*
// @return message to print
//

const char *Arcade::LoadingError::what() const noexcept
{
	return _message.c_str();
}