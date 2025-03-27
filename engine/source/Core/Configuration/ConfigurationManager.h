#pragma once

#include "ConfigurationSchema.h"

namespace BF::Core::Configuration
{
    class ConfigurationManager final
    {
    public:
        static constexpr const char* PLATFORM_SETTINGS_PATH = "./Configuration/PlatformSettings.ini";

        static PlatformSettingsSchema LoadPlatformSettings();
    };
}