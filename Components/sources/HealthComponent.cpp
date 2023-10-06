#include "HealthComponent.h"

void HealthComponent::SetMaxHealth(const int maxHealth)
{
	m_MaxHealth = maxHealth;
	m_CurrentHealth = m_MaxHealth;
}

int HealthComponent::GetMaxHealth() const
{
	return m_MaxHealth;
}

int HealthComponent::GetCurrentHealth() const
{
	return m_CurrentHealth;
}

bool HealthComponent::IsAlive() const
{
	return m_CurrentHealth > 0;
}

void HealthComponent::TakeDamage(const int damage)
{
	if (m_CurrentHealth - damage <= 0)
	{
		m_CurrentHealth = 0;
	}
	else
	{
		m_CurrentHealth -= damage;
	}
}
