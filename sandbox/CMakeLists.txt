project(ByteForgeSandbox VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "ByteForge Sandbox")

add_executable(ByteForgeSandbox Sandbox.cpp)

target_link_libraries(ByteForgeSandbox PRIVATE ByteForgeEngine)