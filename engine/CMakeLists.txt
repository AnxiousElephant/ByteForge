project(ByteForgeEngine VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "ByteForge Engine")

add_library(
    ByteForgeEngine SHARED
    source/ByteForgeApplication.cpp
    source/Platform/PlatformLayer.cpp
    source/Platform/Detection/PlatformDetector.cpp
)

add_compile_definitions(BF_ENGINE_BUILD)

target_link_libraries(ByteForgeEngine PRIVATE ByteForgeVendor)

target_include_directories(ByteForgeEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)