#include "Bonus.h"
#include "Ball.h"
#include "Carriage.h"

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
		Carriage* car = Carriage::getInstance();
		car->_isSticky = true;
	};

	void ChangeBallSpeed::ReleaseBonus()
	{
		std::vector<Ball> balls = Ball::getBalls();
		for (auto& ball : balls)
		{
			ball.setSpeed(ball.getSpeed() + 2);
		}
	};

	void ChangeCarriageSize::ReleaseBonus()
	{
		Carriage* car = Carriage::getInstance();
		sf::Vector2f size = car->getSize();
		size.x *= 1.2;
		size.y *= 1.1;
		car->setSize(size);
	};

	void GiveTemporaryBottom::ReleaseBonus()
	{

	};
	
	void SpawnNewBall::ReleaseBonus()
	{
		Ball::getBalls().push_back(*new Ball());
	};
}