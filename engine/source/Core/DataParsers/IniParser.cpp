#include "IniParser.h"

#include "Core/Strings/StringManipulation.h"

namespace BF::Core::DataParsers
{
    IniData IniParser::Parse(const std::string& iniText)
    {
        IniData iniData{};

        if (iniText.empty()) return iniData;

        size_t lineStart = 0;
        size_t lineEnd = iniText.find('\n');

        std::string currentSection;

        while (lineStart != std::string::npos)
        {
            std::string line = (lineEnd == std::string::npos) ? iniText.substr(lineStart) : iniText.substr(lineStart, lineEnd - lineStart);

            ProcessLine(line, iniData, currentSection);

            lineStart = (lineEnd == std::string::npos) ? lineEnd : lineEnd + 1;
            lineEnd = iniText.find('\n', lineStart);
        }

        return iniData;
    }

    void IniParser::ProcessLine(std::string& line, IniData& data, std::string& currentSection)
    {
        Strings::StringManipulation::Trim(line);

        if (line.empty() || line[0] == ';' || line[0] == '#') return;

        if (line.back() == '\r') line.pop_back();

        if (line[0] == '[')
        {
            if (const size_t endBracket = line.find(']'); endBracket != std::string::npos)
            {
                currentSection = line.substr(1, endBracket - 1);
                Strings::StringManipulation::Trim(currentSection);
            }
        }
        else if (!currentSection.empty())
        {
            const size_t equalSign = line.find('=');

            if (equalSign == std::string::npos) return;

            std::string propertyKey = line.substr(0, equalSign);
            std::string propertyValue = line.substr(equalSign + 1);

            Strings::StringManipulation::Trim(propertyKey);
            Strings::StringManipulation::Trim(propertyValue);

            data.sections[currentSection].emplace(propertyKey, propertyValue);
        }
    }
}
