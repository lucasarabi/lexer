#include "header.h"
#include "lexeme_table.h"

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

entry *create_entry(char *value) {
    return (entry*)malloc(sizeof(int) + sizeof(TokenType) + sizeof(value));
}

void init_entry(entry* my_entry, int my_line_num, TokenType my_type, char *my_value) {
    my_entry->line_num = my_line_num;
    my_entry->type = my_type;
    strcpy(my_entry->value, my_value);
}

void kill_entry(entry *my_entry) {
    free(my_entry->value);
    free(my_entry);
}


void analyze(args *arguments) {
    // Unpack arguments
    int line_num = arguments->line_num;
    char* token = arguments->token;

    // Write analysis here
    printf("%d %s\n", line_num, token);
}