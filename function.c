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

int defineEntry (int positionVerif, char *actualEntry){
    switch (positionVerif) {
      case 0:
        strcpy(actualEntry, nameEntry);
        break;
      case 1:
        strcpy(actualEntry, surnameEntry);
        break
      case 2:
        strcpy(actualEntry, dateEntry);
        break;
      case 3:
        strcpy(actualEntry, secuEntry);
        break
      case 4:
        strcpy(actualEntry, emailEntry);
        break;
      case 5:
        strcpy(actualEntry, postEntry);
        break
      case 6:
        strcpy(actualEntry, restaurantEntry);
        break;
    }
    return 0;
}

int selectEntry (GtkWidget *entry, char *actualEntry, int positionVerif){
    defineEntry(positionVerif, actualEntry);
    entry = GTK_WIDGET(gtk_builder_get_object(builder, actualEntry));
    if(entry != NULL)
      return 0;
    else
      return -1;

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

int entryVerification (int *entryVerification, GtkWidget *entry, int positionVerif, char *actualEntry, char **savedEntry){
    selectEntry(entry, actualEntry, positionVerif);
    switch (positionVerif) {
      case 0:
        textVerification(actualEntry, entryVerification, positionVerif);
        break;
      case 1:
        textVerification(actualEntry, entryVerification, positionVerif);
        break
      case 2:
        dateVerification(actualEntry, entryVerification, positionVerif);
        break;
      case 3:
        secuVerification(actualEntry, entryVerification, positionVerif);
        break
      case 4:
        emailVerification(actualEntry, entryVerification, positionVerif);
        break;
      case 5:
        postOrRestaurantVerification(actualEntry, entryVerification, positionVerif);
        break
      case 6:
        postOrRestaurantVerification(actualEntry, entryVerification, positionVerif);
        break;
    }
}

int saveEntry (int *entryVerification, GtkWidget *entry, int positionVerif, char **savedEntry){
  if(actualEntry != NULL){
    savedEntry[positionVerif] = "y";
    savedEntry[positionVerif][positionVerif] = actualEntry;
    return 0;
  }
  else
    return -1;
}
