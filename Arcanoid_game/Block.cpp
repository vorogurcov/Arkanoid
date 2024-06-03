#include "Block.h"

namespace GameElements
{

	Block::Block(sf::Vector2f const size) : sf::RectangleShape(size),_bns(NULL),hitsToBreak(0)
	{
		setOutlineColor(sf::Color::Black);
		setOutlineThickness(3);
	};

	Bonus* Block::GetBonus()
	{
		return _bns;
	};

	Bonus* Block::SpawnBonus()
	{
		int num = rand() % 10;
		sf::Vector2f blockPos = this->getPosition();
		if (num < 2)
		{
			int type = rand() % 5;
			switch (type)
			{
			case 0:
				return new ChangeBallSpeed(blockPos);
				break;
			case 1:
				return new ChangeCarriageSize(blockPos);
				break;
			case 2:
				return new ChangeStickness(blockPos);
				break;
			case 3:
				return new GiveTemporaryBottom(blockPos);
				break;
			case 4:
				return new SpawnNewBall(blockPos);
				break;
			}
		}
		else
			return NULL;
	}

	bool Block::WasHitAndDestroyed()
	{
		hitsToBreak--;
		
		_bns = SpawnBonus();
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

	SpeedBlock::SpeedBlock(sf::Vector2f const size) : Block(size)
	{
		hitsToBreak = 4;
		_bns = new ChangeBallSpeed(getPosition());
		setFillColor(sf::Color::Yellow);
	}

	
}