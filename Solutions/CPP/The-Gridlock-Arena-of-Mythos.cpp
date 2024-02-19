#include "pch.h"
#include "The-Gridlock-Arena-of-Mythos.h"

std::map<Direction, std::pair<int, int>> BattleSimulator::Directions = {
    { Direction::Up, { -1, 0} },
    { Direction::Down, { 1, 0} },
    { Direction::Left, { 0, -1} },
    { Direction::Right, { 0, 1} }
};


std::map<std::string, int> BattleSimulator::Battle()
{
    std::optional < std::string> grid[GridSize][GridSize];
    std::map < std::string, int> scores;
    // Initialize scores and place creatures on grid
    for (const auto&creature : creatures) {
        scores[creature.Name] = 0;
        grid[creature.Start.X][creature.Start.Y] = creature.Icon;
    }
    // Battle simulation logic should be implemented here
    return scores;
}

void BattleSimulator::RenderGrid(int move, const std::optional<std::string> grid[][GridSize], const std::map<std::string, int>& scores) {
    // Rendering logic should be implemented here
}
