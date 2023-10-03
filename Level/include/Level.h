#pragma once

#include "Turret.h"
#include "Bullet.h"
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
	sf::Time m_DeltaTime{};
	sf::Time m_Timer{};
	float m_ShootingDelay = 1.f;
	GameState m_CurrentGameState = GameState::InProgress;
	
	std::vector<DrawableObject*> m_DrawableObjects{};
	std::vector<DrawableObject*> m_PendingAddObjects{};
	std::vector<DrawableObject*> m_PendingRemoveObjects{};

	void OnMousePressed();
	void OnGameInProgress();

public:
	Level();
	void Add(DrawableObject* ObjectToAdd);
	void Remove(DrawableObject* ObjectToRemove);
	void SpawnProjectile();
	void UpdateGameState();
	void Update(sf::Time DeltaTime);
	void Draw(sf::RenderWindow* WindowToDrawAt);

};