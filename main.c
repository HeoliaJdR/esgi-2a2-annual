#include <stdio.h>
#include <stdlib.h>
#include "qrcodegen.h"
#include <gtk/gtk.h>
#include "function.h"
#include "constant.h"

int main(int argc,char** argv) {
    char *array = NULL;
    char *actualEntry = NULL;
    char **savedEntry = NULL;
    int *entryVerification = NULL;


    GtkWidget *window;
    GtkWidget *picture;
    GtkBuilder *builder;
    GtkWidget *entry;
    GdkPixbuf * pixbuf;

// Allocation mémoire du tableau de verification des entry
    entryVerification = malloc(sizeof(int)*7);
    actualEntry = malloc(sizeof(char)*20);
    savedEntry = malloc(sizeof(char)*7);
    for(int i = 0; i < 7; i++){
      savedEntry[i] = malloc(sizeof(char)*20);
    }

    gtk_init(&argc,&argv);
    loadGladeFile(&builder,"QRCODE.glade");
    window = (GtkWidget *) gtk_builder_get_object(builder,"windowQrcode");

// Text data
    uint8_t qr0[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    bool ok = qrcodegen_encodeText("Hello, world!",
                                   tempBuffer, qr0, qrcodegen_Ecc_MEDIUM,
                                   qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX,
                                   qrcodegen_Mask_AUTO, true);
    if (!ok)
        return 0;

    int size = qrcodegen_getSize(qr0);
    array = malloc(sizeof(char)*((size + 6)*(size+6)*3));
    for (int i = 0; i < 3 * ((size+6)*3); ++i) {
        array[i] = (char) 255;
    }
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size + 6; x++) {
            printf("%d \n", (y * size * 3) + (x * 3) + (3*size*3));
            if(x < 3 || x > size + 3){
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3)] = (char) 255;
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3) + 1] = (char) 255;
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3) + 2] = (char) 255;
            }
            else if(qrcodegen_getModule(qr0, x - 3, y) == 0 ){
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3)] = (char) 255;
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3) + 1] = (char) 255;
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3) + 2] = (char) 255;
            }else{
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3)] = (char) 0;
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3) + 1] = (char) 0;
                array[(y * (size + 6) * 3) + (x * 3) + (3 * (size + 6) * 3) + 2 ] = (char) 0;
            }
        }
    }
    printf("%d \n", (size*(size*3)) + (3 * (size * 3)));
    for (int i = (size* (size + 6) * 3) + (3 * ((size + 6) * 3)); i < (size* (size + 6) * 3) + (6 * ((size + 6) * 3)); ++i) {
        array[i] = (char) 255;
    }
    pixbuf = gdk_pixbuf_new_from_data((const guchar*) array,GDK_COLORSPACE_RGB,FALSE,8,size + 6,size+6,(size + 6) * 3,NULL,NULL);
    picture =(GtkWidget *) gtk_builder_get_object(builder,"etapeImage");
    pixbuf = gdk_pixbuf_scale_simple(pixbuf,200,200,GDK_INTERP_HYPER);
    gtk_image_set_from_pixbuf(GTK_IMAGE(picture),pixbuf);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
