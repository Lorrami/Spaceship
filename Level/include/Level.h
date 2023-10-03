#pragma once

#include "Turret.h"

enum class GameState
{
	MainMenu = -1,
	InProgress = 0,
	Win = 1,
	Loose = 2
};

class Level
{
private:
	sf::RenderWindow* m_CurrentWindow{};
	sf::Time m_DeltaTime{};
	sf::Time m_Timer{};
	float m_ShootingDelay = 1.f;
	Turret m_CurrentTurret{};
	GameState m_CurrentGameState = GameState::InProgress;

	void OnKeyboardPressed();
	void OnGameInProgress();

public:
	void Draw(sf::Time DeltaTime, sf::RenderWindow* WindowToDrawAt);

};