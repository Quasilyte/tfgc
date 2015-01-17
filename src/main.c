#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "e.h"
#include "gc.h"
#include "asrt.h"
#include "flag.h"
#include "echo.h"

const char *Target;

static void SetTarget(const char *s) {
  asrt_True(Target == NULL, E_ARG_MLT_PATH);
  Target = s;
}

static void MajorFlag(const char c) {
  switch(c) {
    case 'S': FLAG_SET(FLAG_SAFE); break;
    case 'A': FLAG_SET(FLAG_ALL); break;

    default:
      printf("warning: unknown major flag '%c' (ignored)\n", c);
  }
}

static void MinorFlag(const char c) {
  switch(c) {
    case 'd': FLAG_REGISTER(FLAG_D); break;
    case 't': FLAG_REGISTER(FLAG_T); break;
    case 'c': FLAG_REGISTER(FLAG_C); break;
    case 'p': FLAG_REGISTER(FLAG_P); break;
    case 'l': FLAG_REGISTER(FLAG_L); break;
    case 'w': FLAG_REGISTER(FLAG_W); break;

    case 'h': echo_Usage();
    case 'v': echo_Version();

    default:
      printf("warning: unknown minor flag '%c' (ignored)\n", c);
  }
}

static void ResolveFlag(const char c) {
  if(isupper(c)) {
    MajorFlag(c);
  } else {
    MinorFlag(c);
  }
}

static void ArgsScan(int argc, const char **argv) {
  for(int i = 1; i < argc; ++argv, ++i) {
    if(**argv != '-') {
      SetTarget(*argv);
    } else {
      ResolveFlag(*(*argv + (*(*argv + 1) == '-' ? 2 : 1)));
    }
  }
}

static void DefaultFallback(void) {
  if(flag_Bits == FLAG_EMPTY) {
    FLAG_REGISTER(FLAG_SAFE);
  }
}

static void ArgsValidate(void) {
  asrt_False(Target == NULL, E_ARG_NO_PATH);
  DefaultFallback();
}

static void ParseArgs(int argc, const char **argv) {
  asrt_True(argc > 1, E_ARG_ZERO);
  ArgsScan(argc, argv);
  ArgsValidate();
}

int main(int argc, const char **argv) {
  argv += 1;

  ParseArgs(argc, argv);

  gc_Launch(Target);
  printf("done\n");

  return EXIT_SUCCESS;
}