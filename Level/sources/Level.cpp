#include "Level.h"

#include <iostream>

void Level::OnKeyboardPressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_Timer += m_DeltaTime;
		if (m_Timer.asSeconds() >= m_ShootingDelay)
		{
			m_CurrentTurret.Shoot();
			m_Timer = m_Timer.Zero;
		}
	}
}

void Level::OnGameInProgress()
{
	m_CurrentTurret.UpdateRotation(sf::Mouse::getPosition(*m_CurrentWindow));

	m_CurrentWindow->draw(m_CurrentTurret);
}

void Level::Draw(sf::Time DeltaTime, sf::RenderWindow* WindowToDrawAt)
{
	m_CurrentWindow = WindowToDrawAt;
	m_DeltaTime = DeltaTime;
	OnKeyboardPressed();
	switch (m_CurrentGameState)
	{
	case GameState::MainMenu:
		// show main menu
		break;
	case GameState::InProgress:
		// update game progress
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