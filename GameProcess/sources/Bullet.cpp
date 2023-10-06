#include "Bullet.h"

#include "Application.h"

#include <cmath>

Bullet::Bullet(const sf::Vector2f startLocation, const sf::Vector2f startDirection)
{
	setPosition(startLocation);
	m_Direction = (startDirection / (float)sqrt(startDirection.x * startDirection.x + startDirection.y * startDirection.y));
	sf::Angle rotation = sf::degrees(atan2(m_Direction.y, m_Direction.x) * 180.0f / 3.14159265f);
	setRotation(rotation);
	setSize(m_BodySize);
	setOrigin(sf::Vector2f(m_BodySize.x / 2, m_BodySize.y / 2));	
	setFillColor(RandomizeColor());
}

void Bullet::Init()
{
	if (m_Texture->loadFromFile("Resources/Bullet.png"))
	{
		setTexture(m_Texture);
	}
}

sf::Color Bullet::RandomizeColor()
{
	return sf::Color::Red;
}

void Bullet::Update()
{
	if (IsOnScreen())
	{
		Move(Application::Get().GetDeltaTime(), m_Direction, m_Speed);
	}
	else
	{
		Application::Get().GetCurrentLevel().Remove(this);
	}
}