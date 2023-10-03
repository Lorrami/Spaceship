#include "Turret.h"

#include "Bullet.h"
#include "Application.h"

#include <iostream>

Turret::Turret()
{
	setFillColor(sf::Color::Red);
	setOrigin(sf::Vector2f(m_BodySize.x / 2, m_BodySize.y / 2));
	setSize(m_BodySize);
	setPosition(m_StartPosition);
}

void Turret::Update()
{
	OnMousePressed();
	UpdateRotation();
}

void Turret::OnMousePressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_Timer.asSeconds() <= 0.f)
			ShootProjectile();

		m_Timer += Application::Get().GetDeltaTime();
		if (m_Timer.asSeconds() >= m_ShootingDelay)
			m_Timer = m_Timer.Zero;
	}
}

void Turret::ShootProjectile()
{
	float dx = Application::Get().GetMouseRelativeLocation().x - getPosition().x;
	float dy = Application::Get().GetMouseRelativeLocation().y - getPosition().y;
	Application::Get().GetCurrentLevel().Add(new Bullet(getPosition(), sf::Vector2f(dx, dy)));
}

void Turret::UpdateRotation()
{
	sf::Vector2i mouseLocation = Application::Get().GetMouseRelativeLocation();
	float dx = -mouseLocation.x + getPosition().x;
	float dy = -mouseLocation.y + getPosition().y;
	sf::Angle rotation = sf::degrees(atan2(dy, dx) * 180.0f / 3.14159265f);
	setRotation(rotation);
}
