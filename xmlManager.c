#include "xmlManager.h"

int

int xmlManager(Validate * workerInfo){
  WIN32_FIND_DATA File;
  HANDLE hSearch;
  time_t timestamp;
  struct tm * t;
  char date[1000];
  char filename[1000];
  char filecontent[10000];

  FILE *fp;

  timestamp = time(NULL);
  t = localtime(&timestamp);

  strcat(filename, workerInfo.surname[0]);
  strcat(filename, workerInfo.name);
  sprintf(date,"year%d",t->tm_month);
  strcat(filename, date);
  sprintf(date,"year%d",1900+t->tm_year);
  strcat(filename, date);
  strcat(filename,".xml");
  hSearch = FindFirstFile(filename, &File);
  if (hSearch != INVALID_HANDLE_VALUE){
    fp = fopen(filename,"a");
    fputs("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n",fp);
    fprintf(fp, "<employee title=\"%s\">\n", filename);
    fputs("\t<informations>\n",fp);
    for(int i = 0; i < 7; i++){

    }
    fputs("\t</informations>\n",fp);
    fputs("</employee>",fp);
    fclose(fp);
  }
}
