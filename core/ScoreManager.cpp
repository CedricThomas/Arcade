/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScoreManager.cpp
*/

#include <algorithm>
#include <fstream>
#include <regex>
#include <iostream>
#include "ScoreManager.hpp"

Arcade::ScoreManager::ScoreManager() : _isLoaded(false), _scoreMap()
{
}

void Arcade::ScoreManager::loadMap(const std::string &id)
{
	if (_isLoaded)
		return;
	_isLoaded = true;
	_fileName = "." + id + "_score";
	std::ifstream input(_fileName);
	std::regex regex("^(\\S+)\\s+(\\d+)$");
	std::smatch m;
	for( std::string line; getline( input, line ); ) {
		if (std::regex_match(line, m, regex)) {
			_scoreMap.push_back(
				std::make_pair(m[1], std::stoi(m[2])));
		}
	}
}

void Arcade::ScoreManager::insertScore(const std::string &name, size_t score)
{
	if (name.empty() || score == 0)
		return;
	_scoreMap.push_back(std::make_pair(name, score));
	auto cmp = [](
		std::pair<std::string, size_t> a,
		std::pair<std::string, size_t> b
	)
	{
		return a.second > b.second;
	};
	std::sort(_scoreMap.begin(), _scoreMap.end(), cmp);
}

void Arcade::ScoreManager::writeScore()
{
	std::ofstream output(_fileName);
	for (auto &it : _scoreMap) {
		output << it.first << " " << it.second << std::endl;
	}
}

void Arcade::ScoreManager::unloadScores()
{
	_scoreMap.clear();
	_fileName.clear();
	_isLoaded = false;
}

const std::vector<std::pair<std::string, size_t>> &
Arcade::ScoreManager::getScoreMap() const
{
	return _scoreMap;
}

Arcade::ScoreManager::~ScoreManager()
{
}
