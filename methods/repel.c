#include "../headers/repel.h"
#include "../headers/status.h"
#include "../structs/input_buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
void read_prompt(InputBuffer *input_buffer) {
  ssize_t bytes_read =
      getline(&input_buffer->buffer, &input_buffer->buffer_length, stdin);
  if (bytes_read <= 0) {
    puts("Input failure");
    exit(EXIT_FAILURE);
  }
  input_buffer->input_length = bytes_read - 1;
  input_buffer->buffer[bytes_read - 1] = 0;
}
void print_prompt() { printf("db>"); }

MetaCommandResult do_meta_command(InputBuffer *input_buffer) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
    return META_COMMAND_SUCCESS;
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}
PrepareResult prepare_result(InputBuffer *input_buffer, Statement *statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }
  if (strcmp(input_buffer->buffer, "select") == 0) {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }
  return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement *statement) {
  switch (statement->type) {
  case STATEMENT_SELECT:
    puts("SELECT statement running");
    break;
  case STATEMENT_INSERT:
    puts("Print statement running");
    break;
  }
}
