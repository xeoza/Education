cmake_minimum_required(VERSION 3.10)
project(labs C)

set(CMAKE_C_STANDARD 99)

add_executable(app.exe main.c users.c students.c books.c )