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
		static std::vector<Ball> Balls;
		Ball(sf::Vector2f pos);
		float _speed;
		float _direction;
		
		void setDirection(float angle);
	public:
		void MakeNotSticky();
		bool isSticky = false;
		static void setBalls();
		static std::vector<Ball>& getBalls();
		void setSpeed(float speed);
		friend class SpawnNewBall;
		friend class ChangeStickness;
		friend class ChangeBallSpeed;
		void Stick();
		Ball();
		void Collide(float direction);
	
		void move();
		float getSpeed() const;
		float getDirection() const;
	};
}

#endif // !BALL_H
