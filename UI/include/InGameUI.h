#pragma once

#include "UI.h"

class InGameUI : public UI
{
public:
	void Init();

	virtual void Update() override;

private:
	sf::Font* m_Font = new sf::Font();
	sf::Text* m_PlayerScoreText = nullptr;
	sf::Text* m_PlayerHealthText = nullptr;
	sf::Text* m_Timer = nullptr;

	void InitTexts();
	void InitPlayerScore();
	void InitPlayerHealth();
	void InitTimer();
	std::string FormatTimer(float time, int digits);
	void UpdateTimer();

};