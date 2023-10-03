#pragma once

#include "SFML/Graphics.hpp"

class DrawableObject : public sf::RectangleShape
{
public:
	virtual void Update() = 0;

};