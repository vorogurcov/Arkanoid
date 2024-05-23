#pragma once
#ifndef GAME_ELEMENTS_H
#define GAME_ELEMENTS_H

#include <SFML/Graphics.hpp>
#include "IMovable.h"


namespace GameElements
{
	class Carriage;

	class Bonus : public sf::CircleShape,public IMovable
	{
	private:
		float const _speed = 0.2;
		float const _direction = 90;
		
		void setSpeed(float speed);
		float getSpeed() const;
		void setDirection(float angle);
		float getDirection() const;
		virtual void ReleaseBonus() = 0;
		

	public:
		void move();
		friend class Carriage;
		
		
		Bonus(sf::Vector2f const pos);
		
	};

	class ChangeCarriageSize: public Bonus
	{
		void ReleaseBonus();
	public:
		ChangeCarriageSize(sf::Vector2f const pos) : Bonus(pos) {};
		
	};

	class ChangeBallSpeed : public Bonus
	{
		
		void ReleaseBonus();
	public:
		ChangeBallSpeed(sf::Vector2f const pos) : Bonus(pos) {};
		
	};

	class ChangeStickness : public Bonus
	{
		void ReleaseBonus();
	public:
		ChangeStickness(sf::Vector2f const pos) : Bonus(pos) {};
		
	};

	class GiveTemporaryBottom: public Bonus
	{
	
		void ReleaseBonus();
	public:
		GiveTemporaryBottom(sf::Vector2f const pos) : Bonus(pos) {};
		
	};

	class SpawnNewBall: public Bonus
	{
		void ReleaseBonus();
		public:
		SpawnNewBall(sf::Vector2f const pos) : Bonus(pos) {};
		
	};

}
#endif // !GAME_ELEMENTS_H

