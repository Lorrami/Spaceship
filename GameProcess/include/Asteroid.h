#pragma once

#include "MovableObject.h"

class Asteroid : public MovableObject
{
public:
	Asteroid(const float speed, const float bodySize);

	virtual void Update() override;

private:
	sf::Vector2f m_Direction{};
	float m_Speed{};
	int m_Damage = 20;

	sf::Vector2f& CalculateDirection(const sf::Vector2f& location);
	sf::Angle& CalculateRotation();
	sf::Vector2f& CalculatePosition();

	void CheckBulletCollision();
	void CheckPlayerCollision();

};