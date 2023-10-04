#include "DangerZone.h"

#include "Application.h"

#include <iostream>

DangerZone::DangerZone(float zoneTime, float zoneRadius, const sf::Vector2f& zonePosition, const sf::Color& zoneColor)
{
	m_ZoneTime = zoneTime;
	m_CurrentTime = m_ZoneTime;
	setSize(sf::Vector2f(zoneRadius, zoneRadius));
	setPosition(zonePosition);
	setFillColor(sf::Color::Transparent);
	setOutlineColor(zoneColor);
	setOutlineThickness(2.f);
}

void DangerZone::Update()
{
	CheckCollisionWithPlayer();
}

void DangerZone::CheckCollisionWithPlayer()
{
	if (getGlobalBounds().contains(Application::Get().GetCurrentLevel().GetPlayer()->getPosition()))
	{
		//TODO: say to level to make asteroids more complicated
		std::cout << m_CurrentTime << std::endl;

		m_CurrentTime -= Application::Get().GetDeltaTime().asSeconds();
		if (m_CurrentTime <= 0.f)
		{
			//TODO: say to level to add points to player
			Application::Get().GetCurrentLevel().ZonePassed();
			Application::Get().GetCurrentLevel().Remove(this);
			return;
		}
	}
	else
	{
		//TODO: say to level to make asteroids more easy
		m_CurrentTime = m_ZoneTime;
	}
}
