cmake_minimum_required(VERSION 4.1)
project(Learning_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Learning_C
        sem3/main.c
        sem4/main.c
        sem5/main.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=[sanitizer_name] [additional_options] [-g] [-OX]")