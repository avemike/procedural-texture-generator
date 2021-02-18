CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(PTG)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")

ADD_EXECUTABLE(PTG
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
        src/modules/texture.c
        src/headers/texture.h src/utils/textureToBlue.c src/headers/textureToBlue.h src/utils/hsl.c src/headers/hsl.h src/utils/textureLight.c src/headers/textureLight.h src/types/hslType.h src/textures/cloud.c src/headers/cloud.h src/textures/marble.c src/headers/marble.h src/textures/wood.c src/headers/wood.h
        )
# ---- GTK SETUP ----
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)

INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})
ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

include_directories(src/modules)
include_directories(src/types)

TARGET_LINK_LIBRARIES(PTG -lm ${LIBS} ${GTK_LIBRARIES})
