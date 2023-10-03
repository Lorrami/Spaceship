#include "Application.h"

Application* Application::s_Instance = nullptr;

void Application::HandleEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_Window.close();
    }
}

void Application::Run()
{
    sf::Clock clock;
	while (m_Window.isOpen())
	{
        sf::Time deltaTime = clock.restart();
        HandleEvents();
        
        m_Window.clear(sf::Color::Black);
        m_Level.Draw(&m_Window);
        m_Window.display();

        m_Level.Update(deltaTime);
	}
}

void Application::InitWindow()
{
    m_Window.create(sf::VideoMode(sf::Vector2u(m_WindowLength, m_WindowHeight)), "Zuma", sf::Style::Close);
}

Application& Application::Get()
{
    if (s_Instance == nullptr)
        s_Instance = new Application();
    return *s_Instance;
}

void Application::Start()
{
    InitWindow();
    Run();
}