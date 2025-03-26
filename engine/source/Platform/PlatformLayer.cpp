#include "PlatformLayer.h"

#include <SDL3/SDL.h>

namespace BF::Platform
{
    void PlatformLayer::Initialize()
    {
        SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMEPAD | SDL_INIT_EVENTS | SDL_INIT_SENSOR | SDL_INIT_CAMERA);
    }

    void PlatformLayer::Shutdown()
    {
        SDL_QuitSubSystem(SDL_INIT_AUDIO);
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
        SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
        SDL_QuitSubSystem(SDL_INIT_HAPTIC);
        SDL_QuitSubSystem(SDL_INIT_GAMEPAD);
        SDL_QuitSubSystem(SDL_INIT_EVENTS);
        SDL_QuitSubSystem(SDL_INIT_SENSOR);
        SDL_QuitSubSystem(SDL_INIT_CAMERA);
        SDL_Quit();
    }
}
