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
#include "headers/wood.h"
#include "headers/marble.h"
#include "headers/cloud.h"
#include "headers/texture.h"
#include "headers/bmp.h"

static
void makeWood(GtkWidget *widget,
                     gpointer data) {
    const int width = 256;
    const int height = 256;
    const int size = 4;

    RGB *texture = generateWood(width, height, size);
    BMP *file = generateBMPFile(texture, width, height);
    saveBMP("temp.bmp", file);
}

static
void makeClouds(GtkWidget *widget,
                     gpointer data) {
    const int width = 256;
    const int height = 256;
    const int size = 5;

    RGB *texture = generateCloud(width, height, size);
    BMP *file = generateBMPFile(texture, width, height);
    saveBMP("temp.bmp", file);
}

static
void makeMarble(GtkWidget *widget,
                      gpointer data) {
    const int width = 256;
    const int height = 256;
    const int size = 6;

    RGB *texture = generateMarble(width, height, size);
    BMP *file = generateBMPFile(texture, width, height);
    saveBMP("temp.bmp", file);
}

static void
activate(GtkApplication *app,
         gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *entry;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Window");
    gtk_container_set_border_width(GTK_CONTAINER (window), 10);

    grid = gtk_grid_new();

    gtk_container_add(GTK_CONTAINER (window), grid);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID (grid), entry, 0, 0, 1, 1);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID (grid), entry, 2, 0, 1, 1);

    button = gtk_button_new_with_label("Clouds");
    g_signal_connect (button, "clicked", G_CALLBACK(makeClouds), NULL);

    gtk_grid_attach(GTK_GRID (grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("Marble");
    g_signal_connect (button, "clicked", G_CALLBACK(makeMarble), NULL);

    gtk_grid_attach(GTK_GRID (grid), button, 1, 1, 1, 1);


    button = gtk_button_new_with_label("Wood");
    g_signal_connect (button, "clicked", G_CALLBACK(makeWood), NULL);

    gtk_grid_attach(GTK_GRID (grid), button, 2, 1, 1, 1);

    button = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped (button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    gtk_grid_attach(GTK_GRID (grid), button, 0, 2, 2, 1);

    gtk_widget_show_all(window);

}

int
main(int argc,
     char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    return status;
}
