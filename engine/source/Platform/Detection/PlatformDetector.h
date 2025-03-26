#pragma once

#if defined(__clang__)
    #define BF_COMPILER_NAME "Clang"
#elif defined(__GNUC__) || defined(__GNUG__)
    #define BF_COMPILER_NAME "GCC"
#elif defined(_MSC_VER)
    #define BF_COMPILER_NAME "MSVC"
#else
    #define BF_COMPILER_NAME "Unknown"
#endif

#if defined(__x86_64__) || defined(_M_X64)
    #define BF_ARCHITECTURE_NAME "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
    #define BF_ARCHITECTURE_NAME "x86"
#elif defined(__aarch64__) || defined(_M_ARM64)
    #define BF_ARCHITECTURE_NAME "ARM64"
#elif defined(__arm__) || defined(_M_ARM)
    #define BF_ARCHITECTURE_NAME "ARM"
#else
    #define BF_ARCHITECTURE_NAME "Unknown"
#endif

#if !defined(NDEBUG) || defined(_DEBUG)
    #define BF_BUILD_CONFIGURATION_NAME "Debug"
#else
    #define BF_BUILD_CONFIGURATION_NAME "Release"
#endif

#include "PlatformInfo.h"

namespace BF::Platform::Detection
{
    class PlatformDetector
    {
    public:
        static PlatformEnvironmentInfo GetEnvironmentInfo();
        static PlatformMemoryInfo GetMemoryInfo();
        static PlatformCPUInfo GetCPUInfo();
        static PlatformDisplayInfo GetDisplayInfo();
        static PlatformAudioInfo GetAudioInfo();
    };
}
