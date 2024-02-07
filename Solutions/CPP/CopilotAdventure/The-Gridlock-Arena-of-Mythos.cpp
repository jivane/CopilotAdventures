#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <optional>


class Position
{
    public:
    int X, Y;

    Position(int x, int y) : X(x), Y(y) { }

    Position MoveBy(int dx, int dy, int gridSize) const {
        auto clamp = [](int value, int min, int max)-> int {
            return std::max(min, std::min(value, max));
        };
return Position(clamp(X + dx, 0, gridSize - 1), clamp(Y + dy, 0, gridSize - 1));
    }
};

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

class Creature
{
    public:
    std::string Name;
    Position Start;
    std::vector<Direction> Moves;
    int Power;
    std::string Icon;

    Creature(std::string name, Position start, std::vector<Direction> moves, int power, std::string icon)
        : Name(name), Start(start), Moves(std::move(moves)), Power(power), Icon(icon) { }
};

class BattleSimulator
{
    private:
    static const int GridSize = 5;
    std::vector<Creature> creatures;
    static inline const std::string OverlapIcon = "🤺";
    static inline const std::string EmptyCellIcon = "⬜";
    static std::map<Direction, std::pair<int, int>> Directions;

    public:
    BattleSimulator(const std::vector<Creature>& creatures) : creatures(creatures) { }

    std::map<std::string, int> Battle()
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

    static void RenderGrid(int move, const std::optional<std::string> grid[][GridSize], const std::map<std::string, int>& scores) {
        // Rendering logic should be implemented here
    }
};

std::map<Direction, std::pair<int, int>> BattleSimulator::Directions = {
    { Direction::Up, { -1, 0} },
    { Direction::Down, { 1, 0} },
    { Direction::Left, { 0, -1} },
    { Direction::Right, { 0, 1} }
};

int main()
{
    // Example of how to use BattleSimulator
    std::vector<Creature> creatures = {
        Creature("Dragon", Position(2, 2), {Direction::Right, Direction::Left, Direction::Down}, 7, "🐉"),
        Creature("Goblin", Position(2, 3), {Direction::Left, Direction::Right, Direction::Up}, 3, "👺"),
        Creature("Ogre", Position(0, 0), {Direction::Right, Direction::Down, Direction::Down}, 5, "👹"),
    };
    BattleSimulator simulator(creatures);
    auto scores = simulator.Battle();
    // Scores processing and display logic should be implemented here
    return 0;
}
