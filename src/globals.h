#ifndef PROCEDURAL_TEXTURE_GENERATOR_GLOBALS_H
#define PROCEDURAL_TEXTURE_GENERATOR_GLOBALS_H

#include <gtk/gtk.h>;

// Available textures
struct _TEXTURES {
    char *Marble;
    char *Wood;
    char *Clouds;
} TEXTURES = {"Marble", "Wood", "Clouds"};

char *WORKING_FILENAME = "_temp.bmp";

// @todo: make resolution customization
int WIDTH = 256;
int HEIGHT = 256;

#endif