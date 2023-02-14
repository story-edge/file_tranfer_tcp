cmake_minimum_required(VERSION 3.16)
project(file C)

set(CMAKE_C_STANDARD 99)

add_executable(file main.c DEBUG.h tcp_socket.c tcp_socket.h server.c client.c file_transfer.c file_transfer.h)
