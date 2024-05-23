#include "Carriage.h"
#include "Bonus.h"

namespace GameElements {
	Carriage* Carriage::carriage = NULL;
	void Carriage::move()
	{
		float rad = _direction * (3.14159265 / 180);
		float posX = getPosition().x;
		float posY = getPosition().y;
		if (movesLeft)
			setPosition(posX + _speed * cos(rad), posY + _speed * sin(rad));
		else
			setPosition(posX - _speed * cos(rad), posY - _speed * sin(rad));

		
	};
	void Carriage::setSpeed(float speed)
	{
		_speed = speed;
	};
	float Carriage::getSpeed() const
	{
		return _speed;	
	};
	void Carriage::setDirection(float angle)
	{	
		//
	};
	float Carriage::getDirection() const
	{
		return (movesLeft)?-_direction : _direction;
	};

	Carriage::Carriage(sf::Vector2f size):sf::RectangleShape(size),_direction(180),_speed(10)
	{
		setPosition(400, 700);
		movesLeft = true;
	}

	

	void Carriage::collidesWithBonus(Bonus* bns)
	{
		bns->ReleaseBonus();
		delete bns;
	}

	void Carriage::MakeNotSticky()
	{
		_isSticky = false;
	};
	void Carriage::MoveLeft()
	{
		movesLeft = true;
	}
	void Carriage::MoveRight()
	{
		movesLeft = false;
	}
	void Carriage::Shrink()
	{
		sf::Vector2f size = carriage->getSize();
		size.x -= (size.x / 4);
		size.y -= (size.y / 6);
		carriage->setSize(size);
	}
}