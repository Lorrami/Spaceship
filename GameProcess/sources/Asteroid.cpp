#include "Asteroid.h"

#include "Application.h"
#include "Bullet.h"

Asteroid::Asteroid(const float speed, const float bodySize)
{
	m_Speed = speed;
	setPosition(CalculatePosition());
	setOrigin(sf::Vector2f(bodySize / 2, bodySize / 2));
	setSize(sf::Vector2f(bodySize, bodySize));
	m_Direction = CalculateDirection();
}

void Asteroid::Init()
{
	if (m_Texture->loadFromFile("../../../Resources/Asteroid.png"))
	{
		setTexture(m_Texture);
	}
}

sf::Vector2f& Asteroid::CalculateDirection()
{
	if (Application::Get().GetCurrentLevel().GetPlayerStateInDangerZone())
	{
		return GetNormalToPlayer();
	}
	else
	{
		float xBuffer = static_cast<float>(std::rand()) / RAND_MAX * 1.0 - 0.5;
		float yBuffer = static_cast<float>(std::rand()) / RAND_MAX * 1.0 - 0.5;

		return GetNormalToPlayer() + sf::Vector2f{ xBuffer, yBuffer };
	}
}

sf::Vector2f& Asteroid::GetNormalToPlayer()
{
	DrawableObject* player = Application::Get().GetCurrentLevel().GetPlayer();
	sf::Vector2f normal = (player->getPosition() - getPosition()).normalized();
	return normal;
}

sf::Vector2f& Asteroid::CalculatePosition()
{
	float targetX{}, targetY{};

	int choiceSide = std::rand() % 2;
	if (choiceSide == 0) //spawn on random X on top or bottom
	{
		int minX = (int)(getSize().x / 2);
		int maxX = (int)(Application::Get().GetWindowSize().x - getSize().x / 2);
		targetX = (float)(std::rand() % (maxX - minX + 1) + minX);

		int choice = std::rand() % 2;
		if (choice == 0) // spawn on top
		{
			targetY = -getSize().y;
		}
		else // spawn on bottom
		{
			targetY = Application::Get().GetWindowSize().y + getSize().y;
		}
	}
	else //spawn on random Y on left or right
	{
		int minY = (int)(getSize().y / 2);
		int maxY = (int)(Application::Get().GetWindowSize().y - getSize().y / 2);
		targetY = (float)(std::rand() % (maxY - minY + 1) + minY);

		int choice = std::rand() % 2;
		if (choice == 0) // spawn on left
		{
			targetX = -getSize().x;
		}
		else // spawn on right
		{
			targetX = Application::Get().GetWindowSize().x + getSize().x;
		}
	}

	return sf::Vector2f(targetX, targetY);
}

void Asteroid::Update()
{
	if (IsOnScreen())
	{
		CheckBulletCollision();
		CheckPlayerCollision();
		Move(Application::Get().GetDeltaTime(), m_Direction, m_Speed);
		setRotation(CalculateRotation());
	}
	else
	{
		Application::Get().GetCurrentLevel().Remove(this);
	}
}

sf::Angle& Asteroid::CalculateRotation()
{
	sf::Angle previousRotation = getRotation();
	return sf::degrees(previousRotation.asDegrees() + m_Speed / m_RotationCoef * Application::Get().GetDeltaTime().asSeconds());
}

void Asteroid::CheckBulletCollision()
{
	auto objectsOnScreen = Application::Get().GetCurrentLevel().GetAllObjectsOnScreen();
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
