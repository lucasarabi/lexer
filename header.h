#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize_string(char *line, void (*function)(void*));
void analyze(char *token);
