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
	Level currentLevel = Application::Get().GetCurrentLevel();

	if (getGlobalBounds().contains(Application::Get().GetCurrentLevel().GetPlayer()->getPosition()))
	{
		currentLevel.SetPlayerStateInDangerZone(true);
		std::cout << m_CurrentTime << std::endl;

		m_CurrentTime -= Application::Get().GetDeltaTime().asSeconds();
		if (m_CurrentTime <= 0.f)
		{
			Application::Get().GetCurrentLevel().ZonePassed();
			Application::Get().GetCurrentLevel().Remove(this);
			return;
		}
	}
	else
	{
		currentLevel.SetPlayerStateInDangerZone(false);
		m_CurrentTime = m_ZoneTime;
	}
}
