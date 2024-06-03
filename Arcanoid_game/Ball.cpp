#include "Ball.h"
#include "Carriage.h"
#include "cmath"
namespace GameElements {

	std::vector<Ball> Ball:: Balls;

	Ball::Ball() : _speed(0.5), _direction(90), sf::CircleShape(10)
	{
		this->setPosition(400, 670);
		this->setFillColor(sf::Color::Red);
	};

	Ball::Ball(sf::Vector2f pos) : sf::CircleShape(10), _speed(1), _direction(90)
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

	void Ball::Collide(float direction)
	{
		setDirection(getDirection() + direction);
	}

	void Ball::setBalls()
	{
		Balls = *new std::vector<Ball>;
	}

	std::vector<Ball>& Ball::getBalls()
	{
		return Balls;
	};

	void Ball::Stick()
	{
		isSticky = true;
	};

	void Ball::MakeNotSticky()
	{
		isSticky = false;
	};
}
