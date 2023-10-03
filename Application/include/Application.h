#pragma once

#include "Level.h"

class Application
{
public:
	static Application* s_Instance;

	void Start();
	static Application& Get();

private:
	const unsigned int m_WindowLength = 1080;
	const unsigned int m_WindowHeight = 720;

protected:
	sf::RenderWindow m_Window{};
	Level m_Level{};

private:
	void InitWindow();
	void Run();
	void HandleEvents();
};