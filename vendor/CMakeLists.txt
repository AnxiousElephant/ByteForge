project(ByteForgeVendor VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "ByteForge Vendor")

enable_language(C)
add_library(glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/glad/source/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)

set(IMGUI_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
set(
    IMGUI_SOURCES
    ${IMGUI_DIRECTORY}/imgui.cpp
    ${IMGUI_DIRECTORY}/imgui_draw.cpp
    ${IMGUI_DIRECTORY}/imgui_tables.cpp
    ${IMGUI_DIRECTORY}/imgui_widgets.cpp
    ${IMGUI_DIRECTORY}/backends/imgui_impl_sdl3.cpp
    ${IMGUI_DIRECTORY}/backends/imgui_impl_opengl3.cpp
)

add_library(imgui STATIC
    ${IMGUI_SOURCES}
    ${IMGUI_DIRECTORY}/imgui.h
    ${IMGUI_DIRECTORY}/imgui_internal.h
)

target_link_libraries(imgui PRIVATE
    SDL3::SDL3
)

target_include_directories(imgui PUBLIC
    ${IMGUI_DIRECTORY}
    ${IMGUI_DIRECTORY}/backends
    ${CMAKE_CURRENT_SOURCE_DIR}/SDL3/include
)

add_library(ByteForgeVendor INTERFACE)

target_link_libraries(ByteForgeVendor INTERFACE SDL3::SDL3 imgui glad)

target_include_directories(ByteForgeVendor INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/SDL3/include
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
    ${IMGUI_DIRECTORY}
    ${IMGUI_DIRECTORY}/backends
)