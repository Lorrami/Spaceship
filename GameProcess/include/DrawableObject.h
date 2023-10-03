#pragma once

#include "SFML/Graphics.hpp"

class DrawableObject : public sf::RectangleShape
{
public:
	virtual void Update(const sf::Vector2i& MousePosition) = 0;

};