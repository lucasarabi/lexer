#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analyze(char *line);
void tokenize_string(char *line, void(*function)(char*));
