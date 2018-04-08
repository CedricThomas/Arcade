/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScoreManager.hpp
*/

#ifndef ARCADE_SCOREMANAGER_HPP
	#define ARCADE_SCOREMANAGER_HPP

	#include <map>
	#include <string>
namespace  Arcade {
	class ScoreManager {
	public:
		ScoreManager();

		virtual ~ScoreManager();

		//load
		void loadMap(const std::string &id);
		//get
		const
		std::vector<std::pair<std::string, size_t>> &getScoreMap()
		const;

		//insert
		void insertScore(const std::string &name, size_t score);
		//write
		void writeScore();
		//unload
		void unloadScores();
	private:
		bool _isLoaded;
		std::string _fileName;
		std::vector<std::pair<std::string, size_t>> _scoreMap;

	};
}

#endif /* !ARCADE_SCOREMANAGER_HPP */
