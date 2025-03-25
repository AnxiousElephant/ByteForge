#pragma once

#include "ByteForgeApi.h"

namespace BF
{
    class BF_ENGINE_API ByteForgeApplication final
    {
    public:
        static void Initialize();

    private:
        ByteForgeApplication() = default;
        ~ByteForgeApplication() = default;
    };
}