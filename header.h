#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

typedef struct arguments {
    int line_num;
    char *token;
} args;

args* create_args(char *token);
void init_args(args *my_args, int my_line_num, char *my_token);
void kill_args(args *my_args);

void analyze_single_char_tokens(args *line);
void tokenize_string(char *line, int line_num, void(*function)(args*));
