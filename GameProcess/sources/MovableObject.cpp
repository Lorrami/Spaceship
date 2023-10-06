#include "MovableObject.h"

#include "Application.h"

bool MovableObject::IsOnScreen()
{
	sf::Vector2i windowSize = Application::Get().GetWindowSize();
	sf::Vector2f bodySize = getSize();
	sf::Vector2f position = getPosition();
	if (position.x > -bodySize.x / 2 &&
		position.x < windowSize.x + bodySize.x / 2 &&
		position.y > -bodySize.y / 2 &&
		position.y < windowSize.y + bodySize.y / 2)
		return true;
	return false;
}

void MovableObject::Move(const sf::Time deltaTime, const sf::Vector2f& direction, const float speed)
{
	sf::Vector2f prevLocation = getPosition();
	setPosition(sf::Vector2f(prevLocation.x + direction.x * speed * deltaTime.asSeconds(), prevLocation.y + direction.y * speed * deltaTime.asSeconds()));
}
