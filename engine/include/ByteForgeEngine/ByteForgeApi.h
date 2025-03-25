#pragma once

#ifdef BF_ENGINE_BUILD
    #define BF_ENGINE_API __declspec(dllexport)
#else
    #define BF_ENGINE_API __declspec(dllimport)
#endif