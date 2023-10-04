#pragma once

class HealthComponent
{
public:
	void SetMaxHealth(const int maxHealth);
	int GetMaxHealth();

	bool IsAlive();

	void TakeDamage(const int damage);

private:
	int m_MaxHealth;
	int m_CurrentHealth;

};