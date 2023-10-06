#include "InGameUI.h"

#include "Application.h"

#include <iostream>
#include <string>

void InGameUI::Init()
{
	InitTexts();
}

void InGameUI::InitTexts()
{
	if (m_Font->loadFromFile("../../../Resources/Text1.ttf"))
	{
		m_PlayerScoreText = new sf::Text(*m_Font, "Score: " + std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerScoreComponent.GetCurrentScore()));
		m_PlayerScoreText->setPosition(sf::Vector2f(10.f, 10.f));

		m_PlayerHealthText = new sf::Text(*m_Font, "Health: " +
			std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerHealthComponent.GetCurrentHealth()) +
			"/" +
			std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerHealthComponent.GetMaxHealth()));
		sf::FloatRect textRect = m_PlayerHealthText->getLocalBounds();
		m_PlayerHealthText->setPosition(sf::Vector2f(
			Application::Get().GetWindowSize().x - (textRect.left + textRect.width) - 10.f, 10.f));
	}
}

void InGameUI::Update()
{
	m_PlayerScoreText->setString("Score: " + std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerScoreComponent.GetCurrentScore()));
	m_PlayerHealthText->setString("Health: " +
							std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerHealthComponent.GetCurrentHealth()) + 
							"/" + 
							std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerHealthComponent.GetMaxHealth()));
	
	Application::Get().GetCurrentWindow().draw(*m_PlayerScoreText);
	Application::Get().GetCurrentWindow().draw(*m_PlayerHealthText);
}