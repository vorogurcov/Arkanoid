#pragma once

#ifndef CARRIAGE_H
#define CARRIAGE_H

#include <SFML/Graphics.hpp>
#include "IMovable.h"
namespace GameElements {
    class Bonus;
    class ChangeCarriageSize;
    class ChangeStickness;

    class Carriage : public IMovable, public sf::RectangleShape //Signleton pattern
    {
        void setSpeed(float speed);
        bool _isSticky = false;
        float getSpeed() const;
        void setDirection(float angle);
        float getDirection() const;
        static Carriage* carriage;
        Carriage(sf::Vector2f size);
        float _speed;
        float _direction;
        bool movesLeft;
    public:
        bool isSticky()
        {
            return _isSticky;
        }
        void move();
        void MakeNotSticky();
        Carriage(Carriage& obj) = delete;
        static Carriage* getInstance()
        {
            if (carriage == NULL)
            {
                sf::Vector2f size(100, 30);
                carriage = new Carriage(size);
            }
            return carriage;
        }
        void collidesWithBonus(Bonus* bns);
        void Shrink();
        void MoveLeft();
        void MoveRight();

        friend class ChangeCarriageSize;
        friend class ChangeStickness;
    };

    
};

#endif // !CARRIAGE_H
