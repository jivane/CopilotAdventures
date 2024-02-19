#include "pch.h"
#include "The-Clockwork-Town-of-Tempora.h"

std::pair<int, int> Tempora::ParseTime(const std::string& time)
{
    std::istringstream ss(time);
    std::string part;
    std::getline(ss, part, ':');
    int hour = std::stoi(part);
    std::getline(ss, part);
    int minute = std::stoi(part);
    return { hour, minute
    };
}

int Tempora::TimeDifference(const std::string& clockTime, const std::string& grandClockTime)
{
    auto [clockHour, clockMinute] = ParseTime(clockTime);
    auto [grandClockHour, grandClockMinute] = ParseTime(grandClockTime);
    return (clockHour - grandClockHour) * 60 + (clockMinute - grandClockMinute);
}

std::vector<int> Tempora::SynchronizeClocks(const std::vector<std::string>& clockTimes, const std::string& grandClockTime)
{
    std::vector<int> differences;
    for (const auto& clockTime : clockTimes) {
        differences.push_back(TimeDifference(clockTime, grandClockTime));
    }
    return differences;
}

void Tempora::Run()
{
    std::vector < std::string> clockTimes = { "14:45", "15:05", "15:00", "14:40" };
    std::string grandClockTime = "15:00";
    auto differences = SynchronizeClocks(clockTimes, grandClockTime);
    std::cout << "[";
    for (size_t i = 0; i < differences.size(); ++i)
    {
        std::cout << differences[i];
        if (i != differences.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

