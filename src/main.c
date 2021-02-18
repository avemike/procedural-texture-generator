/*
************************************************
************************************************
********     **********************     ********
********  *  **********************  *  ********
************************************************
************************************************
************************************************
********     **********************     ********
*********     ********************     *********
**********     ******************     **********
***********                          ***********
************                        ************
************************************************
************************************************
*/

#include <gtk/gtk.h>
#include <stdlib.h>
#include "headers/wood.h"
#include "headers/marble.h"
#include "headers/cloud.h"
#include "headers/texture.h"
#include "headers/bmp.h"

GtkBuilder *builder;
GtkAdjustment *adj_vRepeat, *adj_hRepeat, *adj_repeat, *adj_harmonics, *adj_twist;
GtkStack *stack_textureType;
GtkImage *img_preview;

void genFile(char *fileName) {
    double vRepeatVal = gtk_adjustment_get_value(adj_vRepeat);
    double hRepeatVal = gtk_adjustment_get_value(adj_hRepeat);
    double repeatVal = gtk_adjustment_get_value(adj_repeat);
    double twistFactor = gtk_adjustment_get_value(adj_twist);
    int harmonicsVal = 8 - gtk_adjustment_get_value(adj_harmonics);
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

int main (int argc, char *argv[])
{
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_builder_connect_signals(builder, NULL);

    // SLIDERS WIDGETS
    adj_harmonics = GTK_ADJUSTMENT(gtk_builder_get_object(builder, "adjustment1_layers"));
    adj_vRepeat = GTK_ADJUSTMENT(gtk_builder_get_object(builder, "adjustment1_vRepeat"));
    adj_hRepeat = GTK_ADJUSTMENT(gtk_builder_get_object(builder, "adjustment1_hRepeat1"));
    adj_repeat = GTK_ADJUSTMENT(gtk_builder_get_object(builder, "adjustment1_repeat"));
    adj_twist = GTK_ADJUSTMENT(gtk_builder_get_object(builder, "adjustment1_twist"));

    // STACK TEXTURE CONTROL
    stack_textureType = GTK_STACK(gtk_builder_get_object(builder, "stack_texture"));

    // IMAGE LIVE PREVIEW
    img_preview = GTK_IMAGE(gtk_builder_get_object(builder, "img_preview"));

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}
