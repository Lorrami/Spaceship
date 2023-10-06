#pragma once

#include "UI.h"

class MainMenuUI : public UI
{
public:
	void Init();

	virtual void Update() override;

private:
	sf::Font* m_Font = new sf::Font();
	sf::Text* m_PlayerScoreText = nullptr;
	sf::Text* m_WelcomeText = nullptr;
	sf::Texture* m_StartButtonTexture = new sf::Texture();
	sf::RectangleShape* m_StartButton = new sf::RectangleShape();

	bool CheckStartButton();
};