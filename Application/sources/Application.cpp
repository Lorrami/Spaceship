#include "Application.h"

Application* Application::s_Instance = nullptr;

void Application::Start()
{
    InitWindow();
    Run();
}

void Application::InitWindow()
{
    m_Window.create(sf::VideoMode(sf::Vector2u(m_WindowLength, m_WindowHeight)), "Zuma", sf::Style::Close);
}

void Application::Run()
{
    sf::Clock clock;
    while (m_Window.isOpen())
    {
        m_MouseLocation = sf::Mouse::getPosition(m_Window);
        m_DeltaTime = clock.restart();

        HandleEvents();

        m_Window.clear(sf::Color::Black);
        m_Level.Update();

        m_Window.display();
    }
}

void Application::HandleEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_Window.close();
    }
}

Application& Application::Get()
{
    if (s_Instance == nullptr)
        s_Instance = new Application();
    return *s_Instance;
}