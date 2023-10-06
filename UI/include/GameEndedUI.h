#pragma once

#include "UI.h"

class GameEndedUI : public UI
{
public:
	void Init(const bool gameState);

	virtual void Update() override;

private:
	bool m_CurrentState = false;
	sf::Font* m_Font = new sf::Font();
	sf::Text* m_PlayerScoreText = nullptr;
	sf::Text* m_ResultText = nullptr;
	sf::Text* m_GlobalTimer = nullptr;
	sf::Texture* m_ReturnButtonTexture = new sf::Texture();
	sf::RectangleShape* m_ReturnButton = new sf::RectangleShape();

	void InitTexts();
	void InitTextsForWin();
	void InitTextsForLoose();
	void InitTimer();
	void InitMainMenuButton();
	std::string FormatTimer(float time, int digits);

	bool CheckReturnButton();
};