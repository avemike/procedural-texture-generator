//
// Created by avemike on 18/02/2021.
//

#include <gtk/gtk.h>

#include "bmpType.h"
#include "../headers/bmp.h"
#include "../headers/marble.h"
#include "../headers/wood.h"
#include "../headers/clouds.h"

extern GtkBuilder *builder;
extern GtkAdjustment *adj_vRepeat, *adj_hRepeat, *adj_repeat, *adj_harmonics, *adj_twist;
extern GtkStack *stack_textureType;
extern GtkImage *img_preview;

void genFile(char *fileName) {
    double vRepeatVal = gtk_adjustment_get_value(adj_vRepeat);
    double hRepeatVal = gtk_adjustment_get_value(adj_hRepeat);
    double repeatVal = gtk_adjustment_get_value(adj_repeat);
    double twistFactor = gtk_adjustment_get_value(adj_twist);
    int harmonicsVal = (int)(gtk_adjustment_get_upper(adj_harmonics) - gtk_adjustment_get_value(adj_harmonics));
    const char* textureType = gtk_stack_get_visible_child_name(stack_textureType);

    const int width = 256;
    const int height = 256;
    RGB *texture = NULL;

    // Check texture type
    if (strcmp(textureType, "Marble") == 0) {
        texture = generateMarble(width, height, harmonicsVal, vRepeatVal, hRepeatVal, twistFactor);
    }
    else if (strcmp(textureType, "Clouds") == 0) {
        texture = generateCloud(width, height, harmonicsVal);
    }
    else if (strcmp(textureType, "Wood") == 0) {
        texture = generateWood(width, height, harmonicsVal, repeatVal, twistFactor);
    }

    BMP *file = generateBMPFile(texture, width, height);

    saveBMP(fileName, file);
}

void updateImage(char *fileName) {
    genFile(fileName);
    gtk_image_set_from_file(img_preview, fileName);
}

void btn_clicked_save () {
    updateImage("output.bmp");
}

void change_modifier() {
    updateImage("_temp.bmp");
}

void on_main_window_destroy() {
    gtk_main_quit();
}
