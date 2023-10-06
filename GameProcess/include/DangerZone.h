#pragma once

#include "DrawableObject.h"

class DangerZone : public DrawableObject
{
public:
	DangerZone(float zoneTime, float zoneRadius, const sf::Vector2f& zonePosition, const sf::Color& zoneColor);

	virtual void Update() override;

	bool GetPlayerStateInDangerZone() const { return m_IsPlayerInZone; }
	void SetPlayerStateInDangerZone(const bool newState) { m_IsPlayerInZone = newState; }

	float GetTimeLeft() { return m_CurrentTime; }

private:
	float m_ZoneTime{};
	float m_CurrentTime{};
	bool m_IsPlayerInZone = false;

	void CheckCollisionWithPlayer();

};