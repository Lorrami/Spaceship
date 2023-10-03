#include "Turret.h"

#include <iostream>

void Turret::UpdateRotation(const sf::Vector2i& MousePosition)
{
	float dx = -MousePosition.x + getPosition().x;
	float dy = -MousePosition.y + getPosition().y;
	sf::Angle rotation = sf::degrees(atan2(dy, dx) * 180.0f / 3.14159265f);
	setRotation(rotation);
}

void Turret::Update(const sf::Vector2i& MousePosition)
{
	UpdateRotation(MousePosition);
}

Turret::Turret()
{
	setFillColor(sf::Color::Red);
	setOrigin(sf::Vector2f(m_BodySize.x / 2, m_BodySize.y / 2));
	setSize(m_BodySize);
	setPosition(sf::Vector2f(540.f, 360.f));
}