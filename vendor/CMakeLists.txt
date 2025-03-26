project(ByteForgeVendor VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "ByteForge Vendor")

add_subdirectory(SDL3)

add_library(ByteForgeVendor INTERFACE)

target_link_libraries(ByteForgeVendor INTERFACE SDL3::SDL3)

target_include_directories(ByteForgeVendor INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/SDL3/include)