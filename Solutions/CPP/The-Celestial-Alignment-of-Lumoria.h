#pragma once

class Planet 
{
public:
	std::string Name;
	double Distance;
	double Size;
	Planet(std::string name, double distance, double size) : Name(name), Distance(distance), Size(size) {}
};

class Lumoria
{
public:
	static int GetShadowCount(const std::vector<Planet>& planets, int currentIndex);
	static std::string GetLightIntensity(int i, int shadowCount);
	static std::vector<std::pair<std::string, std::string>> CalculateLightIntensity(const std::vector<Planet>& planets);
	static void Run();
};