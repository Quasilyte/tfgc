#include "gc.h"

void ProcessFiles(void) {
  ENTS_WHILE(ent) {
    if(FLAG_ISSET(FLAG_T) && file_IsTemp(*ent) && file_GetAge(*ent) > 0) {
      ents_Delete(ent, 't');
    } else if(FLAG_ISSET(FLAG_P) && file_IsPkg(*ent)) {
      ents_Delete(ent, 'p');
    } else if(FLAG_ISSET(FLAG_D) && file_IsDuplicate(*ent)) {
      ents_Delete(ent, 'd');
    } else if(FLAG_ISSET(FLAG_C) && file_HasParent(*ent)) {
      ents_Delete(ent, 'c');
    } else if(FLAG_ISSET(FLAG_W) && file_IsWinBin(*ent)) {
      ents_Delete(ent, 'w');
    } else if(FLAG_ISSET(FLAG_L) && strlen(*ent) > 40) {
      ents_Delete(ent, 'l');
    } else {
      ++ent;
    }
  }
}

void gc_Launch(const char *target) {
  ents_Init(target);

  ProcessFiles();

  ents_Free();
}