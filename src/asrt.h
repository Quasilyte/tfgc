#ifndef ASRT_H_
#define ASRT_H_

#include <stdio.h>
#include <stdlib.h>

void asrt_False(_Bool expr, const char *const msg);
void asrt_True(_Bool expr, const char *const msg);

#endif