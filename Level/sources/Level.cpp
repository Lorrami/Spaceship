#include "Level.h"

#include <iostream>

Level::Level()
{
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

void Level::OnGameInMainMenu()
{
	// button start pressed =>
	OnGameStarted();
}

void Level::OnGameStarted()
{
	SpawnDangerZones();
	SpawnPlayer();
	m_CurrentGameState = GameState::InProgress;
}

void Level::SpawnPlayer()
{
	m_Player = new Spaceship();
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
	//TODO: spawn asteroids
	if (!m_Player->HealthComponent.IsAlive())
	{
		m_CurrentGameState = GameState::Loose;
		return;
	}
	if (m_ZonesCount <= 0)
	{
		m_CurrentGameState = GameState::Win;
		return;
	}
}

void Level::ZonePassed()
{
	m_ZonesCount--;
	//TODO: add player score
}

void Level::OnWin()
{
	std::cout << "Win\n";
}

void Level::OnLoose()
{
	std::cout << "Loose\n";
	
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

	for (DrawableObject* ObjectToRemove: m_PendingRemoveObjects)
	{
		m_DrawableObjects.erase(std::remove(m_DrawableObjects.begin(), m_DrawableObjects.end(), ObjectToRemove), m_DrawableObjects.end());
	}
	m_PendingRemoveObjects.clear();
}

void Level::Draw(sf::RenderWindow* windowToDrawAt)
{
	m_CurrentWindow = windowToDrawAt;
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

