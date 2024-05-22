#pragma once
#ifndef GAME_ELEMENTS_H
#define GAME_ELEMENTS_H

#include <SFML/Graphics.hpp>
#include "IMovable.h"


namespace GameElements
{
	

	class Bonus : public sf::CircleShape,public IMovable
	{
	private:
		float const _speed = 1;
		float const _direction = 90;

		virtual void ReleaseBonus() = 0;
		void setSpeed(float speed);
		float getSpeed() const;
		void setDirection(float angle);
		float getDirection() const;
	public:
		void move();
		Bonus(sf::Vector2f const pos);
		
	};

	class ChangeCarriageSize: public Bonus
	{
		
	private:
		void ReleaseBonus();
	public:
		ChangeCarriageSize(sf::Vector2f const pos) : Bonus(pos) {};
	};

	class ChangeBallSpeed : public Bonus
	{
		
	private:
		void ReleaseBonus();
	public:
		ChangeBallSpeed(sf::Vector2f const pos) : Bonus(pos) {};
	};

	class ChangeStickness : public Bonus
	{
	private:
		void ReleaseBonus();
	public:
		ChangeStickness(sf::Vector2f const pos) : Bonus(pos) {};
	};

	class GiveTemporaryBottom: public Bonus
	{
	private:
		void ReleaseBonus();
	public:
		GiveTemporaryBottom(sf::Vector2f const pos) : Bonus(pos) {};
	};

	class SpawnNewBall: public Bonus
	{
	private:
		void ReleaseBonus();
	public:
		SpawnNewBall(sf::Vector2f const pos) : Bonus(pos) {};
	};

}
#endif // !GAME_ELEMENTS_H

