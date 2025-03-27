project(ByteForgeEngine VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "ByteForge Engine")

include_directories(ByteForgeEngine ${CMAKE_CURRENT_SOURCE_DIR}/source)

add_library(
    ByteForgeEngine SHARED

    source/ByteForgeApplication.cpp

    source/Platform/PlatformLayer.cpp
    source/Platform/Detection/PlatformDetector.cpp
    source/Platform/IO/FileSystem.cpp
    source/Platform/Window/WindowManager.cpp

    source/Core/Configuration/ConfigurationManager.cpp
    source/Core/DataParsers/IniParser.cpp
    source/Core/Strings/StringTypeConverter.cpp
    source/Core/Strings/StringManipulation.cpp

)

add_compile_definitions(BF_ENGINE_BUILD)

target_link_libraries(ByteForgeEngine PRIVATE ByteForgeVendor)

target_include_directories(ByteForgeEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)