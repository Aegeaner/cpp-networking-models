add_executable(seastar_server main.cpp)
# Seastar typically handles its own flags via pkg-config or CMake helpers, keeping it simple for skeleton
target_link_libraries(seastar_server PRIVATE common)
set_target_properties(seastar_server PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
