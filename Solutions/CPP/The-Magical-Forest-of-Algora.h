#pragma once

class Algora
{
public:
    static std::string danceEffect(const std::string& loxMove, const std::string& drakoMove, const std::unordered_map<std::string, std::string>& effects);
    static std::vector<std::string> simulateDance(const std::vector<std::string>& loxMoves, const std::vector<std::string>& drakoMoves, const std::unordered_map<std::string, std::string>& effects);
    static void Run();
};
