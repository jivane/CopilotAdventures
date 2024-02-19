#pragma once

class StoneVale
{
private:
    static void PlayRounds(const std::vector<std::string>& player1Moves, const std::vector<std::string>& player2Moves, int& player1Score, int& player2Score);
    static std::string DetermineWinner(int player1Score, int player2Score);
    static void DisplayResults(int player1Score, int player2Score);
    static std::map<std::string, std::string> WinningMoves;
    static std::map<std::string, int> StoneValePoints;
    static std::map<std::string, int> Points;
    static bool IsWinningMove(const std::string& move1, const std::string& move2);
public:
    static void Run();   
};
