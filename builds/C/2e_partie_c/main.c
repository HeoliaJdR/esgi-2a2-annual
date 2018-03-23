#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <dir.h>

int main(int argc, char **argv){
    WIN32_FIND_DATA File;
    HANDLE hSearch;
    time_t timestamp;
    struct tm * t;
    char directoryname[1000];
    char filename[1000];
    char filecontent[10000];
    FILE *fp;

    timestamp = time(NULL);
    t = localtime(&timestamp);

    sprintf(directoryname,"year%d",1900+t->tm_year);
    mkdir(directoryname);

    hSearch = FindFirstFile("*.xml", &File);
    strcpy(filename,directoryname);
    strcat(filename,"/");
    strcat(filename,directoryname);
    strcat(filename,".xml");
    fp = fopen(filename,"a");
    fputs("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<archive>\n",fp);
    fclose(fp);
    if (hSearch != INVALID_HANDLE_VALUE){
        do {
            printf("%s\n", File.cFileName);
            fp = fopen(File.cFileName,"rb");
            fseek(fp,40,SEEK_SET);
            fread(filecontent,sizeof(char),10000,fp);
            fclose(fp);
            filecontent[strlen(filecontent)-1]='\n';
            fp = fopen(filename,"a");
            fputs(filecontent,fp);
            fclose(fp);
        } while (FindNextFile(hSearch, &File));

        FindClose(hSearch);
        fp = fopen(filename,"a");
        fputs("</archive>",fp);
        fclose(fp);
    }

    return 0;
}
