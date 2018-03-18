//
// Created by rayan on 18/03/2018.
//

#ifndef UNTITLED_STRUCTURE_H
#define UNTITLED_STRUCTURE_H

#include <gtk/gtk.h>

typedef struct Validate {
    GtkBuilder *builder;
    char *name;
    char *surname;
    char *email;
    char *numsecu;
}Validate;

typedef struct WindowCalendarParam{
    GtkWidget * destinationWidget;
    GtkWidget * calendarWindow;
    gint day;
    gint month;
    gint year;
} WindowCalendarParam;

#endif //UNTITLED_STRUCTURE_H
