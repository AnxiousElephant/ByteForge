#pragma once

#include <string>

namespace BF::Core::Strings
{
    class StringTypeConverter final
    {
    public:
        static bool ToBool(const std::string& str);
        static int ToInt(const std::string& str);
    };
}
