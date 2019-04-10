cmake_minimum_required(VERSION 3.13)
project(NetworkingFinal C)

set(CMAKE_C_STANDARD 99)

add_executable(SimpleFirewall src/main.c src/Server.c src/Server.h src/Util.c src/Util.h src/PreProcessing.c src/PreProcessing.h src/Structs.c src/Structs.h)

if(WIN32)
    target_link_libraries(SimpleFirewall wsock32 ws2_32)
endif()