#include "Bullet.h"

#include <iostream>

void Bullet::Update(const sf::Vector2i& MousePosition)
{
	std::cout << "Update bullet" << std::endl;
}

Bullet::Bullet()
{
	setSize(sf::Vector2f(20.f, 20.f));
	setOrigin(sf::Vector2f(10.f, 10.f));
	setFillColor(sf::Color::Blue);
}