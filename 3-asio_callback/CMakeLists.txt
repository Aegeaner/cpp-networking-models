add_executable(asio_callback_server main.cpp)
target_link_libraries(asio_callback_server PRIVATE common)
set_target_properties(asio_callback_server PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
# Note: In a real project, you'd add `find_package(Asio REQUIRED)` here
