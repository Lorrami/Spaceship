#include "Asteroid.h"

#include "Application.h"

Asteroid::Asteroid(const float speed, const float bodySize, const sf::Vector2f& position, const sf::Vector2f direction)
{
	m_Speed = speed;
	m_Direction = direction;
	setPosition(position);
	setOrigin(sf::Vector2f(bodySize / 2, bodySize / 2));
	setSize(sf::Vector2f(bodySize, bodySize));
}

void Asteroid::Update()
{
	if (IsOnScreen())
	{
		//TODO: check collision with bullet or player
		Move(Application::Get().GetDeltaTime(), m_Direction, m_Speed);
	}
	else
	{
		Application::Get().GetCurrentLevel().Remove(this);
	}
}
