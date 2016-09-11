#include "util.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* vformat(const char* fmt, va_list ap) {
  char buf[256];
  vsnprintf(buf, 255, fmt, ap);
  buf[255] = 0;
  return strdup(buf);
}

char* format(const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char* r = vformat(fmt, ap);
  va_end(ap);
  return r;
}

void error(const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char* r = vformat(fmt, ap);
  va_end(ap);
  fprintf(stderr, "%s\n", r);
  exit(1);
}
