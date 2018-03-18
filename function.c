//
// Created by rayan on 16/03/2018.
//

#include "function.h"


void destroyWindow(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

GError *loadGladeFile(GtkBuilder **builder, char *fileName) {
    GError *error = NULL;

    *builder = gtk_builder_new();

    gtk_builder_add_from_file(*builder, fileName, &error);

    return error;
}

void checkWorkerInfo(GtkWidget *widget, gpointer data){

    GtkWidget *tempWidget;
    Validate workerInfo;
    GError *error;
    GtkWidget *window;
    GtkBuilder *builder;

    /**
     * Je récupère mon champs
     * Je récupère le contenu de mon champ et je le stocke dans ma structure
     */
    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"SurnameEntry");
    workerInfo.surname = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"NameEntry");
    workerInfo.name = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"BirthdayEntry");
    workerInfo.birthday = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"EmailEntry");
    workerInfo.email = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"NumSecuEntry");
    workerInfo.numsecu = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"BirthdayEntry");
    workerInfo.birthday = (char *) gtk_entry_get_text(GTK_ENTRY(tempWidget));

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"PosteComboBox");
    workerInfo.poste = (char *) gtk_combo_box_get_active_id(GTK_COMBO_BOX(tempWidget));

    tempWidget = (GtkWidget *) gtk_builder_get_object(GTK_BUILDER(data),"RestaurantComboBox");
    workerInfo.restaurant = (char *) gtk_combo_box_get_active_id(GTK_COMBO_BOX(tempWidget));


    if((error = loadGladeFile(&builder,"infoQrcode.glade")) == NULL){
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