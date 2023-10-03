#pragma once

#include "DrawableObject.h"

class Turret : public DrawableObject
{
public:
	Turret();
	virtual void Update() override;
	void UpdateRotation();

private:
	void OnMousePressed();
	void ShootProjectile();

	sf::Time m_Timer{};
	float m_ShootingDelay = 0.3f;
	const sf::Vector2f m_StartPosition{ 540.f, 360.f };
	const sf::Vector2f m_BodySize{ 100.f, 100.f };

};