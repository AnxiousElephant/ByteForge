#include "StringTypeConverter.h"
#include "StringManipulation.h"

namespace BF::Core::Strings
{
    bool StringTypeConverter::ToBool(const std::string& str)
    {
        if (str.empty()) return false;

        const std::string lower = StringManipulation::ToLower(str);

        if (lower == "true" || lower == "1" || lower == "yes" || lower == "on") return true;

        return false;
    }

    int StringTypeConverter::ToInt(const std::string& str)
    {
        if (str.empty()) return 0;

        bool negative = false;

        if (str[0] == '-')
        {
            negative = true;
        }

        int result = 0;

        for (const char c : str)
        {
            if (c >= '0' && c <= '9')
            {
                result = result * 10 + (c - '0');
            }
        }

        return negative ? -result : result;
    }
}
