
#include "pch.h"
#include "The-Celestial-Alignment-of-Lumoria.h"


std::string Lumoria::GetLightIntensity(int i, int shadowCount) {
    if (i == 0) return "Full";
    if (shadowCount == 1) return "None";
    if (shadowCount > 1) return "None (Multiple Shadows)";
    return "Partial";
}

std::vector<std::pair<std::string, std::string>> Lumoria::CalculateLightIntensity(const std::vector<Planet>& planets) {
    std::vector<std::pair<std::string, std::string>> lightIntensities;
    for (int i = 0; i < planets.size(); ++i) {
        int shadowCount = GetShadowCount(planets, i);
        std::string lightIntensity = GetLightIntensity(i, shadowCount);
        lightIntensities.emplace_back(planets[i].Name, lightIntensity);
    }
    return lightIntensities;
}


int  Lumoria::GetShadowCount(const std::vector<Planet>& planets, int currentIndex) {
    int shadowCount = 0;
    for (int i = 0; i < currentIndex; ++i) {
        if (planets[i].Size > planets[currentIndex].Size) {
            ++shadowCount;
        }
    }
    return shadowCount;
}

void Lumoria::Run() {
    std::vector<Planet> lumoriaPlanets = {
        Planet("Mercuria", 0.4, 4879),
        Planet("Earthia", 1, 12742),
        Planet("Venusia", 0.7, 12104),
        Planet("Marsia", 1.5, 6779)
    };

    // Sorting planets by distance
    std::sort(lumoriaPlanets.begin(), lumoriaPlanets.end(), [](const Planet& a, const Planet& b) {
        return a.Distance < b.Distance;
        });

    auto lightIntensities = CalculateLightIntensity(lumoriaPlanets);

    for (const auto& item : lightIntensities) {
        std::cout << "Planet: " << item.first << ", Light: " << item.second << std::endl;
    }
}