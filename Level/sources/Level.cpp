#include "Level.h"

#include <iostream>

Level::Level()
{
	m_DrawableObjects.push_back(new Spaceship());
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

void Level::OnGameInProgress()
{
	// on game on progress
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

