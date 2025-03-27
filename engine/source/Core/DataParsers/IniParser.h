#pragma once

#include <string>
#include <unordered_map>

namespace BF::Core::DataParsers
{
    struct IniData
    {
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> sections{};
    };

    class IniParser final
    {
    public:
        IniParser() = default;
        ~IniParser() = default;

        static IniData Parse(const std::string& iniText);

    private:
        static void ProcessLine(std::string& line, IniData& data, std::string& currentSection);
    };
}
