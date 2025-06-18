#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H
#include <sys/types.h>
typedef struct {
  char *buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;
#endif // !
