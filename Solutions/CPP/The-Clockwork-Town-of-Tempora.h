#pragma once

class Tempora
{
public:
    static std::pair<int, int> ParseTime(const std::string& time);
    static int TimeDifference(const std::string& clockTime, const std::string& grandClockTime);
    static std::vector<int> SynchronizeClocks(const std::vector<std::string>& clockTimes, const std::string& grandClockTime);
    static void Run();
    
};
