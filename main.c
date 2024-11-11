#include "header.h"

#define BUFF_SIZE 10000

// Framework by which to read an input file in C for lexer project
// Principles of Programming Languages
//
// Diego Angueira
// Lucas Arabi
//

int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Error: File not found\n");
        exit(EXIT_FAILURE);
    }
    FILE *input = fopen(argv[1], "r");
    if(input == NULL) {
        fprintf(stderr, "Error: File not found\n");
        exit(EXIT_FAILURE);
    }
    
    char *line_buf = (char*)malloc(BUFF_SIZE);
    int block_comment_state = 0;
    int line_num = 1;

    while(fgets(line_buf, BUFF_SIZE, input) != NULL) {
        char *comment_start = strstr(line_buf, "//");
        if (comment_start != NULL) *comment_start = '\0';
        tokenize_string(&block_comment_state, line_buf, line_num, &analyze);
        line_num++;
    }
}
