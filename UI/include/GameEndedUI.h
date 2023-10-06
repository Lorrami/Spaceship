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
	//sf::Texture* m_StartButtonTexture = new sf::Texture();
	//sf::Texture* m_LeaveButtonTexture = new sf::Texture();
	//sf::RectangleShape* m_StartButton = new sf::RectangleShape();
	//sf::RectangleShape* m_LeaveButton = new sf::RectangleShape();

	void InitTexts();
	void InitTextsForWin();
	void InitTextsForLoose();
	void InitTimer();
	std::string FormatTimer(float time, int digits, bool includeMinutes);
	//void InitStartButton();
	//void InitLeaveButton();

	//bool CheckStartButton();
	//bool CheckLeaveButton();
};