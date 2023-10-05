#include "Spaceship.h"

#include "Bullet.h"
#include "Application.h"

#include <iostream>

Spaceship::Spaceship()
{
	setFillColor(sf::Color::Red);
	setOrigin(sf::Vector2f(m_BodySize.x / 2, m_BodySize.y / 2));
	setSize(m_BodySize);
	setPosition(m_StartPosition);

	PlayerHealthComponent.SetMaxHealth(100);
}

void Spaceship::Update()
{
	OnMousePressed();
	OnKeyboardPressed();
	UpdateRotation();
}

void Spaceship::OnKeyboardPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Move(sf::Vector2f(0.f, -1.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Move(sf::Vector2f(0.f, 1.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Move(sf::Vector2f(-1.f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Move(sf::Vector2f(1.f, 0.f));
	}
}

void Spaceship::OnMousePressed()
{
	if (Application::Get().GetCurrentLevel().GetCurrentGameState() != GameState::InProgress)
		return;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_Timer.asSeconds() <= 0.f)
			ShootProjectile();

		m_Timer += Application::Get().GetDeltaTime();
		if (m_Timer.asSeconds() >= m_ShootingDelay)
			m_Timer = m_Timer.Zero;
	}
}

void Spaceship::Move(const sf::Vector2f direction)
{
	sf::Vector2f prevLocation = getPosition();
	const sf::Time deltaTime = Application::Get().GetDeltaTime();
	sf::Vector2i windowSize = Application::Get().GetWindowSize();

	sf::Vector2f targetLocation = sf::Vector2f(prevLocation.x + direction.x * m_Speed * deltaTime.asSeconds(), prevLocation.y + direction.y * m_Speed * deltaTime.asSeconds());

	if (targetLocation.x < m_BodySize.x / 2 ||
		targetLocation.x > windowSize.x - m_BodySize.x / 2 ||
		targetLocation.y < m_BodySize.y / 2 ||
		targetLocation.y > windowSize.y - m_BodySize.y / 2)
		return;

	setPosition(targetLocation);
}

void Spaceship::ShootProjectile()
{
	float dx = Application::Get().GetMouseRelativeLocation().x - getPosition().x;
	float dy = Application::Get().GetMouseRelativeLocation().y - getPosition().y;
	Application::Get().GetCurrentLevel().Add(new Bullet(getPosition(), sf::Vector2f(dx, dy)));
}

void Spaceship::UpdateRotation()
{
	sf::Vector2i mouseLocation = Application::Get().GetMouseRelativeLocation();
	float dx = -mouseLocation.x + getPosition().x;
	float dy = -mouseLocation.y + getPosition().y;
	sf::Angle rotation = sf::degrees(atan2(dy, dx) * 180.0f / 3.14159265f);
	setRotation(rotation);
}
