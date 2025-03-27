#include "StringManipulation.h"

namespace BF::Core::Strings
{
    void StringManipulation::Trim(std::string& str)
    {
        if (str.empty()) return;

        str.erase(0, str.find_first_not_of(" \t"));
        str.erase(str.find_last_not_of(" \t") + 1);
    }

    std::string StringManipulation::ToLower(const std::string& str)
    {
        if (str.empty()) return std::string();

        std::string lower;

        lower.reserve(str.size());

        for (const char c : str)
        {
            if (c >= 'A' && c <= 'Z')
            {
                lower += ('a' - 'A');
            }
            else
            {
                lower += c;
            }
        }

        return lower;
    }
}
