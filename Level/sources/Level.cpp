#include "Level.h"

#include <iostream>

void Level::SpawnProjectile()
{
	m_DrawableObjects.push_back(new Bullet());
}

void Level::OnMousePressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_Timer += m_DeltaTime;
		if (m_Timer.asSeconds() >= m_ShootingDelay)
		{
			SpawnProjectile();
			m_Timer = m_Timer.Zero;
		}
	}
}

void Level::OnGameInProgress()
{
	OnMousePressed();
}

void Level::UpdateGameState()
{
	switch (m_CurrentGameState)
	{
	case GameState::MainMenu:
		// show main menu
		break;
	case GameState::InProgress:
		OnGameInProgress();
		break;
	case GameState::Win:
		// show win screen
		break;
	case GameState::Loose:
		// show loose screen
		break;
	}
}

void Level::Update(sf::Time DeltaTime)
{
	m_DeltaTime = DeltaTime;

	UpdateGameState();

	for (auto* ObjectToUpdate : m_DrawableObjects)
	{
		ObjectToUpdate->Update(sf::Mouse::getPosition(*m_CurrentWindow));
	}

	m_DrawableObjects.insert(m_DrawableObjects.end(), m_PendingAddObjects.begin(), m_PendingAddObjects.end());
	m_PendingAddObjects.clear();

	for (DrawableObject* Object : m_PendingRemoveObjects)
	{
		std::iterator smth = remove(m_DrawableObjects.begin, m_DrawableObjects.end, Object);
	}
	m_PendingRemoveObjects.clear();
}

void Level::Draw(sf::RenderWindow* WindowToDrawAt)
{
	m_CurrentWindow = WindowToDrawAt;
	for (auto* ObjectToDraw : m_DrawableObjects)
	{
		m_CurrentWindow->draw(*ObjectToDraw);
	}
}

void Level::Remove(DrawableObject* ObjectToRemove)
{
	m_PendingRemoveObjects.push_back(ObjectToRemove);
}

void Level::Add(DrawableObject* ObjectToAdd)
{
	m_PendingAddObjects.push_back(ObjectToAdd);
}

Level::Level()
{
	m_DrawableObjects.push_back(new Turret());
}