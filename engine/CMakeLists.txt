project(ByteForgeEngine VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "ByteForge Engine")

add_library(
    ByteForgeEngine SHARED
    include/ByteForgeEngine/ByteForgeApi.h
    include/ByteForgeEngine/ByteForgeApplication.h
    include/ByteForgeEngine.h
    source/ByteForgeApplication.cpp
)

add_compile_definitions(BF_ENGINE_BUILD)

target_include_directories(ByteForgeEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)