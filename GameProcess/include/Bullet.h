#pragma once

#include "DrawableObject.h"

class Bullet : public DrawableObject
{
public:
	Bullet(const sf::Vector2f startLocation, const sf::Vector2f startDirection);
	virtual void Update() override;

private:
	const sf::Vector2f m_BodySize{ 10.f, 10.f };
	const float m_Speed = 900.f;
	sf::Vector2f m_Direction{};

	sf::Color RandomizeColor();
	bool IsOnScreen();
	void Move(const sf::Time deltaTime);

};