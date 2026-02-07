add_executable(libevent_server main.cpp)
target_link_libraries(libevent_server PRIVATE common)
set_target_properties(libevent_server PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
# Note: In a real project, you'd add `find_package(Libevent REQUIRED)` here
