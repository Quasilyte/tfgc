#ifndef TCONV_H_
#define TCONV_H_

#include <time.h>

#define TCONV_S_SINCE(x) (time(NULL) - x)
#define TCONV_M_SINCE(x) (TCONV_S_SINCE(x) / 60)
#define TCONV_H_SINCE(x) (TCONV_M_SINCE(x) / 60)

#endif