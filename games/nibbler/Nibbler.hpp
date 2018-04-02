/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler
*/

#ifndef ARCADE_NIBBLER_HPP
#define ARCADE_NIBBLER_HPP

#include <string>
#include <vector>
#include "../../api/IGameLib.hpp"
#include "../../api/IGraphicLib.hpp"

namespace Arcade {
	class Nibbler : public IGameLib{
		public:
		bool init() override;

		bool stop() override;

		bool close() override;

		bool open() override;

		void applyEvent(Keys key) override;

		void update() override;

		const std::string getName() const override;

		Nibbler();

		virtual ~Nibbler();
		void refresh(IGraphicLib &graphicLib);


		private:
		size_t _snakeSize;
		std::vector<size_t> _coreSnake;
		size_t _level;
		size_t _score;

		void recalculate(Vect<size_t> size);
		PixelBox _board;
		Vect<size_t> _size;
	};
}


#endif //ARCADE_NIBBLER_HPP
