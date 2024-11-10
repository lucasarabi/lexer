#include "header.h"

void tokenize_string(char *line, int line_num, void(*function)(args*)) {
    const char delim[] = " \t\n";
    char *token = strtok(line, delim);

    while(token != NULL) {
        args *arguments = create_args(token); 
        init_args(arguments, line_num, token);
        (*function)(arguments);
        token = strtok(NULL, delim);
        kill_args(arguments);
    }
}
