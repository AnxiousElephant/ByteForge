#include "PlatformDetector.h"

#include <SDL3/SDL.h>

namespace BF::Platform::Detection
{
    static void GetAudioDeviceData(PlatformAudioDeviceData& audioDeviceData, const SDL_AudioDeviceID audioDeviceId)
    {
        audioDeviceData.name = SDL_GetAudioDeviceName(audioDeviceId);

        SDL_AudioSpec audioSpec;

        SDL_GetAudioDeviceFormat(audioDeviceId, &audioSpec, &audioDeviceData.bufferSize);

        audioDeviceData.channels = audioSpec.channels;
        audioDeviceData.formatName = SDL_GetAudioFormatName(audioSpec.format);
        audioDeviceData.sampleRate = audioSpec.freq;
    }

    PlatformEnvironmentInfo PlatformDetector::GetEnvironmentInfo()
    {
        return PlatformEnvironmentInfo(SDL_GetPlatform(), SDL_GetBasePath(), BF_BUILD_CONFIGURATION_NAME, BF_COMPILER_NAME, BF_ARCHITECTURE_NAME);
    }

    PlatformMemoryInfo PlatformDetector::GetMemoryInfo()
    {
        return PlatformMemoryInfo(SDL_GetSystemRAM());
    }

    PlatformCPUInfo PlatformDetector::GetCPUInfo()
    {
        return PlatformCPUInfo(SDL_GetNumLogicalCPUCores());
    }

    PlatformDisplayInfo PlatformDetector::GetDisplayInfo()
    {
        PlatformDisplayInfo displayInfo{};

        if (SDL_DisplayID* displays = SDL_GetDisplays(&displayInfo.displaysCount); displays != nullptr)
        {
            for (int i = 0; i < displayInfo.displaysCount && i < MAX_DISPLAY_COUNT; i++)
            {
                PlatformDisplayData& displayData = displayInfo.displaysData[i];

                displayData.name = SDL_GetDisplayName(displays[i]);
                displayData.orientation = SDL_GetCurrentDisplayOrientation(displays[i]) == SDL_ORIENTATION_LANDSCAPE ? PlatformDisplayOrientationLandscape : PlatformDisplayOrientationPortrait;

                SDL_Rect displayBounds, displayUsableBounds;

                SDL_GetDisplayBounds(displays[i], &displayBounds);
                displayData.bounds = { .width = displayBounds.w, .height = displayBounds.h, .x = displayBounds.x, .y = displayBounds.h };

                SDL_GetDisplayUsableBounds(displays[i], &displayUsableBounds);
                displayData.usableBounds = { .width = displayUsableBounds.w, .height = displayUsableBounds.h, .x = displayUsableBounds.x, .y = displayUsableBounds.h };

                if (const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(displays[i]))
                {
                    displayData.width = mode->w;
                    displayData.height = mode->h;
                    displayData.pixelDensity = mode->pixel_density;
                    displayData.refreshRate = mode->refresh_rate;
                    displayData.refreshRateDenominator = mode->refresh_rate_denominator;
                    displayData.refreshRateNumerator = mode->refresh_rate_numerator;
                }
            }

            SDL_free(displays);
        }

        return displayInfo;
    }

    PlatformAudioInfo PlatformDetector::GetAudioInfo()
    {
        PlatformAudioInfo audioInfo{};

        if (SDL_AudioDeviceID* playbackDevices = SDL_GetAudioPlaybackDevices(&audioInfo.playbackDeviceCount); playbackDevices != nullptr)
        {
            for (int i = 0; i < audioInfo.playbackDeviceCount && i < MAX_PLAYBACK_AUDIO_DEVICE_COUNT; i++)
            {
                GetAudioDeviceData(audioInfo.playbackDevices[i], playbackDevices[i]);
            }

            SDL_free(playbackDevices);
        }

        if (SDL_AudioDeviceID* recordingDevices = SDL_GetAudioRecordingDevices(&audioInfo.recordingDeviceCount); recordingDevices != nullptr)
        {
            for (int i = 0; i < audioInfo.recordingDeviceCount && i < MAX_RECORDING_AUDIO_DEVICE_COUNT; i++)
            {
                GetAudioDeviceData(audioInfo.recordingDevices[i], recordingDevices[i]);
            }

            SDL_free(recordingDevices);
        }

        return audioInfo;
    }
}