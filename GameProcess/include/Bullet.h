#pragma once

#include "MovableObject.h"

class Bullet : public MovableObject
{
public:
	Bullet(const sf::Vector2f startLocation, const sf::Vector2f startDirection);
	virtual void Update() override;

private:
	const sf::Vector2f m_BodySize{ 10.f, 10.f };
	const float m_Speed = 900.f;
	sf::Vector2f m_Direction{};

	sf::Color RandomizeColor();

};