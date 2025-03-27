#include "ConfigurationManager.h"

#include "Core/DataParsers/IniParser.h"
#include "Core/Strings/StringTypeConverter.h"

#include "Platform/IO/FileSystem.h"

namespace BF::Core::Configuration
{
    PlatformSettingsSchema ConfigurationManager::LoadPlatformSettings()
    {
        const std::string platformSettingsContent = Platform::IO::FileSystem::ReadFile(PLATFORM_SETTINGS_PATH);
        const DataParsers::IniData platformSettingsIni = DataParsers::IniParser::Parse(platformSettingsContent);

        const std::unordered_map<std::string, std::string> windowSection = platformSettingsIni.sections.at("window");

        return
        {
            .windowSettings =
            {
                .title = windowSection.at("title"),
                .width = Strings::StringTypeConverter::ToInt(windowSection.at("width")),
                .height = Strings::StringTypeConverter::ToInt(windowSection.at("height")),
                .isFullscreen = Strings::StringTypeConverter::ToBool(windowSection.at("is_fullscreen"))
            }
        };
    }
}
