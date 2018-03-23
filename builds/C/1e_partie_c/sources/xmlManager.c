/* Created by Medhi FOULGOC 18/03/2018 */
#include "../headers/xmlManager.h"

int xmlNode(int i, Validate * workerInfoSurname, Validate * workerInfoName, Validate * workerInfoSecu, Validate * workerInfoEmail, Validate * workerInfoRestaurant, Validate * workerInfoJob, char *filename){
  FILE * fp;
  fp = fopen(filename,"a");
  switch (i) {
    case 0:
      fputs("\t\t<SurnameEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfoSurname);
      fputs("\t\t</SurnameEntry>\n",fp);
      break;
    case 1:
      fputs("\t\t<NameEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfoName);
      fputs("\t\t</NameEntry>\n",fp);
      break;
    case 2:
      /*fputs("\t\t<BirthdayEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", (*workerInfo).birthday);
      fputs("\t\t</BirthdayEntry>\n",fp);*/
      break;
    case 3:
      fputs("\t\t<NumSecuEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfoSecu);
      fputs("\t\t</NumSecuEntry>\n",fp);
      break;
    case 4:
      fputs("\t\t<EmailEntry>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfoEmail);
      fputs("\t\t</EmailEntry>\n",fp);
      break;
    case 5:
      fputs("\t\t<RestaurantComboBox>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfoRestaurant);
      fputs("\t\t</RestaurantComboBox>\n",fp);
      break;
    case 6:
      fputs("\t\t<PosteComboBox>\n",fp);
      fprintf(fp, "\t\t\t%s\n", workerInfoJob);
      fputs("\t\t</PosteComboBox>\n",fp);
      break;
    default:
      fclose(fp);
      return -1;
  }
  fclose(fp);
  return 0;
}

int xmlManager(Validate * workerInfoSurname, Validate * workerInfoName, Validate * workerInfoSecu, Validate * workerInfoEmail, Validate * workerInfoRestaurant, Validate * workerInfoJob){
  time_t timestamp;
  struct tm * t;
  char date[1000];
  char filename[1000];
  char tempChar;

  FILE *fp;
  timestamp = time(NULL);
  t = localtime(&timestamp);
  // Protocole de nomenclature
  strcat(filename, workerInfoName);
  strcat(filename, workerInfoSurname);
  sprintf(date,"%d",t->tm_mon);
  strcat(filename, date);
  sprintf(date,"%d",1900+t->tm_year);
  strcat(filename, date);
  strcat(filename,".xml");
  //Recherche du nom du fichier, s'il existe déjà ou non
  fp = fopen(filename,"a+");
  printf("creating file\n");
  fputs("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n",fp);
  printf("test1\n");
  fputs("<employee title=\"",fp);
  fprintf(fp, "%s", filename);
  fputs("\">\n", fp);
  fputs("\t<informations>\n",fp);
  fclose(fp);
  printf("file created\n");
  for(int i = 0; i < 7; i++){
    xmlNode(i, workerInfoSurname, workerInfoName, workerInfoSecu, workerInfoEmail, workerInfoRestaurant, workerInfoJob, filename);
  }
  fp = fopen(filename,"a+");
  fputs("\t</informations>\n",fp);
  fputs("</employee>",fp);
  fclose(fp);
  return 0;
}
