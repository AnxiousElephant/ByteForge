#pragma once

#include <string>

namespace BF::Platform::Window
{
    class WindowImplementation;

    class WindowManager final
    {
        public:
            WindowManager();
            ~WindowManager();

            [[nodiscard]] bool CreateWindow(const std::string& title, int width, int height, bool isFullscreen) const;
            [[nodiscard]] bool PollEvents() const;

        private:
            WindowImplementation* windowImplementation;
    };
}
