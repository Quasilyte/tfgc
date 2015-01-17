#include "echo.h"

void echo_Usage(void) {
  printf("tfgc - temporary file garbage collector\n\n");

  printf("syntax: 'tfgc [flags] target',\n");
  printf("where 'target' is absolute or relative path to directory\n\n");

  printf("example: 'tfgc -d -t -l /home/Fooman/Downloads'\n\n");

  printf("supported flags:\n\n");

  printf("\t-d --d: removes file if it have parens with index like 'f(1).c'\n");
  printf("\t-t --t: targets file with 't_' prefix and age > 24 hours\n");
  printf("\t-c --c: deletes file with 'copy of' prefix if origin exists\n");
  printf("\t-p --p: unlinks all package files (ext = deb || pkg)\n");
  printf("\t-w --w: drops windows-related files (ext = exe || msi)\n");
  printf("\t-l --l: erases file which name is longer than 40 characters\n");
  printf("\t-S --S: 'play safe' mode. Turns on -d, -t, -c\n");
  printf("\t-A --A: 'agressive' mode. Turns on everything\n\n");

  printf("\t-h --h: show usage (terminates program)\n");
  printf("\t-v --v: show version (terminates program)\n\n");

  printf("written by Quasilyte -- Iskander Sharipov\n");
  exit(EXIT_SUCCESS);
}

void echo_Version(void) {
  printf("tfgc version: 1.0.0\n");
  exit(EXIT_SUCCESS);
}