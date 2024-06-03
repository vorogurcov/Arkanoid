#pragma once


#ifndef BLOCK_H
#define BLOCK_H

#include "Bonus.h"
namespace GameElements {
	class Block : public sf::RectangleShape
	{
	protected:
		int hitsToBreak;
		Bonus* _bns;
	public:
		Block(sf::Vector2f const size);
		bool WasHitAndDestroyed();
		Bonus* GetBonus();
		Bonus* SpawnBonus();
		~Block() = 0;
	};

	class RedBlock : public Block
	{
	public:
		RedBlock(sf::Vector2f const size);
	};

	class BlueBlock : public Block
	{
	public:
		BlueBlock(sf::Vector2f const size);
	};

	class WhiteBlock :public Block
	{
	public:
		WhiteBlock(sf::Vector2f const size);
	};

	class MagentaBlock :public Block
	{
	public:
		MagentaBlock(sf::Vector2f const size);
	};

	class SpeedBlock : public Block
	{
	public:
		SpeedBlock(sf::Vector2f const size);
	};
}
#endif // !BLOCK_H
