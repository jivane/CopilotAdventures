#include <iostream>
#include <vector>

class ChamberOfEchoes
{
    public:
    static std::vector<int> echoes;
    static std::vector<int> memories;

    static int PredictNext(const std::vector<int>& echoes) {
        int difference = echoes[1] - echoes[0];
    int next = echoes[echoes.size() - 1] + difference;
    // Store the full sequence including the predicted number in memories
    memories.insert(memories.end(), echoes.begin(), echoes.end());
        memories.push_back(next);
        return next;
    }

static void Run()
{
    std::cout << PredictNext(echoes) << std::endl;
}
};

std::vector<int> ChamberOfEchoes::echoes = { 3, 6, 9, 12};
std::vector<int> ChamberOfEchoes::memories;

int main()
{
    ChamberOfEchoes::Run();
    return 0;
}
