cmake_minimum_required(VERSION 3.0.0)
project(Terminal_Snake VERSION 1.2)

add_executable(snake snake.c)
add_subdirectory(jlib)

target_link_libraries(snake jlib)