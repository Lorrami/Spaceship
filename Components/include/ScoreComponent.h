#pragma once

class ScoreComponent
{
public:
	int GetScore() const;
	void AddScore(const int score);

private:
	int m_CurrentScore{};
};