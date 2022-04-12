cmake_minimum_required(VERSION 3.19)
project(TP C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TP
        game.c
        game.h
        main.c
        matdin.c
        matdin.h
        save.c
        save.h
        utils.c
        utils.h)
