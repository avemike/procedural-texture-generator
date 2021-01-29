cmake_minimum_required(VERSION 3.19)
project(projekt C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-lm")

include_directories(src/modules)
include_directories(src/types)

add_executable(projekt
        src/modules/bmp.c
        src/headers/bmp.h
        src/types/bmpType.h
        src/types/bmpHeaderType.h
        src/types/rgbType.h
        src/main.c
        src/headers/noise.h
        src/modules/noise.c
        src/modules/bluredNoise.c
        src/headers/bluredNoise.h
        src/modules/smoothNoise.c
        src/headers/smoothNoise.h
        src/headers/turbulence.h
        src/modules/turbulence.c
        src/modules/texture.c src/headers/texture.h src/utils/textureToBlue.c src/headers/textureToBlue.h src/utils/hsl.c src/headers/hsl.h src/utils/textureLight.c src/headers/textureLight.h src/types/hslType.h src/textures/cloud.c src/headers/cloud.h src/textures/marble.c src/headers/marble.h src/textures/wood.c src/headers/wood.h)
