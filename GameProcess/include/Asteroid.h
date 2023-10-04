#pragma once

#include "MovableObject.h"

class Asteroid : public MovableObject
{
public:
	Asteroid(const float speed, const float bodySize, const sf::Vector2f& position, const sf::Angle& rotation, const sf::Vector2f direction);

	virtual void Update() override;

private:
	sf::Vector2f m_Direction{};
	float m_Speed{};
	int m_Damage = 50;

	void CheckBulletCollision();
	void CheckPlayerCollision();

};