//
// Created by rayan on 16/03/2018.
//

#include "function.h"


GError *loadGladeFile(GtkBuilder **builder, char *fileName) {
    GError *error = NULL;

    *builder = gtk_builder_new();

    gtk_builder_add_from_file(*builder, fileName, &error);

    return error;
}
