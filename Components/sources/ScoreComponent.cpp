#include "ScoreComponent.h"

int ScoreComponent::GetScore() const
{
	return m_CurrentScore;
}

void ScoreComponent::AddScore(const int score)
{
	m_CurrentScore += score;
}