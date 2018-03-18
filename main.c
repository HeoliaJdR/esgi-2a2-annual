#include <stdio.h>
#include <stdlib.h>
#include "qrcodegen.h"
#include <gtk/gtk.h>
#include "function.h"

int main(int argc,char** argv) {
    char *array = NULL;
    int *entryVerification = NULL;


    GtkWidget *window;
    GtkWidget *tempWidget;
    GtkBuilder *builder;
    GdkPixbuf * pixbuf;
    GError *error;
    WindowCalendarParam *tempCalendarParam = NULL;

    // Allocation mémoire du tableau de verification des entry
    entryVerification = malloc(sizeof(int)*7);
    
    gtk_init(&argc,&argv);
    if((error = loadGladeFile(&builder,"infoQR.glade")) == NULL){
        window = (GtkWidget *) gtk_builder_get_object(builder,"window1");

        g_signal_connect(window, "destroy", G_CALLBACK(destroyWindow), NULL);

        tempWidget = (GtkWidget *) gtk_builder_get_object(builder, "BirthdayEntry");

        if (tempWidget != NULL) {

            tempCalendarParam = (WindowCalendarParam *) calloc(1, sizeof(WindowCalendarParam));
            tempCalendarParam->destinationWidget = tempWidget;
            tempCalendarParam->calendarWindow = NULL;
            tempCalendarParam->year = -1;
            tempCalendarParam->month = -1;
            tempCalendarParam->day = -1;

            g_signal_connect(G_OBJECT(tempWidget), "icon-press", G_CALLBACK(openCalendar), (gpointer) tempCalendarParam);

        }

        tempWidget = (GtkWidget *) gtk_builder_get_object(builder,"validerButton");

        g_signal_connect(G_OBJECT(tempWidget), "clicked", G_CALLBACK(checkWorkerInfo),(gpointer) builder);

        gtk_widget_show_all(window);

        gtk_main();
    }else
        puts(error->message);


    return 0;
}
