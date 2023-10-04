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

sf::Color Bullet::RandomizeColor()
{
	return sf::Color::Red;
}

void Bullet::Update()
{
	if (IsOnScreen())
	{
		Move(Application::Get().GetDeltaTime());
	}
	else
	{
		Application::Get().GetCurrentLevel().Remove(this);
	}
}

bool Bullet::IsOnScreen()
{
	sf::Vector2i windowSize = Application::Get().GetWindowSize();
	if (getPosition().x > -m_BodySize.x / 2 &&
		getPosition().x < windowSize.x + m_BodySize.x / 2 &&
		getPosition().y > -m_BodySize.y / 2 &&
		getPosition().y < windowSize.y + m_BodySize.y / 2)
		return true;
	return false;
}

void Bullet::Move(const sf::Time deltaTime)
{
	sf::Vector2f prevLocation = getPosition();
	setPosition(sf::Vector2f(prevLocation.x + m_Direction.x * m_Speed * deltaTime.asSeconds(), prevLocation.y + m_Direction.y * m_Speed * deltaTime.asSeconds()));
}
