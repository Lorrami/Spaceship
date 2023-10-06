#pragma once

#include "DrawableObject.h"
#include "HealthComponent.h"
#include "ScoreComponent.h"

class Spaceship : public DrawableObject
{
public:
	Spaceship();
	virtual void Update() override;
	void UpdateRotation();
	HealthComponent PlayerHealthComponent{};
	ScoreComponent PlayerScoreComponent{};

private:
	void OnKeyboardPressed();
	void OnMousePressed();
	void Move(const sf::Vector2f direction);
	void ShootProjectile();

	float m_Speed = 300.f;
	const sf::Vector2f m_StartPosition{ 540.f, 360.f };
	const sf::Vector2f m_BodySize{ 40.f, 40.f };

};