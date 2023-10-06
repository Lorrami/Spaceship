#pragma once

#include "DrawableObject.h"

class MovableObject : public DrawableObject
{
public:
	virtual bool IsOnScreen();
	virtual void Move(const sf::Time deltaTime, const sf::Vector2f& direction, const float speed);
};