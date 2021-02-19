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
#include "headers/clouds.h"
#include "headers/texture.h"
#include "headers/bmp.h"

// GLOBAL: GTK widgets pointers
GtkWidget *window_main;
GtkBuilder *builder;
GtkAdjustment *adj_vRepeat, *adj_hRepeat, *adj_repeat, *adj_harmonics, *adj_twist;
GtkStack *stack_textureType;
GtkImage *img_preview;


int main (int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    // Glade UI builder
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "ui.glade", NULL);

    // Main Window
    window_main = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
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
    gtk_widget_show(window_main);
    gtk_main();

    return 0;
}
