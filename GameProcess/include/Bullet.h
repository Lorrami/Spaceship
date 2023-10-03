#pragma once

#include "DrawableObject.h"

class Bullet : public DrawableObject
{
public:
	Bullet();

	virtual void Update(const sf::Vector2i& MousePosition) override;

};