#pragma once

class Position
{
public:
    int X, Y;

    Position(int x, int y) : X(x), Y(y) { }

    Position MoveBy(int dx, int dy, int gridSize) const;
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
    std::map<std::string, int> Battle();
    static void RenderGrid(int move, const std::optional<std::string> grid[][GridSize], const std::map<std::string, int>& scores);
};

