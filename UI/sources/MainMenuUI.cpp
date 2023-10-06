#include "MainMenuUI.h"

#include "Application.h"

#include <iostream>
#include <string>

MainMenuUI::MainMenuUI()
{
	m_Font = new sf::Font();
	m_StartButtonTexture = new sf::Texture();

	if (m_Font->loadFromFile("../../../Resources/Text1.ttf"))
	{
		m_PlayerScoreText = new sf::Text(*m_Font, "Score: " + std::to_string(Application::Get().GetCurrentLevel().GetCurrentScore()));
		m_PlayerScoreText->setPosition(sf::Vector2f(10.f, 10.f));

		m_WelcomeText = new sf::Text(*m_Font, "Welcome  to\n  SPACESHIP");
		m_WelcomeText->setCharacterSize(40);
		sf::FloatRect textRect = m_WelcomeText->getLocalBounds();
		m_WelcomeText->setOrigin(sf::Vector2f(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f));
		m_WelcomeText->setPosition(sf::Vector2f(540.f, 200.f));
	}
	
	if (m_StartButtonTexture->loadFromFile("../../../Resources/StartButton.png"))
	{
		m_StartButton->setTexture(m_StartButtonTexture, true);
		//m_StartButton->setSize(sf::Vector2f(300, 100));
		m_StartButton->setOrigin(sf::Vector2f(m_StartButton->getSize().x / 2, m_StartButton->getSize().y / 2));
		m_StartButton->setPosition(sf::Vector2f(540.f, 360.f));
	}
}

void MainMenuUI::Update()
{
	if (CheckStartButton())
	{
		Application::Get().GetCurrentLevel().OnGameStarted();
		return;
	}

	Application::Get().GetCurrentWindow().draw(*m_StartButton);
	if (!m_PlayerScoreText || !m_WelcomeText)
		return;

	Application::Get().GetCurrentWindow().draw(*m_PlayerScoreText);
	Application::Get().GetCurrentWindow().draw(*m_WelcomeText);
}

bool MainMenuUI::CheckStartButton()
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return false;

	if (m_StartButton->getGlobalBounds().contains(
		sf::Vector2f((float)Application::Get().GetMouseRelativeLocation().x,
			(float)Application::Get().GetMouseRelativeLocation().y)))
	{
		return true;
	}
	return false;
}
