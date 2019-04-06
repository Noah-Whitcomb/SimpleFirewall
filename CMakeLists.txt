cmake_minimum_required(VERSION 3.13)
project(NetworkingFinal C)

set(CMAKE_C_STANDARD 99)

add_executable(NetworkingFinal src/main.c src/Server.c src/Server.h src/Util.c src/Util.h)