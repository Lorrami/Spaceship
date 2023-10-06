#pragma once

#include "UI.h"

class MainMenuUI : public UI
{
public:
	MainMenuUI();

	virtual void Update() override;

private:
	sf::Font* m_Font = nullptr;
	sf::Text* m_PlayerScoreText = nullptr;
	sf::Text* m_WelcomeText = nullptr;
	sf::Texture* m_StartButtonTexture = nullptr;
	sf::RectangleShape* m_StartButton = new sf::RectangleShape();

	bool CheckStartButton();
};