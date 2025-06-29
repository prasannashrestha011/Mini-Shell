#ifndef STATUS_H
#define STATUS_H
typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND,
} MetaCommandResult;
typedef enum {
  STATEMENT_INSERT,
  STATEMENT_SELECT,
} StatementType;
typedef struct {
  StatementType type;
} Statement;

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

#endif // !STATUS_H
