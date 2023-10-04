#pragma once

#include "Spaceship.h"
#include "DangerZone.h"

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
	GameState m_CurrentGameState = GameState::MainMenu;
	int m_ZonesCount = 3;
	int m_PointsPerZone = 100;
	bool m_IsPlayerInDangerZone = false;
	
	Spaceship* m_Player{};

	std::vector<DrawableObject*> m_DrawableObjects{};
	std::vector<DrawableObject*> m_PendingAddObjects{};
	std::vector<DrawableObject*> m_PendingRemoveObjects{};

	void OnGameInProgress();
	void OnGameStarted();
	void SpawnPlayer();
	void SpawnDangerZones();
	void OnGameInMainMenu();
	void OnWin();
	void OnLoose();
	void ClearLevel();

public:
	Level();
	void Add(DrawableObject* objectToAdd);
	void Remove(DrawableObject* objectToRemove);
	void UpdateGameState();
	void Update();
	void Draw(sf::RenderWindow* windowToDrawAt);

	void ZonePassed();

	DrawableObject* GetPlayer() { return m_Player; }
	bool GetPlayerStateInDangerZone() const { return m_IsPlayerInDangerZone; }
	void SetPlayerStateInDangerZone(const bool newState) { m_IsPlayerInDangerZone = newState; }

};