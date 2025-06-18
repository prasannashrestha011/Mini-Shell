#ifndef REPEL_H
#define REPEL_H
#include "../headers/status.h"
#include "../structs/input_buffer.h"
void read_prompt(InputBuffer *input_buffer);
void print_prompt();
MetaCommandResult do_meta_command(InputBuffer *input_buffer);
PrepareResult prepare_result(InputBuffer *input_buffer, Statement *statement);
void execute_statement(Statement *statement);
#endif // !REPEL_H
