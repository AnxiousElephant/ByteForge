#pragma once

#include <string>

namespace BF::Core::Configuration
{
    struct WindowSettingsSchema
    {
        std::string title{};
        int width = 0;
        int height = 0;
        bool isFullscreen = false;
    };

    struct PlatformSettingsSchema
    {
        WindowSettingsSchema windowSettings;
    };
}
