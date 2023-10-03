#include "Bullet.h"
#include <vector>

class Turret : public sf::RectangleShape
{
public:
	Turret();
	void Shoot();
	void UpdateRotation(const sf::Vector2i& MousePosition);

private:
	std::vector<Bullet> m_Bullets{};
	const sf::Vector2f m_BodySize{100.f, 100.f};

};