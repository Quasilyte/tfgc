#include "dir.h"

static struct {
  DIR *p;
  struct dirent *entity;
} Dir;

static unsigned EntCount(void) {
  unsigned count = 0u;

  for(char *ent = dir_Fetch(); ent; ent = dir_Fetch(), ++count) {
  }

  rewinddir(Dir.p);
  return count;
}

unsigned dir_Open(const char *name) {
  printf("entering '%s' folder to perform cleanup\n", name);

  Dir.p = opendir(name);
  asrt_True(Dir.p, E_DIR_OPEN);

  asrt_False(chdir(name) == -1, E_DIR_ENTER);

  return EntCount();
}

void dir_Close(void) {
  if(Dir.p) {
    closedir(Dir.p);
  }
}

char* dir_Fetch(void) {
  if((Dir.entity = readdir(Dir.p))) {
    if(file_IsHidden(Dir.entity->d_name) || file_IsDir(Dir.entity->d_name)) {
      return dir_Fetch();
    }

    return Dir.entity->d_name;
  }

  return NULL;
}
