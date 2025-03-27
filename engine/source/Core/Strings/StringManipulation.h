#pragma once

#include <string>

namespace BF::Core::Strings
{
    class StringManipulation final
    {
    public:
        static void Trim(std::string& str);
        static std::string ToLower(const std::string& str);
    };
}
