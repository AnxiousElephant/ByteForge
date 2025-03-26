#pragma once

namespace BF::Platform::Detection
{
    constexpr int MAX_DISPLAY_COUNT = 5;
    constexpr int MAX_PLAYBACK_AUDIO_DEVICE_COUNT = 10;
    constexpr int MAX_RECORDING_AUDIO_DEVICE_COUNT = 10;
    constexpr int MAX_GAMEPAD_COUNT = 4;
    constexpr int MAX_JOYSTICK_COUNT = 4;
    constexpr int MAX_CAMERA_COUNT = 2;

    enum PlatformDisplayOrientation
    {
        Portrait,
        Landscape
    };

    struct PlatformEnvironmentInfo
    {
        const char* const operatingSystem{};
        const char* const workingDirectory{};
        const char* const buildConfiguration{};
        const char* const compiler{};
        const char* const architecture{};
    };

    struct PlatformMemoryInfo
    {
        int totalAvailableRAM = 0;
    };

    struct PlatformCPUInfo
    {
        int threadsCount = 0;
    };

    struct PlatformDisplayBounds
    {
        int width = 0;
        int height = 0;
        int x = 0;
        int y = 0;
    };

    struct PlatformDisplayData
    {
        const char* name{};
        int width = 0;
        int height = 0;
        int refreshRateNumerator = 0;
        int refreshRateDenominator = 0;
        float refreshRate = 0.0f;
        float pixelDensity = 0.0f;
        PlatformDisplayBounds bounds{};
        PlatformDisplayBounds usableBounds{};
        PlatformDisplayOrientation orientation{};
    };

    struct PlatformDisplayInfo
    {
        int displaysCount = 0;
        PlatformDisplayData displaysData[MAX_DISPLAY_COUNT]{};
    };

    struct PlatformAudioDeviceData
    {
        const char* name{};
        const char* formatName{};
        int channels = 0;
        int sampleRate = 0;
        int bufferSize = 0;
    };

    struct PlatformAudioInfo
    {
        int playbackDeviceCount = 0;
        int recordingDeviceCount = 0;
        PlatformAudioDeviceData playbackDevices[MAX_PLAYBACK_AUDIO_DEVICE_COUNT]{};
        PlatformAudioDeviceData recordingDevices[MAX_RECORDING_AUDIO_DEVICE_COUNT]{};
    };
}