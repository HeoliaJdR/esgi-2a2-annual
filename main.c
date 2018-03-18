#include <stdio.h>
#include <stdlib.h>
#include "qrcodegen.h"
#include <gtk/gtk.h>
#include "function.h"

int main(int argc,char** argv) {
    char *array = NULL;
    GtkWidget *window;
    GtkWidget *picture;
    GtkBuilder *builder;
    GdkPixbuf * pixbuf;
    GError *error;

    gtk_init(&argc,&argv);
    if((error = loadGladeFile(&builder,"infoQR.glade")) == NULL){
        window = (GtkWidget *) gtk_builder_get_object(builder,"window1");

        

        gtk_widget_show_all(window);

        gtk_main();
    }else
        puts(error->message);


    return 0;
}