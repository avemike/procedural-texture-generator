CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(procedural-texture-generator)

FIND_PACKAGE(PkgConfig REQUIRED)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic") # Glade needs this

ADD_EXECUTABLE(procedural-texture-generator
        src/main.c

        # Headers
        src/headers/randomNoisePattern.h src/headers/hsl.h src/headers/wood.h src/headers/turbulence.h
        src/headers/clouds.h src/headers/marble.h src/headers/bmp.h
        src/headers/smoothNoise.h src/headers/texture.h src/headers/ui.h

        # Types
        src/types/bmpHeaderType.h src/types/bmpType.h
        src/types/rgbType.h src/types/hslType.h

        # Modules
        src/modules/bmp.c src/modules/randomNoisePattern.c
        src/modules/smoothNoise.c src/modules/turbulence.c src/modules/texture.c

        # Textures
        src/textures/marble.c src/textures/clouds.c src/textures/wood.c

        # Handlers
        src/handlers/ui.c

        # Utils
        src/utils/hsl.c src/globals.h)

# ---- GTK SETUP ----
PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)

INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})
ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

include_directories(src/modules)
include_directories(src/types)

TARGET_LINK_LIBRARIES(procedural-texture-generator -lm ${LIBS} ${GTK_LIBRARIES}) # -lm enables using math.h
