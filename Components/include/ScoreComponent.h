#pragma once

class ScoreComponent
{
public:
	int GetScore();
	void AddScore(const int score);

private:
	int m_CurrentScore = 100;
};