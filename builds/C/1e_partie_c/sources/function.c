//
// Created by rayan on 16/03/2018.
//

#include "../headers/function.h"


void destroyWindow(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

GError *loadGladeFile(GtkBuilder **builder, char *fileName) {
    GError *error = NULL;

    *builder = gtk_builder_new();

    gtk_builder_add_from_file(*builder, fileName, &error);

    return error;
}

int textVerification(char *actualEntry, int *entryVerification, int positionVerif){
    if(strlen(actualEntry) <= 20 && strlen(actualEntry) > 0){
      return entryVerification[positionVerif] = 1;
    }
    else{
      return entryVerification[positionVerif] = 0;
    }
}

int emailVerification(char *actualEntry, int *entryVerification, int positionVerif){
  int endVerif = 0;
  int atVerif = 0;
  if(strlen(actualEntry) <= 20 && strlen(actualEntry) > 0){
    // End mail verification
    for(int i = 0; i < 3; i++){
      if(strpbrk(actualEntry, ".fr") != NULL){
        endV++;
      }
      if(strpbrk(actualEntry, ".com") != NULL){
        endV++;
      }
      if(strpbrk(actualEntry, ".eu") != NULL){
        endV++;
      }
    }
    if(strchr(actualEntry, "@") != NULL){
      atVerif = 1;
    }
    if(endVerif == 3 && atVerif == 1){
      return entryVerification[positionVerif] = 1;
    }
  }
  else{
    return entryVerification[positionVerif] = 0;
  }
}

int dateVerification(char *actualEntry, int *entryVerification, int positionVerif){
  if(actualEntry != NULL)
    return entryVerification[positionVerif] = 1;
}

int secuVerification(char *actualEntry, int *entryVerification, int positionVerif){
  if(strlen(actualEntry) == 15){
    return entryVerification[positionVerif] = 1;
  }
  else{
    return entryVerification[positionVerif] = 0;
  }
}

int postOrRestaurantVerification(char *actualEntry, int *entryVerification, int positionVerif){
  // Restaurant verification
  if(positionVerif == 5){
    if(actualEntry >= 0 && actualEntry < 7){
      return entryVerification[positionVerif] = 1;
    }
    else{
      return entryVerification[positionVerif] = 0;
    }
  }
  // Post verification
  else{
    if(actualEntry >= 0 && actualEntry < 5){
      return entryVerification[positionVerif] = 1;
    }
    else{
      return entryVerification[positionVerif] = 0;
    }
  }
}

int entryVerification (int positionVerif, char *actualEntry, int *entryVerification){
    selectEntry(actualEntry, positionVerif);
    switch (positionVerif) {
      case 0:
        textVerification(actualEntry, entryVerification, positionVerif);
        &positionVerif++;
        break;
      case 1:
        textVerification(actualEntry, entryVerification, positionVerif);
        &positionVerif++;
        break
      case 2:
        dateVerification(actualEntry, entryVerification, positionVerif);
        &positionVerif++;
        break;
      case 3:
        secuVerification(actualEntry, entryVerification, positionVerif);
        &positionVerif++;
        break
      case 4:
        emailVerification(actualEntry, entryVerification, positionVerif);
        &positionVerif++;
        break;
      case 5:
        postOrRestaurantVerification(actualEntry, entryVerification, positionVerif);
        &positionVerif++;
        break
      case 6:
        postOrRestaurantVerification(actualEntry, entryVerification, positionVerif);
        &positionVerif++;
        break;
    }
}

void checkWorkerInfo(GtkWidget *widget, gpointer data, int *entryVerification){

    GtkWidget *tempWidget;
    Validate workerInfo;
    GError *error;
    GtkWidget *window;
    GtkBuilder *builder;
    int positionVerif = 0;

    /**
     * Je récupère mon champs
     * Je récupère le contenu de mon champ et je le stocke dans ma structure
     */
    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"SurnameEntry");
    workerInfo.surname = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));
    entryVerification(positionVerif, workerInfo.surname, entryVerification);

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"NameEntry");
    workerInfo.name = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));
    entryVerification(positionVerif, workerInfo.name, entryVerification);

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"BirthdayEntry");
    workerInfo.birthday = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));
    entryVerification(positionVerif, workerInfo.birthday, entryVerification);

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"NumSecuEntry");
    workerInfo.numsecu = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));
    entryVerification(positionVerif, workerInfo.numsecu, entryVerification);

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"EmailEntry");
    workerInfo.email = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));
    entryVerification(positionVerif, workerInfo.email, entryVerification);

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"RestaurantComboBox");
    workerInfo.restaurant = (char *) gtk_combo_box_get_active_id(GTK_COMBO_BOX(tempWidget));
    entryVerification(positionVerif, workerInfo.restaurant, entryVerification);

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"PosteComboBox");
    workerInfo.poste = (char *) gtk_combo_box_get_active_id(GTK_COMBO_BOX(tempWidget));
    entryVerification(positionVerif, workerInfo.poste, entryVerification);


    if((error = loadGladeFile(&builder,"infoQrcode.glade")) == NULL && positionVerif == 7){
        window = (GtkWidget *) gtk_builder_get_object(builder,"dialog1");

        tempWidget = (GtkWidget *) gtk_builder_get_object(builder,"CloseButton");

        g_signal_connect(G_OBJECT(tempWidget), "clicked", G_CALLBACK(closeDialogBox),(gpointer) window);

        tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(builder),"SurnameResultLabel");
        gtk_label_set_text(GTK_LABEL(tempWidget), workerInfo.surname);

        tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(builder),"NameResultLabel");
        gtk_label_set_text(GTK_LABEL(tempWidget), workerInfo.name);

        tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(builder),"DateResultLabel");
        gtk_label_set_text(GTK_LABEL(tempWidget), workerInfo.birthday);

        tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(builder),"SecuResultLabel");
        gtk_label_set_text(GTK_LABEL(tempWidget), workerInfo.numsecu);

        tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(builder),"EmailResultLabel");
        gtk_label_set_text(GTK_LABEL(tempWidget), workerInfo.email);

        tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(builder),"PosteResultLabel");
        gtk_label_set_text(GTK_LABEL(tempWidget), workerInfo.poste);

        tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(builder),"RestaurantResultLabel");
        gtk_label_set_text(GTK_LABEL(tempWidget), workerInfo.restaurant);

        tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(builder),"QrcodeImage");
        qrCodeToGtkImage(tempWidget, workerInfo.numsecu);

        gtk_widget_show_all(window);

        gtk_main();
    }else
        puts(error->message);

}

