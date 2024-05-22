#pragma once

#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

namespace GameElements
{

	class Block;

	bool checkWallCollision(const sf::Shape& sh, const sf::RenderWindow& window);
	bool checkCollision(const sf::Shape& shape1, const sf::Shape& shape2);
	std::list<Block*> CreateBlocks();

}






#endif // !GAME_FUNCTIONS_H
