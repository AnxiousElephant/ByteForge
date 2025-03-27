#include "FileSystem.h"

#include <filesystem>
#include <fstream>
#include <vector>

namespace BF::Platform::IO
{
    bool FileSystem::FileExists(const std::string& path)
    {
        return std::filesystem::exists(path);
    }

    std::string FileSystem::ReadFile(const std::string& path)
    {
        std::ifstream file(path, std::ios::binary | std::ios::ate);

        if (!file.is_open()) return std::string();

        const int64_t fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<char> buffer(fileSize);

        if (!file.read(buffer.data(), fileSize)) return std::string();

        return std::string(&buffer[0], fileSize);
    }
}