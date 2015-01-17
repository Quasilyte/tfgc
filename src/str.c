#include "str.h"

#define MAX_LEN 96

static char* Alloc(size_t len) {
  return malloc(len + 1);
}

static void LenCheck(const char *s) {
  asrt_True(strlen(s) <= MAX_LEN, E_STR_LEN);
}

char* str_New(const char *s) {
  LenCheck(s);

  char *str = Alloc(strlen(s));
  strcpy(str, s);

  return str;
}
