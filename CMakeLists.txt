cmake_minimum_required(VERSION 3.23)
project(sockets C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(sockets src/server.c)

