#include "HealthComponent.h"

void HealthComponent::SetMaxHealth(const int maxHealth)
{
	m_MaxHealth = maxHealth;
	m_CurrentHealth = m_MaxHealth;
}

int HealthComponent::GetMaxHealth()
{
	return m_MaxHealth;
}

bool HealthComponent::IsAlive()
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
