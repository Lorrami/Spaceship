#include "MainMenuUI.h"

#include "Application.h"

#include <iostream>
#include <string>

MainMenuUI::MainMenuUI()
{
	/*if (m_Font.loadFromFile("../../Resources/Text1.ttf"))
	{
		m_PlayerScoreText = new sf::Text(m_Font, std::to_string(Application::Get().GetCurrentLevel().GetCurrentScore()));
	}*/

	m_StartButton.setSize(sf::Vector2f(300, 100));
	m_StartButton.setOrigin(sf::Vector2f(m_StartButton.getSize().x / 2, m_StartButton.getSize().y / 2));
	m_StartButton.setPosition(sf::Vector2f(540.f, 360.f));
	m_StartButton.setFillColor(sf::Color::Red);
}

void MainMenuUI::Update()
{
	Application::Get().GetCurrentWindow().draw(m_StartButton);
	if (CheckStartButton())
	{
		Application::Get().GetCurrentLevel().OnGameStarted();
	}
}

bool MainMenuUI::CheckStartButton()
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return false;

	if (m_StartButton.getGlobalBounds().contains(
		sf::Vector2f((float)Application::Get().GetMouseRelativeLocation().x,
			(float)Application::Get().GetMouseRelativeLocation().y)))
	{
		return true;
	}
	return false;
}
