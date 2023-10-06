#include "InGameUI.h"

#include "Application.h"

#include <sstream>
#include <string>

void InGameUI::Init()
{
	InitTexts();
}

void InGameUI::InitTexts()
{
	if (m_Font->loadFromFile("../../../Resources/Text1.ttf"))
	{
		InitPlayerScore();
		InitPlayerHealth();
		InitTimer();
	}
}

void InGameUI::InitPlayerScore()
{
	m_PlayerScoreText = new sf::Text(*m_Font, "Score: " + std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerScoreComponent.GetCurrentScore()));
	m_PlayerScoreText->setPosition(sf::Vector2f(10.f, 10.f));
}

void InGameUI::InitPlayerHealth()
{
	m_PlayerHealthText = new sf::Text(*m_Font, "Health: " +
		std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerHealthComponent.GetCurrentHealth()) +
		"/" +
		std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerHealthComponent.GetMaxHealth()));
	sf::FloatRect textRect = m_PlayerHealthText->getLocalBounds();
	m_PlayerHealthText->setPosition(sf::Vector2f(
		Application::Get().GetWindowSize().x - (textRect.left + textRect.width) - 10.f, 10.f));
}

void InGameUI::InitTimer()
{
	m_Timer = new sf::Text(*m_Font, "TIMER");
	sf::FloatRect timerRect = m_Timer->getLocalBounds();
	m_Timer->setPosition(sf::Vector2f(
		Application::Get().GetWindowSize().x / 2 - (timerRect.left + timerRect.width), 10.f));
	std::setprecision(2);
}

void InGameUI::Update()
{
	m_PlayerScoreText->setString("Score: " + std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerScoreComponent.GetCurrentScore()));
	m_PlayerHealthText->setString("Health: " +
							std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerHealthComponent.GetCurrentHealth()) + 
							"/" + 
							std::to_string(dynamic_cast<Spaceship*>(Application::Get().GetCurrentLevel().GetPlayer())->PlayerHealthComponent.GetMaxHealth()));

	UpdateTimer();

	Application::Get().GetCurrentWindow().draw(*m_PlayerScoreText);
	Application::Get().GetCurrentWindow().draw(*m_PlayerHealthText);
}

void InGameUI::UpdateTimer()
{
	if (Application::Get().GetCurrentLevel().GetPlayerStateInDangerZone())
	{
		float timer = Application::Get().GetCurrentLevel().GetZoneTimer();
		m_Timer->setString(FormatTimer(timer, 4));
		Application::Get().GetCurrentWindow().draw(*m_Timer);
	}
}

std::string InGameUI::FormatTimer(float time, int digits)
{
	std::ostringstream ss;
	ss.precision(digits);
	ss << time;
	return ss.str();
}