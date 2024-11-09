#include "header.h"

// Tokenize string
void tokenize_string(char *line, void (*function)(void*)) {
  const char delim[] = " \t\n";
  char *token = strtok(line, delim);

  while(token != NULL) {
    (*analyze)(token);
    token = strtok(NULL, delim);
  }
}
