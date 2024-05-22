#include "Ball.h"
#include "cmath"
namespace GameElements {
	Ball::Ball() : _speed(10), _direction(270), sf::CircleShape(10)
	{
		this->setPosition(400, 700);
		this->setFillColor(sf::Color::Red);
	};

	Ball::Ball(sf::Vector2f pos) : sf::CircleShape(10), _speed(10), _direction(270)
	{
		setPosition(pos);
		this->setFillColor(sf::Color::Red);
	};

	void Ball::setDirection(float const angle)
	{
		_direction = angle;
	};

	void Ball::move()
	{
		float rad = _direction * (3.14159265 / 180);
		float previousX = getPosition().x;
		float previousY = getPosition().y;
		setPosition(previousX + _speed * cos(rad), previousY + _speed * sin(rad));
	}

	void Ball::setSpeed(float speed)
	{
		_speed = speed;
	}

	float Ball::getSpeed() const
	{
		return _speed;
	}

	float Ball::getDirection() const
	{
		return _direction;
	}

	void Ball::Collide()
	{
		setDirection(getDirection() + 90);
	}
}