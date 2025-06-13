#include <stdio.h>
#include <sys/types.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
  char *buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;
InputBuffer *new_input_buffer() {
  InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
  input_buffer->buffer_length = 1024;
  input_buffer->buffer = NULL;
  input_buffer->input_length = 0;
  return input_buffer;
}
void print_prompt(){
  printf("db> ");
}
void read_prompt(InputBuffer* input_buffer){
  ssize_t bytes_read=getline(&(input_buffer->buffer),&(input_buffer->buffer_length),stdin);
  if(bytes_read<=0){
    printf("Input failure");
    exit(EXIT_FAILURE);
  }
  input_buffer->input_length=bytes_read-1;
  input_buffer->buffer[bytes_read-1]=0;
}
void close_input_buffer(InputBuffer* input_buffer){
  free(input_buffer->buffer);
  free(input_buffer);
}
int main(int argc, char *argv[]) {
  InputBuffer *input_buffer = new_input_buffer();
  while(true){
  print_prompt();
  read_prompt(input_buffer);
  if(strcmp(input_buffer->buffer,".exit")==0){
      close_input_buffer(input_buffer);
      exit(EXIT_SUCCESS);
    }
 }
}
