#ifndef ENTS_H_
#define ENTS_H_

#include "dir.h"
#include "str.h"
#include "file.h"

#define ENTS_WHILE(iter) \
char **iter = Ents.names; \
while(*iter)

struct {
  unsigned count;
  char *origin;
  char **names;
} Ents;

void ents_Init(const char *path);

void ents_Delete(char **ent, const char cause);

void ents_Free(void);

#endif