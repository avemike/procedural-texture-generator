#include <gtk/gtk.h>

#include "bmpType.h"
#include "../headers/bmp.h"
#include "../headers/marble.h"
#include "../headers/wood.h"
#include "../headers/clouds.h"
#include "../globals.h"

// GTK Widgets declared in main.c
extern GtkBuilder *builder;
extern GtkAdjustment *adj_vRepeat, *adj_hRepeat, *adj_repeat, *adj_harmonics, *adj_twist;
extern GtkStack *stack_textureType;
extern GtkImage *img_preview;

//
void genFile(char *fileName) {
    // Gather input data from GTK Widgets
    double vRepeatVal = gtk_adjustment_get_value(adj_vRepeat);
    double hRepeatVal = gtk_adjustment_get_value(adj_hRepeat);
    double repeatVal = gtk_adjustment_get_value(adj_repeat);
    double twistFactor = gtk_adjustment_get_value(adj_twist);
    int harmonicsVal = (int)(gtk_adjustment_get_upper(adj_harmonics) - gtk_adjustment_get_value(adj_harmonics));
    const char* textureType = gtk_stack_get_visible_child_name(stack_textureType);

    RGB *texture = NULL;

    // Check texture type and generate texture based on it
    if (strcmp(textureType, TEXTURES.Marble) == 0) {
        texture = generateMarble(WIDTH, HEIGHT, harmonicsVal, vRepeatVal, hRepeatVal, twistFactor);
    }
    else if (strcmp(textureType, TEXTURES.Clouds) == 0) {
        texture = generateCloud(WIDTH, HEIGHT, harmonicsVal);
    }
    else if (strcmp(textureType, TEXTURES.Wood) == 0) {
        texture = generateWood(WIDTH, HEIGHT, harmonicsVal, repeatVal, twistFactor);
    }

    // Create bmp file and save texture
    BMP *file = generateBMPFile(texture, WIDTH, HEIGHT);
    saveBMP(fileName, file);
}

// Generates image and shows it in preview
void updateImage() {
    genFile(WORKING_FILENAME);
    gtk_image_set_from_file(img_preview, WORKING_FILENAME);
}

void btn_clicked_save () {
    // @todo: rename working .bmp file
}

// When user updates form inputs (sliders mostly...)
void change_modifier() {
    updateImage();
}

// When user press x in upper right corner
void on_main_window_destroy() {
    gtk_main_quit();
    remove(WORKING_FILENAME);
}
