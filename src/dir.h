#ifndef DIR_H_
#define DIR_H_

/*
 * Posix-compatible directory access
 */

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#include "e.h"
#include "asrt.h"
#include "file.h"

unsigned dir_Open(const char *name);
void dir_Close(void);

char* dir_Fetch(void);

#endif
