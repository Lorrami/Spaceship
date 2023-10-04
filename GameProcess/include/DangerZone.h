#pragma once

#include "DrawableObject.h"

class DangerZone : public DrawableObject
{
public:
	DangerZone(float zoneTime, float zoneRadius, const sf::Vector2f& zonePosition, const sf::Color& zoneColor);

	virtual void Update() override;

private:
	float m_ZoneTime{};
	float m_CurrentTime{};

	void CheckCollisionWithPlayer();

};