#pragma once

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "IMovable.h"



namespace GameElements {

	class ChangeBallSpeed;
	class ChangeStickness;
	class SpawnNewBall;

	class Ball :public sf::CircleShape, public IMovable
	{
	private:
		bool isSticky = false;
		Ball(sf::Vector2f pos);
		float _speed;
		float _direction;
		void setSpeed(float speed);
		void setDirection(float angle);
	public:
		friend class SpawnNewBall;
		friend class ChangeStickness;
		friend class ChangeBallSpeed;

		Ball();
		void Collide();
		void move();
		float getSpeed() const;
		float getDirection() const;
	};
}

#endif // !BALL_H
