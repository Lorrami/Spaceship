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
		m_IsPlayerInZone = true;
		//std::cout << m_CurrentTime << std::endl;

		m_CurrentTime -= Application::Get().GetDeltaTime().asSeconds();
		if (m_CurrentTime <= 0.f)
		{
			m_IsPlayerInZone = false;
			Application::Get().GetCurrentLevel().ZonePassed();
			Application::Get().GetCurrentLevel().Remove(this);
			return;
		}
	}
	else
	{
		m_IsPlayerInZone = false;
		m_CurrentTime = m_ZoneTime;
	}
}
