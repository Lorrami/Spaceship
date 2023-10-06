#pragma once

#include "DrawableObject.h"
#include "HealthComponent.h"
#include "ScoreComponent.h"

class Spaceship : public DrawableObject
{
public:
	Spaceship();
	void Init();
	virtual void Update() override;
	void UpdateRotation();
	HealthComponent PlayerHealthComponent{};
	ScoreComponent PlayerScoreComponent{};

private:
	void OnKeyboardPressed();
	void OnMousePressed();
	void Move(const sf::Vector2f direction);
	void ShootProjectile();

	sf::Texture* m_SpaceshipTexture = new sf::Texture();
	float m_Speed = 300.f;
	const sf::Vector2f m_StartPosition{ 540.f, 360.f };
	const sf::Vector2f m_BodySize{ 60.f, 40.f };

};