void openCalendar(GtkEntry *widget, GtkEntryIconPosition iconPos, GdkEvent *event, gpointer *data) {
    GtkBuilder *builder = NULL;
    GError *error = NULL;
    GtkWidget *window = NULL;
    GtkWidget *calendar = NULL;
    WindowCalendarParam *calendarParam = (WindowCalendarParam *) data;

    error = loadGladeFile(&builder, "calendar.glade");

    if (error == NULL) {
        window = (GtkWidget *) gtk_builder_get_object(builder, "calendarWindow");

        if (window != NULL) {

            calendarParam->calendarWindow = window;

            calendar = (GtkWidget *) gtk_builder_get_object(builder, "mainCalendar");

            if (calendarParam->day != -1)
                gtk_calendar_select_day(GTK_CALENDAR(calendar), (guint) calendarParam->day);

            if (calendarParam->month != -1 && calendarParam->year != -1)
                gtk_calendar_select_month(GTK_CALENDAR(calendar), (guint) calendarParam->month,
                                          (guint) calendarParam->year);

            if (calendar != NULL)
                g_signal_connect(G_OBJECT(calendar), "day-selected-double-click", G_CALLBACK(daySelect),
                                 calendarParam);

            gtk_widget_show_all(window);
        } else {
            printf("No window to display");
        }
    } else {
        printf("%s \n", error->message);
        g_error_free(error);
    }
}

void daySelect(GtkCalendar *calendar, gpointer *data) {
    WindowCalendarParam *calendarParam = (WindowCalendarParam *) data;
    guint year = 0;
    guint day = 0;
    guint month = 0;
    gchar tempChar[250];

    gtk_calendar_get_date(calendar, &year, &month, &day);

    gtk_widget_destroy(calendarParam->calendarWindow);

    sprintf(tempChar, "%d-%02d-%02d", year, month + 1, day);

    if (calendarParam->destinationWidget != NULL)
        gtk_entry_set_text(GTK_ENTRY(calendarParam->destinationWidget), tempChar);

    calendarParam->day = day;
    calendarParam->month = month;
    calendarParam->year = year;
}

void closeDialogBox(GtkWidget *widget, gpointer *data) {
    GtkWidget *window = (GtkWidget *) data;

    gtk_widget_destroy(window);


}

void qrCodeToGtkImage(GtkWidget **image, char *code){

    char *array = NULL;
    GtkWidget *window;
    GtkWidget *picture;
    GtkWidget *widget;
    GtkBuilder *builder;
    GdkPixbuf * pixbuf;
    int option = 0;
    int border = 12;
    int allBorder = border *2;
    int grow = 6;


    uint8_t qr0[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    bool ok = qrcodegen_encodeText(code,
                                   tempBuffer, qr0, qrcodegen_Ecc_MEDIUM,
                                   qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX,
                                   qrcodegen_Mask_AUTO, true);
    if (!ok)
        return;

    int size = qrcodegen_getSize(qr0);

    /**
     * Allocate the array
     */
    array = malloc(sizeof(char)* ( ((size * grow) + allBorder) * ((size * grow) + allBorder) * 3));

    memset(array, 255, (size_t) ((size * grow) + allBorder) * ((size * grow) + allBorder) * 3);

    for (int y = 0; y < size; y++) {

        for (int j = y * grow; j < (y * grow) + grow; ++j) {

            for (int x = 0; x < size; x++) {

                for (int i = 0; i < grow; ++i){
                    option = (j * ((size * grow) + allBorder) * 3) + (x * grow * 3) + (border * 3) + (i * 3) + (border * ((size * grow) + allBorder) * 3);
                    if(qrcodegen_getModule(qr0, x, y) == 1){
                        array[option] = (char) 0;
                        array[option + 1] = (char) 0;
                        array[option + 2] = (char) 0;
                    }
                }
            }
        }
    }

    pixbuf = gdk_pixbuf_new_from_data((const guchar*) array,
                                      GDK_COLORSPACE_RGB,
                                      FALSE,
                                      8,
                                      (size * grow) + allBorder,
                                      (size * grow) + allBorder,
                                      ((size * grow) + allBorder) * 3,
                                      NULL,
                                      NULL);

    gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
}
