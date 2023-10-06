#include "MainMenuUI.h"

#include "Application.h"

#include <string>

void MainMenuUI::Init()
{
	InitTexts();
	InitStartButton();
	InitLeaveButton();
}

void MainMenuUI::InitTexts()
{
	if (m_Font->loadFromFile("Resources/Text1.ttf"))
	{
		m_PlayerScoreText = new sf::Text(*m_Font, "Max score: " + std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerScoreComponent.GetEarnedScore()));
		m_PlayerScoreText->setPosition(sf::Vector2f(10.f, 10.f));

		m_WelcomeText = new sf::Text(*m_Font, "Welcome  to\n  SPACESHIP");
		m_WelcomeText->setCharacterSize(40);
		sf::FloatRect textRect = m_WelcomeText->getLocalBounds();
		m_WelcomeText->setOrigin(sf::Vector2f(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f));
		m_WelcomeText->setPosition(sf::Vector2f(540.f, 300.f));
	}
}

void MainMenuUI::InitStartButton()
{
	if (m_StartButtonTexture->loadFromFile("Resources/StartButton.png"))
	{
		m_StartButton->setTexture(m_StartButtonTexture);
		m_StartButton->setSize(sf::Vector2f(230, 90));
		m_StartButton->setOrigin(sf::Vector2f(m_StartButton->getSize().x / 2, m_StartButton->getSize().y / 2));
		m_StartButton->setPosition(sf::Vector2f(540.f, 460.f));
	}
}

void MainMenuUI::InitLeaveButton()
{
	if (m_LeaveButtonTexture->loadFromFile("Resources/LeaveButton.png"))
	{
		m_LeaveButton->setTexture(m_LeaveButtonTexture);
		m_LeaveButton->setSize(sf::Vector2f(110, 90));
		m_LeaveButton->setOrigin(sf::Vector2f(m_LeaveButton->getSize().x / 2, m_LeaveButton->getSize().y / 2));
		m_LeaveButton->setPosition(sf::Vector2f(540.f, 560.f));
	}
}

void MainMenuUI::Update()
{
	if (CheckStartButton())
	{
		Application::Get().GetCurrentLevel().OnGameStarted();
		return;
	}
	else if (CheckLeaveButton())
	{
		Application::Get().Stop();
		return;
	}

	Application::Get().GetCurrentWindow().draw(*m_StartButton);
	Application::Get().GetCurrentWindow().draw(*m_LeaveButton);
	Application::Get().GetCurrentWindow().draw(*m_PlayerScoreText);
	Application::Get().GetCurrentWindow().draw(*m_WelcomeText);
}

bool MainMenuUI::CheckStartButton()
{
	if (Application::Get().GetIsMouseLocked())
		return false;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Application::Get().SetMouseLocked(true);
		if (m_StartButton->getGlobalBounds().contains(
			sf::Vector2f((float)Application::Get().GetMouseRelativeLocation().x,
				(float)Application::Get().GetMouseRelativeLocation().y)))
		{
			return true;
		}
	}
	return false;
}

bool MainMenuUI::CheckLeaveButton()
{
	if (Application::Get().GetIsMouseLocked())
		return false;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Application::Get().SetMouseLocked(true);
		if (m_LeaveButton->getGlobalBounds().contains(
			sf::Vector2f((float)Application::Get().GetMouseRelativeLocation().x,
				(float)Application::Get().GetMouseRelativeLocation().y)))
		{
			return true;
		}
	}
	return false;

}
