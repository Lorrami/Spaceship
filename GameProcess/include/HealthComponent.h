#pragma once

class HealthComponent
{
public:
	void SetMaxHealth(const int maxHealth);
	int GetMaxHealth() const;

	bool IsAlive() const;

	void TakeDamage(const int damage);

private:
	int m_MaxHealth;
	int m_CurrentHealth;

};