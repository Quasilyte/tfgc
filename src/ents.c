#include "ents.h"

#define MAX_NAME_LEN 96
#define LAST_ENT (Ents.names[Ents.count])
#define NOT_LAST(ent) (ent - Ents.names != Ents.count)

void ents_Init(const char *path) {
  Ents.count = dir_Open(path);

  Ents.origin = str_New(path);
  Ents.names = malloc((Ents.count + 1) * sizeof(char*));
  Ents.names[Ents.count] = NULL;

  for(unsigned i = 0u; i < Ents.count; ++i) {
    Ents.names[i] = str_New(dir_Fetch());
  }

  dir_Close();
}

void ents_Delete(char **ent, const char cause) {
  file_Delete(*ent, cause);
  free(*ent);

  Ents.count -= 1;

  if(NOT_LAST(ent)) {
    *ent = LAST_ENT;
  }

  LAST_ENT = NULL;
}

void ents_Free(void) {
  for(unsigned i = 0u; i < Ents.count; ++i) {
    free(Ents.names[i]);
  }

  free(Ents.origin);
  free(Ents.names);
}