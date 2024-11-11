#include "header.h"

void tokenize_string(int *block_comment_state, char *line, int line_num, void(*function)(args*)) {
    const char delim[] = " \t\n";
    char *token = strtok(line, delim);
    while(token != NULL) {
        char *start_comment = strstr(token, "/*");
        char *end_comment = strstr(token, "*/");
        if (start_comment != NULL) {
            *block_comment_state = 1;  
            *start_comment = '\0';      
            if (strlen(token) > 0) {
                args *arguments = create_args(token);
                init_args(arguments, line_num, token);
                (*function)(arguments);
                kill_args(arguments);
            }
        }
        if (*block_comment_state == 0) {
            args *arguments = create_args(token);
            init_args(arguments, line_num, token);
            (*function)(arguments);
            kill_args(arguments);
        }
        if (end_comment != NULL) {
            *block_comment_state = 0;  
            *end_comment = '\0';
            token = end_comment + 2;  
            if (strlen(token) > 0) {
                args *arguments = create_args(token);
                init_args(arguments, line_num, token);
                (*function)(arguments);
                kill_args(arguments);
            }
        }
        token = strtok(NULL, delim);
    }
}
