#include "Level.h"
#include "Level.h"
#include "Level.h"@

#include "Application.h"
#include "Asteroid.h"
#include <iostream>

void Level::Init()
{
	m_Player = new Spaceship();
	m_MainMenuUI->Init();
}

void Level::UpdateGameState()
{
	switch (m_CurrentGameState)
	{
	case GameState::MainMenu:
		OnGameInMainMenu();
		break;
	case GameState::InProgress:
		OnGameInProgress();
		break;
	case GameState::Win:
		OnWin();
		break;
	case GameState::Loose:
		OnLoose();
		break;
	}
}

void Level::OnGameStarted()
{
	SpawnDangerZones();
	SpawnPlayer();
	m_CurrentGameState = GameState::InProgress;
	m_InGameUI->Init();
}

void Level::OnGameInMainMenu()
{
	m_MainMenuUI->Update();
}

void Level::SpawnPlayer()
{
	m_DrawableObjects.push_back(m_Player);
}

void Level::SpawnDangerZones()
{
	m_PendingAddObjects.push_back(new DangerZone(10.f, 150.f, sf::Vector2f(400.f, 50.f), sf::Color::Red));
	m_PendingAddObjects.push_back(new DangerZone(15.f, 200.f, sf::Vector2f(100.f, 300.f), sf::Color::Yellow));
	m_PendingAddObjects.push_back(new DangerZone(20.f, 300.f, sf::Vector2f(750.f, 400.f), sf::Color::Green));
}

void Level::OnGameInProgress()
{
	SpawnAsteroids();
	CheckWinLooseConditions();
	Draw();
	m_InGameUI->Update();
}

void Level::CheckWinLooseConditions()
{
	if (m_ZonesCount <= 0)
	{
		m_CurrentGameState = GameState::Win;
		return;
	}

	if (!dynamic_cast<Spaceship*>(m_Player)->PlayerHealthComponent.IsAlive())
	{
		m_CurrentGameState = GameState::Loose;
		return;
	}
}

void Level::SpawnAsteroids()
{
	if (m_TimeForAsteroids <= 0)
	{
		AdjustAsteroidsParameters();

		float newSpeed = (float)(std::rand() % (m_AsteroidSpeedRange.y - m_AsteroidSpeedRange.x + 1) + m_AsteroidSpeedRange.x);
		float newSize = (float)(std::rand() % (m_AsteroidSizeRange.y - m_AsteroidSizeRange.x + 1) + m_AsteroidSizeRange.x);

		Add(new Asteroid(newSpeed, newSize));

		m_TimeForAsteroids = static_cast<float>(std::rand() % 151 + 10) / 100;
	}
	else
	{
		m_TimeForAsteroids -= Application::Get().GetDeltaTime().asSeconds();
	}
}

void Level::AdjustAsteroidsParameters()
{
	for (auto* drawableObject : m_DrawableObjects)
	{
		if (DangerZone* zone = dynamic_cast<DangerZone*>(drawableObject))
		{
			if (zone->GetPlayerStateInDangerZone())
			{
				m_IsPlayerInDangerZone = true;
				m_AsteroidSpeedRange = m_AsteroidSpeedRangeActive;
				return;
			}
			else
			{
				m_IsPlayerInDangerZone = false;
				m_AsteroidSpeedRange = m_AsteroidSpeedRangeUnactive;
			}
		}
	}
}

void Level::ZonePassed()
{
	m_IsPlayerInDangerZone = false;
	m_ZonesCount--;
}

void Level::OnDrawableObjectHit(const int damage, DrawableObject* hitObject, DrawableObject* hitCauser)
{
	Remove(hitCauser);
	if (dynamic_cast<Spaceship*>(hitObject))
	{
		m_Player->PlayerHealthComponent.TakeDamage(damage);
	}
	else if (Asteroid* asteroid = dynamic_cast<Asteroid*>(hitObject))
	{
		Remove(asteroid);
		m_Player->PlayerScoreComponent.AddScore(m_PointsPerAsteroid);
	}
}

void Level::OnWin()
{
	std::cout << "Win\n";

	m_CurrentGameState = GameState::MainMenu;
	ClearLevel();
}

void Level::OnLoose()
{
	std::cout << "Loose\n";
	
	ClearLevel();
	m_CurrentGameState = GameState::MainMenu;
}

void Level::ClearLevel()
{
	m_IsPlayerInDangerZone = false;
	m_Player = new Spaceship();
	for (auto DrawableObject : m_DrawableObjects)
	{
		Remove(DrawableObject);
	}
}

void Level::Update()
{
	UpdateGameState();

	for (auto* ObjectToUpdate : m_DrawableObjects)
	{
		ObjectToUpdate->Update();
	}

	m_DrawableObjects.insert(m_DrawableObjects.end(), m_PendingAddObjects.begin(), m_PendingAddObjects.end());
	m_PendingAddObjects.clear();

	for (DrawableObject* ObjectToRemove : m_PendingRemoveObjects)
	{
		m_DrawableObjects.erase(std::remove(m_DrawableObjects.begin(), m_DrawableObjects.end(), ObjectToRemove), m_DrawableObjects.end());
	}
	m_PendingRemoveObjects.clear();
}

void Level::Draw()
{
	m_CurrentWindow = &(Application::Get().GetCurrentWindow());
	for (auto* ObjectToDraw : m_DrawableObjects)
	{
		m_CurrentWindow->draw(*ObjectToDraw);
	}
}

void Level::Add(DrawableObject* objectToAdd)
{
	m_PendingAddObjects.push_back(objectToAdd);
}

void Level::Remove(DrawableObject* objectToRemove)
{
	m_PendingRemoveObjects.push_back(objectToRemove);
}

