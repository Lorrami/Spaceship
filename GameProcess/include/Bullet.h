#pragma once

#include "MovableObject.h"

class Bullet : public MovableObject
{
public:
	Bullet(const sf::Vector2f startLocation, const sf::Vector2f startDirection);
	void Init();
	virtual void Update() override;

private:
	sf::Texture* m_Texture = new sf::Texture();
	const sf::Vector2f m_BodySize{ 10.f, 10.f };
	const float m_Speed = 1200.f;
	sf::Vector2f m_Direction{};

	sf::Color RandomizeColor();

};