#include "ScoreComponent.h"

#include <fstream>

ScoreComponent::ScoreComponent()
{
    ReadStoredScore();
}

void ScoreComponent::ReadStoredScore()
{
    m_EarnderScore = ReadOrCreateFile("../../../Resources/Score.txt", 0);
}

int ScoreComponent::ReadOrCreateFile(const std::string& filename, int defaultValue)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        int value;
        file >> value;
        file.close();
        return value;
    }
    else
    {
        std::ofstream output_file(filename);
        output_file << defaultValue;
        output_file.close();
        return defaultValue;
    }
}

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

void ScoreComponent::SaveScore()
{
    std::ofstream output_file("../../../Resources/Score.txt");
    output_file << m_CurrentScore + m_EarnderScore;
    output_file.close();
}
