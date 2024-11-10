#include "header.h"

void tokenize_string(char *line, void(*function)(char*)) {
    const char delim[] = " \t\n";
    char *token = strtok(line, delim);
    while(token != NULL) {
        (*function)(token);
        token = strtok(NULL, delim);
    }
}
