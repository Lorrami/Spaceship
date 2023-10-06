#include "DangerZone.h"

#include "Application.h"

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
	Level* currentLevel = &(Application::Get().GetCurrentLevel());

	if (getGlobalBounds().contains(currentLevel->GetPlayer()->getPosition()))
	{
		m_IsPlayerInZone = true;
		m_CurrentTime -= Application::Get().GetDeltaTime().asSeconds();

		currentLevel->UpdateZoneTimer(m_CurrentTime);
		if (m_CurrentTime <= 0.f)
		{
			m_IsPlayerInZone = false;

			currentLevel->ZonePassed();
			currentLevel->Remove(this);
		}
	}
	else
	{
		m_IsPlayerInZone = false;
		m_CurrentTime = m_ZoneTime;
	}
}
