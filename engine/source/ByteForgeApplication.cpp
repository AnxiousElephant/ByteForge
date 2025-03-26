#include "ByteForgeEngine/ByteForgeApplication.h"
#include "Platform/PlatformLayer.h"
#include "Platform/Detection/PlatformDetector.h"

namespace BF
{
    void ByteForgeApplication::Initialize(const int argc, char* argv[])
    {
        Platform::PlatformLayer::Initialize();

        Platform::Detection::PlatformEnvironmentInfo environmentInfo = Platform::Detection::PlatformDetector::GetEnvironmentInfo();
        Platform::Detection::PlatformMemoryInfo memoryInfo = Platform::Detection::PlatformDetector::GetMemoryInfo();
        Platform::Detection::PlatformCPUInfo cpuInfo = Platform::Detection::PlatformDetector::GetCPUInfo();
        Platform::Detection::PlatformDisplayInfo displayInfo = Platform::Detection::PlatformDetector::GetDisplayInfo();
        Platform::Detection::PlatformAudioInfo audioInfo = Platform::Detection::PlatformDetector::GetAudioInfo();

        Platform::PlatformLayer::Shutdown();
    }
}
