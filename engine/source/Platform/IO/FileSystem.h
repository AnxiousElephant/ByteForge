#pragma once

#include <string>

namespace BF::Platform::IO
{
    class FileSystem final
    {
    public:
        static bool FileExists(const std::string& path);
        static std::string ReadFile(const std::string& path);
    };
}