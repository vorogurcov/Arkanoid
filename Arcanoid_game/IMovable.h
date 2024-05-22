#pragma once

#ifndef IMOVABLE_H
#define	IMOVABLE_H

class IMovable
{
public:
    virtual ~IMovable() = default;
    virtual void move() = 0;
    virtual void setSpeed(float speed) = 0;
    virtual float getSpeed() const = 0;
    virtual void setDirection(float angle) = 0;
    virtual float getDirection() const = 0;
    
};

#endif // !IMOVABLE_H
