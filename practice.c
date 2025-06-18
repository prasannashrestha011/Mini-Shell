#include "./headers/repel.h"
#include "./structs/input_buffer.h"
#include "status_bits.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
InputBuffer *new_input_buffer() {
  InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;
  return input_buffer;
}

int main(int argc, char *argv[]) {
  InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
  while (true) {
    print_prompt();
    read_prompt(input_buffer);
    if (input_buffer->buffer[0] == '.') {
      switch (do_meta_command(input_buffer)) {
      case META_COMMAND_SUCCESS:
        break;
      case META_COMMAND_UNRECOGNIZED_COMMAND:
        puts("Unknow meta command ");
        continue;
      }
    }
    Statement statement;
    switch (prepare_result(input_buffer, &statement)) {
    case PREPARE_SUCCESS:
      break;
    case PREPARE_UNRECOGNIZED_STATEMENT:
      puts("Unknow statement ");
      continue;
    }
    execute_statement(&statement);
  }
  return 0;
}
