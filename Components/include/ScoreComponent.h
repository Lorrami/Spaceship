#pragma once

#include <string>

class ScoreComponent
{
public:
	ScoreComponent();
	void ReadStoredScore();
	int GetEarnedScore();
	int GetCurrentScore();
	void AddScore(const int score);
	void SaveScore();

	int ReadOrCreateFile(const std::string& filename, int defaultValue);

private:
	int m_EarnderScore = 100;
	int m_CurrentScore = 0;
};