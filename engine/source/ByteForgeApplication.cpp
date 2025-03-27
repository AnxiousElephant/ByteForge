#include "ByteForgeEngine/ByteForgeApplication.h"

#include "Core/Configuration/ConfigurationManager.h"
#include "Platform/Window/WindowManager.h"

namespace BF
{
    void ByteForgeApplication::Initialize(const int argc, char* argv[])
    {
        // For now, all the code in this method is based on testing the engine.

        const Core::Configuration::PlatformSettingsSchema platformSettings = Core::Configuration::ConfigurationManager::LoadPlatformSettings();

        const auto* windowManager = new Platform::Window::WindowManager();

        const bool windowCreated = windowManager->CreateWindow(
            platformSettings.windowSettings.title,
            platformSettings.windowSettings.width,
            platformSettings.windowSettings.height,
            platformSettings.windowSettings.isFullscreen
        );

        if (windowCreated)
        {
            while (windowManager->PollEvents())
            {

            }
        }

        delete windowManager;
    }
}
