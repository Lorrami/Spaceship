#pragma once

#include "UI.h"

class MainMenuUI : public UI
{
public:
	MainMenuUI();

	virtual void Update() override;

private:
	sf::Font m_Font{};
	sf::Text* m_PlayerScoreText = nullptr;
	sf::RectangleShape m_StartButton = sf::RectangleShape();

	bool CheckStartButton();
};