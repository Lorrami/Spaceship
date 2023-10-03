#pragma once

#include "Spaceship.h"

#include <vector>

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
	GameState m_CurrentGameState = GameState::InProgress;
	
	std::vector<DrawableObject*> m_DrawableObjects{};
	std::vector<DrawableObject*> m_PendingAddObjects{};
	std::vector<DrawableObject*> m_PendingRemoveObjects{};

	void OnGameInProgress();

public:
	Level();
	void Add(DrawableObject* objectToAdd);
	void Remove(DrawableObject* objectToRemove);
	void UpdateGameState();
	void Update();
	void Draw(sf::RenderWindow* windowToDrawAt);

};