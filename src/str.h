#ifndef STR_H_
#define STR_H_

#include <string.h>
#include <stdlib.h>

#include "e.h"
#include "asrt.h"

#define STR_SKIP_WHILE(s, expr) while(*s && expr) {}

char* str_New(const char *s);

#endif
