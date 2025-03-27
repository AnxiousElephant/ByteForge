#include "WindowManager.h"

#include <vector>

#include <SDL3/SDL.h>

namespace BF::Platform::Window
{
    class WindowImplementation
    {
    public:
        std::vector<SDL_Window*> windows;

        ~WindowImplementation()
        {
            for (SDL_Window* window : windows)
            {
                if (window)
                {
                    SDL_DestroyWindow(window);
                }
            }

            windows.clear();
        }
    };

    WindowManager::WindowManager() : windowImplementation(new WindowImplementation())
    {

    }

    WindowManager::~WindowManager()
    {
        delete windowImplementation;
    }

    bool WindowManager::CreateWindow(const std::string& title, const int width, const int height, const bool isFullscreen) const
    {
        ::SDL_Window* window = SDL_CreateWindow(title.c_str(), width, height, isFullscreen ? SDL_WINDOW_FULLSCREEN : 0);

        if (!window) return false;


        windowImplementation->windows.emplace_back(window);

        return true;
    }

    bool WindowManager::PollEvents() const
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                {
                    return false;
                }
                case SDL_EVENT_KEY_DOWN:
                {
                    if (event.key.key == SDLK_ESCAPE)
                    {
                        return false;
                    }
                }
                default: ;
            }
        }

        return true;
    }
}
