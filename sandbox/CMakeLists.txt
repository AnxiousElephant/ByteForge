project(ByteForgeSandbox VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "ByteForge Sandbox")

add_executable(ByteForgeSandbox Sandbox.cpp)

add_dependencies(ByteForgeSandbox ByteForgeSandboxConfiguration)

add_custom_target(ByteForgeSandboxConfiguration
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Configuration
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Configuration ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Configuration
)

target_link_libraries(ByteForgeSandbox PRIVATE ByteForgeEngine)