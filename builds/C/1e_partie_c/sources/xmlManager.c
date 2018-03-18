#include "../headers/function.h"

int xmlNode(int i, Validate * workerInfo, char filename[1000]){

  fp = fopen(filename,"a");
  switch (i) {
    case 0:
      fputs("\t\t<SurnameEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfo.surname);
      fputs("\t\t</SurnameEntry>\n",fp);
      break;
    case 1:
      fputs("\t\t<NameEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfo.name);
      fputs("\t\t</NameEntry>\n",fp);
      break;
    case 2:
      fputs("\t\t<BirthdayEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfo.birthday);
      fputs("\t\t</BirthdayEntry>\n",fp);
      break;
    case 3:
      fputs("\t\t<NumSecuEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfo.numsecu);
      fputs("\t\t</NumSecuEntry>\n",fp);
      break;
    case 4:
      fputs("\t\t<EmailEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfo.email);
      fputs("\t\t</EmailEntry>\n",fp);
      break;
    case 5:
      fputs("\t\t<RestaurantComboBox>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfo.restaurant);
      fputs("\t\t</RestaurantComboBox>\n",fp);
      break;
    case 6:
      fputs("\t\t<PosteComboBox>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfo.poste);
      fputs("\t\t</PosteComboBox>\n",fp);
      break;
    default:
      fclose(fp);
      return -1;
  }
  fclose(fp);
  return 0;
}

int xmlManager(Validate * workerInfo){
  WIN32_FIND_DATA File;
  HANDLE hSearch;
  time_t timestamp;
  struct tm * t;
  char date[1000];
  char filename[1000];
  char **information = NULL;

  FILE *fp;
  timestamp = time(NULL);
  t = localtime(&timestamp);
  // Protocole de nomenclature
  strcat(filename, workerInfo.surname[0]);
  strcat(filename, workerInfo.name);
  sprintf(date,"year%d",t->tm_month);
  strcat(filename, date);
  sprintf(date,"year%d",1900+t->tm_year);
  strcat(filename, date);
  strcat(filename,".xml");
  //Recherche du nom du fichier, s'il existe déjà ou non
  hSearch = FindFirstFile(filename, &File);
  if (hSearch != INVALID_HANDLE_VALUE){
    fp = fopen(filename,"a");
    fputs("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n",fp);
    fprintf(fp, "<employee title=\"%s\">\n", filename);
    fputs("\t<informations>\n",fp);
    fclose(fp);
    for(int i = 0; i < 7; i++){
      xmlNode(i, workerInfo, filename[1000]);
    }
    fputs("\t</informations>\n",fp);
    fputs("</employee>",fp);
    fp = fopen(filename,"a");
    fclose(fp);
  }
}
