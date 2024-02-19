#include "pch.h"
#include "The-Magical-Forest-of-Algora.h"

std::string Algora::danceEffect(const std::string& loxMove, const std::string& drakoMove, const std::unordered_map<std::string, std::string>& effects)
{
    auto key = loxMove + drakoMove;
    auto it = effects.find(key);
        if (it != effects.end()) 
        {
            return it->second;
        } 
        else
        {
            return "A mysterious effect takes place.";
        }
}

std::vector<std::string> Algora::simulateDance(const std::vector<std::string>& loxMoves, const std::vector<std::string>& drakoMoves, const std::unordered_map<std::string, std::string>& effects)
{
    std::vector < std::string> results;
    for (size_t i = 0; i < loxMoves.size(); ++i)
    {
        results.push_back(danceEffect(loxMoves[i], drakoMoves[i], effects));
    }
    return results;
}

void Algora::Run()
{
    std::vector < std::string> loxMoves = { "Twirl", "Leap", "Spin", "Twirl", "Leap"};
    std::vector < std::string> drakoMoves = { "Spin", "Twirl", "Leap", "Leap", "Spin"};

    std::unordered_map < std::string, std::string> effects = {
        { "TwirlTwirl", "Fireflies light up the forest."},
            { "LeapSpin", "Gentle rain starts falling."},
            { "SpinLeap", "A rainbow appears in the sky."}
    };

    auto results = simulateDance(loxMoves, drakoMoves, effects);
    for (const auto&result : results) 
    {
            std::cout << result << std::endl;
    }    
}
