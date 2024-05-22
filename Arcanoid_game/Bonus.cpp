#include "Bonus.h"
#include "Ball.h"

namespace GameElements
{
	Bonus::Bonus(sf::Vector2f const pos):sf::CircleShape(5)
	{
		setPosition(pos);
	}

	void Bonus::move()
	{
		float rad = _direction * (3.14159265 / 180);
		float previousX = getPosition().x;
		float previousY = getPosition().y;
		setPosition(previousX + _speed * cos(rad), previousY + _speed * sin(rad));
	}

	float Bonus::getDirection() const
	{
		return _direction;
	}
	void Bonus::setDirection(float angle)
	{
		//
	}
	void Bonus::setSpeed(float speed)
	{
		//
	}
	float Bonus::getSpeed() const
	{
		return _speed;
	}

	void ChangeStickness::ReleaseBonus()
	{
		
	};

	void ChangeBallSpeed::ReleaseBonus()
	{

	};

	void ChangeCarriageSize::ReleaseBonus()
	{
	};

	void GiveTemporaryBottom::ReleaseBonus()
	{
	};
	
	void SpawnNewBall::ReleaseBonus()
	{
	};
}