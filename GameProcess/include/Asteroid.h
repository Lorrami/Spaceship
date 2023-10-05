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

	sf::Vector2f& CalculateDirection();
	sf::Vector2f& GetNormalToPlayer();
	sf::Angle& CalculateRotation();
	sf::Vector2f& CalculatePosition();

	void CheckBulletCollision();
	void CheckPlayerCollision();

};