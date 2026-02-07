add_executable(asio_coro_server main.cpp)
target_link_libraries(asio_coro_server PRIVATE common)
set_target_properties(asio_coro_server PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
# Note: In a real project, you'd add `find_package(Asio REQUIRED)` here
