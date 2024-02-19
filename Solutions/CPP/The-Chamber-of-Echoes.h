#pragma once

class ChamberOfEchoes
{
public:
    static std::vector<int> echoes;
    static std::vector<int> memories;
    static int PredictNext(const std::vector<int>& echoes);
    static void Run();
};
