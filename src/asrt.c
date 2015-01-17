#include "asrt.h"

void asrt_False(_Bool expr, const char *const msg) {
  if(expr) {
    printf("error: %s\n", msg);
    exit(EXIT_FAILURE);
  }
}

void asrt_True(_Bool expr, const char *const msg) {
  asrt_False(!expr, msg);
}