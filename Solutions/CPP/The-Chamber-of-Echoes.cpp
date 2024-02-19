#include "pch.h"
#include "The-Chamber-of-Echoes.h"

std::vector<int> ChamberOfEchoes::echoes = { 3, 6, 9, 12};
std::vector<int> ChamberOfEchoes::memories;

int ChamberOfEchoes::PredictNext(const std::vector<int>& echoes)
{
    int difference = echoes[1] - echoes[0];
    int next = echoes[echoes.size() - 1] + difference;
    // Store the full sequence including the predicted number in memories
    memories.insert(memories.end(), echoes.begin(), echoes.end());
    memories.push_back(next);
    return next;
}

void ChamberOfEchoes::Run()
{
    std::cout << PredictNext(echoes) << std::endl;
}
