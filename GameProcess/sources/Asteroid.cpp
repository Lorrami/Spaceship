#include "Asteroid.h"

#include "Application.h"
#include "Bullet.h"

Asteroid::Asteroid(const float speed, const float bodySize)
{
	m_Speed = speed;
	m_Direction = CalculateDirection(getPosition());

	setOrigin(sf::Vector2f(bodySize / 2, bodySize / 2));
	setSize(sf::Vector2f(bodySize, bodySize));
	setRotation(CalculateRotation());

	//////
	//TODO: random spawn for asteroids
	//////
}

sf::Angle& Asteroid::CalculateRotation()
{
	DrawableObject* player = Application::Get().GetCurrentLevel().GetPlayer();
	float dx = -player->getPosition().x + getPosition().x;
	float dy = -player->getPosition().y + getPosition().y;
	return sf::degrees(atan2(dy, dx) * 180.0f / 3.14159265f);
}

sf::Vector2f& Asteroid::CalculateDirection(const sf::Vector2f& location)
{
	DrawableObject* player = Application::Get().GetCurrentLevel().GetPlayer();
	sf::Vector2f normal = (player->getPosition() - location).normalized();
	return normal;
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
