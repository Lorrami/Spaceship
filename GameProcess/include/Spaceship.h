#pragma once

#include "DrawableObject.h"

class Spaceship : public DrawableObject
{
public:
	Spaceship();
	virtual void Update() override;
	void UpdateRotation();

private:
	void OnKeyboardPressed();
	void OnMousePressed();
	void Move(const sf::Vector2f direction);
	void ShootProjectile();

	sf::Time m_Timer{};
	float m_Speed = 300.f;
	float m_ShootingDelay = 0.3f;
	const sf::Vector2f m_StartPosition{ 540.f, 360.f };
	const sf::Vector2f m_BodySize{ 60.f, 60.f };

};