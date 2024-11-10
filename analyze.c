#include "header.h"

args* create_args(char *token) {
    return (args*)malloc(sizeof(int) + sizeof(token));
}

void init_args(args *my_args, int my_line_num, char *my_token) {
    my_args->line_num = my_line_num;
    my_args->token = (char*)malloc(sizeof(my_token));
    strcpy(my_args->token, my_token);
}

void kill_args(args *my_args) {
    free(my_args->token);
    free(my_args);
}

void analyze(args *arguments) {
    // Write analysis here
    printf("%d %s\n", arguments->line_num, arguments->token);
}