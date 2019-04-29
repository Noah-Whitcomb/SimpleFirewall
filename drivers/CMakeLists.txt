cmake_minimum_required(VERSION 3.13)
project(TestClient C)

set(CMAKE_C_STANDARD 99)

add_executable(TestClient main.c)

if(WIN32)
    target_link_libraries(TestClient wsock32 ws2_32)
endif()