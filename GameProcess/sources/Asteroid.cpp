#include "Asteroid.h"

#include "Application.h"
#include "Bullet.h"

Asteroid::Asteroid(const float speed, const float bodySize, const sf::Vector2f& position, const sf::Angle& rotation, const sf::Vector2f direction)
{
	m_Speed = speed;
	m_Direction = direction;
	setPosition(position);
	setRotation(rotation);
	setOrigin(sf::Vector2f(bodySize / 2, bodySize / 2));
	setSize(sf::Vector2f(bodySize, bodySize));
}

void Asteroid::Update()
{
	if (IsOnScreen())
	{
		CheckBulletCollision();
		CheckPlayerCollision();
		Move(Application::Get().GetDeltaTime(), m_Direction, m_Speed);
	}
	else
	{
		Application::Get().GetCurrentLevel().Remove(this);
	}
}

void Asteroid::CheckBulletCollision()
{
	auto currentLevel = Application::Get().GetCurrentLevel();
	auto objectsOnScreen = currentLevel.GetAllObjectsOnScreen();
	for (auto* objectOnScreen : objectsOnScreen)
	{
		if (auto* bullet = dynamic_cast<Bullet*>(objectOnScreen))
		{
			if (getGlobalBounds().findIntersection(bullet->getGlobalBounds()))
			{
				Application::Get().GetCurrentLevel().OnDrawableObjectHit(0, this, this);
			}
		}
	}
}

void Asteroid::CheckPlayerCollision()
{
	Spaceship* player = dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer());
	if (!player)
		return;

	if (getGlobalBounds().findIntersection(player->getGlobalBounds()))
	{
		Application::Get().GetCurrentLevel().OnDrawableObjectHit(m_Damage, player, this);
	}
}
