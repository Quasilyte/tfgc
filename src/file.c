#include "file.h"

#define GIVE_STAT(s, expr) stat(s, &FileInfo); return expr;

#define CP_PREFIX_OFFSET 8

static struct stat FileInfo;

const char* GetExt(const char *s) {
  size_t len = strlen(s);
  const char *p = s + len;

  while(p > s && *(p - 1) != '.') {
    --p;
  }

  return p;
}

int Exists(const char *s) {
  if(access(s, F_OK) != -1) {
    return 1;
  } else {
    return 0;
  }
}

static FILE* Open(const char *name) {
  FILE *file = fopen(name, "r");
  asrt_True(file, E_FILE_OPEN);

  return file;
}

static int Equal(const char *name1, const char *name2) {
  FILE *f1 = Open(name1), *f2 = Open(name2);

  char c1, c2;
  do {
    c1 = fgetc(f1), c2 = fgetc(f2);
  } while(c1 != EOF && c2 != EOF && c1 == c2);

  int res = ftell(f1) == ftell(f2) && c1 == c2;

  fclose(f1), fclose(f2);
  return res;
}

int file_HasParent(const char *s) {
  const char *parentName = s + CP_PREFIX_OFFSET;

  return Exists(parentName) && Equal(s, parentName);
}

int file_IsTemp(const char *s) {
  return *s == 't' && *(s + 1) == '_';
}

int file_IsHidden(const char *s) {
  return *s == '.';
}

int file_IsPkg(const char *s) {
  const char *ext = GetExt(s);
  return !strcmp(ext, "deb") || !strcmp(ext, "pkg");
}

int file_IsWinBin(const char *s) {
  const char *ext = GetExt(s);
  return !strcmp(ext, "exe") || !strcmp(ext, "msi");
}

int file_IsDuplicate(const char *s) {
  STR_SKIP_WHILE(s, *s++ != '(');
  STR_SKIP_WHILE(s, isdigit(*s++));

  return *s == '.';
}

int file_IsCopy(char *s) {
  char swap = *(s + CP_PREFIX_OFFSET);
  *(s + CP_PREFIX_OFFSET) = '\0';

  int res = !strcmp(s, "copy of ");
  *(s + CP_PREFIX_OFFSET) = swap;

  return res;
}

int file_IsDir(const char *s) {
  GIVE_STAT(s, S_ISDIR(FileInfo.st_mode));
}

time_t file_GetAge(const char *s) {
  GIVE_STAT(s, TCONV_S_SINCE(FileInfo.st_mtime));
}

void file_Delete(const char *name, const char cause) {
  printf("  unlinking '%s' file (flag=%c)\n", name, cause);
  asrt_False(unlink(name) == -1, E_FILE_UNLINK);
}
