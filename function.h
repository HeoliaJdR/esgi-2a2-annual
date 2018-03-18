//
// Created by rayan on 16/03/2018.
//

#ifndef UNTITLED_FUNCTION_H
#define UNTITLED_FUNCTION_H

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "qrcodegen.h"

void destroyWindow(GtkWidget *widget, gpointer data);

GError *loadGladeFile(GtkBuilder **builder, char *fileName);

void checkWorkerInfo(GtkWidget *widget, gpointer data);

void daySelect(GtkCalendar *calendar, gpointer *data);

void openCalendar(GtkEntry *widget, GtkEntryIconPosition iconPos, GdkEvent *event, gpointer *data);

void closeDialogBox(GtkWidget *widget, gpointer *data);

void qrCodeToGtkImage(GtkWidget **image, char *code);

#endif //UNTITLED_FUNCTION_H
