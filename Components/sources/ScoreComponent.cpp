#include "ScoreComponent.h"

int ScoreComponent::GetEarnedScore()
{
	return m_EarnderScore;
}

int ScoreComponent::GetCurrentScore()
{
	return m_CurrentScore;
}

void ScoreComponent::AddScore(const int score)
{
	m_CurrentScore += score;
}