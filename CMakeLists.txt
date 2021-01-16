cmake_minimum_required(VERSION 3.19)
project(projekt C)

set(CMAKE_C_STANDARD 11)

include_directories(src/modules)
include_directories(src/types)

add_executable(projekt
        src/modules/bmp.c
        src/modules/bmp.h
        src/types/bmp.h
        src/types/bmpHeader.h
        src/types/pixel.h
        src/main.c src/modules/noise.h src/modules/noise.c)
