#include "Block.h"

namespace GameElements
{

	Block::Block(sf::Vector2f const size) : sf::RectangleShape(size),_bns(NULL),hitsToBreak(0)
	{
		setOutlineColor(sf::Color::Black);
		setOutlineThickness(3);
	};

	bool Block::WasHitAndDestroyed()
	{
		hitsToBreak--;
		if (hitsToBreak == 0)
		{
			delete this;
			return true;
		}
		return false;
	}

	Block::~Block()
	{
		delete _bns;
		setFillColor(sf::Color::Color(217, 221, 220));
		setOutlineThickness(0);
		setOutlineColor(sf::Color::Color(217, 221, 220));
	}
	RedBlock::RedBlock(sf::Vector2f const size) : Block(size)
	{
		hitsToBreak = 5;
		_bns = NULL;
		setFillColor(sf::Color::Red);
	}

	MagentaBlock::MagentaBlock(sf::Vector2f const size) : Block(size)
	{

		hitsToBreak = INFINITY;
		_bns = NULL;
		setFillColor(sf::Color::Magenta);
	}

	WhiteBlock::WhiteBlock(sf::Vector2f const size) : Block(size)
	{
		hitsToBreak = 1;
		_bns = NULL;
		setFillColor(sf::Color::White);
	}

	BlueBlock::BlueBlock(sf::Vector2f const size) : Block(size)
	{
		hitsToBreak = 3;
		_bns = NULL;
		setFillColor(sf::Color::Blue);
	}
}