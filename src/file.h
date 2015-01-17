#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

#include "e.h"
#include "str.h"
#include "asrt.h"
#include "tconv.h"

int file_HasParent(const char *s);
int file_IsTemp(const char *s);
int file_IsHidden(const char *s);
int file_IsPkg(const char *s);
int file_IsWinBin(const char *s);
int file_IsDuplicate(const char *s);
int file_IsCopy(char *s);
int file_IsDir(const char *s);

time_t file_GetAge(const char *s);

void file_Delete(const char *name, const char cause);

#endif
