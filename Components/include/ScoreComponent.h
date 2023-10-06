#pragma once

class ScoreComponent
{
public:
	int GetEarnedScore();
	int GetCurrentScore();
	void AddScore(const int score);

private:
	int m_EarnderScore = 100;
	int m_CurrentScore = 0;
};