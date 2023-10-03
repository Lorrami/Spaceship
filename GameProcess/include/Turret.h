#pragma once

#include "DrawableObject.h"

class Turret : public DrawableObject
{
public:
	Turret();
	virtual void Update(const sf::Vector2i& MousePosition) override;
	void UpdateRotation(const sf::Vector2i& MousePosition);

private:
	const sf::Vector2f m_BodySize{100.f, 100.f};

};