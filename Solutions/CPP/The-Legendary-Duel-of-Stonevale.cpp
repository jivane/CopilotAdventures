#include "pch.h"
#include "The-Legendary-Duel-of-Stonevale.h"


std::map<std::string, std::string> StoneVale::WinningMoves =
{
    { "rock", "scissors" },
    { "scissors", "paper" },
    { "paper", "rock"}
};


std::map<std::string, int> StoneVale::StoneValePoints =
{
    { "rock", 1 },
    { "paper", 2 },
    { "scissors", 3 }
};


std::map<std::string, int> StoneVale::Points = {
    { "rock", 1 },
    { "paper", 2 },
    { "scissors", 3 }
};

bool StoneVale::IsWinningMove(const std::string& move1, const std::string& move2)
{
     return WinningMoves[move1] == move2;
}

void StoneVale::PlayRounds(const std::vector<std::string>& player1Moves, const std::vector<std::string>& player2Moves, int& player1Score, int& player2Score)
{
    int rounds = (int) std::min<size_t>(player1Moves.size(), player2Moves.size());
    for (int i = 0; i < rounds; ++i)
    {
        std::string move1 = player1Moves[i];
        std::string move2 = player2Moves[i];

        if (move1 == move2) continue;

        if (IsWinningMove(move1, move2))
        {
            player1Score += Points[move1];
        }
        else
        {
            player2Score += Points[move2];
        }
    }
}

std::string StoneVale::DetermineWinner(int player1Score, int player2Score)
{
    if (player1Score > player2Score) return "Player 1 wins!";
    if (player2Score > player1Score) return "Player 2 wins!";
    return "It's a draw!";
}

void StoneVale::DisplayResults(int player1Score, int player2Score)
{
    std::cout << "Player 1 Score: " << player1Score << std::endl;
    std::cout << "Player 2 Score: " << player2Score << std::endl;

    std::string winnerMessage = DetermineWinner(player1Score, player2Score);
    std::cout << winnerMessage << std::endl;
}

void StoneVale::Run()
{
    std::vector < std::string> player1Moves = { "scissors", "paper", "scissors", "rock", "rock" };
    std::vector < std::string> player2Moves = { "rock", "rock", "paper", "scissors", "paper" };

    int player1Score = 0, player2Score = 0;

    PlayRounds(player1Moves, player2Moves, player1Score, player2Score);
    DisplayResults(player1Score, player2Score);
}
