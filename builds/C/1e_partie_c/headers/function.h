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
#include "xmlManager.h"

void destroyWindow(GtkWidget *widget, gpointer data);

GError *loadGladeFile(GtkBuilder **builder, char *fileName);

void checkWorkerInfo(GtkWidget *widget, gpointer data, int *entryVerification);

void daySelect(GtkCalendar *calendar, gpointer *data);

void openCalendar(GtkEntry *widget, GtkEntryIconPosition iconPos, GdkEvent *event, gpointer *data);

void closeDialogBox(GtkWidget *widget, gpointer *data);

void qrCodeToGtkImage(GtkWidget **image, char *code);

int textVerification(char *actualEntry, int *entryVerification, int positionVerif);

int emailVerification(char *actualEntry, int *entryVerification, int positionVerif);

int dateVerification(char *actualEntry, int *entryVerification, int positionVerif);

int secuVerification(char *actualEntry, int *entryVerification, int positionVerif);

int postOrRestaurantVerification(char *actualEntry, int *entryVerification, int positionVerif);

int entryVerification (int positionVerif, char *actualEntry, int *entryVerification);

#endif //UNTITLED_FUNCTION_H
