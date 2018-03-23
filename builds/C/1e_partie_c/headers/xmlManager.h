#ifndef XMLMANAGER_STRUCTURE_H
#define XMLMANAGER_STRUCTURE_H
#if defined(__LINUX__)
// Linux, Android, MacOS
  #include <filesystem>
  #include <dirent.h>
#if defined(__ANDROID__)
// Android
#elif defined(__APPLE__)
// MacOS
#else
// Linux or its flavor
#endif
#elif defined(WIN32)
  #include <windows.h>
  #include <dir.h>
// Windows targets must have WIN32 (_WIN32)
#endif

#include <gtk/gtk.h>
#include <time.h>
#include "function.h"
#include "structure.h"

int xmlNode(int i, Validate * workerInfo, char *filename);

int xmlManager(Validate * workerInfo);

#endif //UNTITLED_STRUCTURE_H
