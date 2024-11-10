#include "header.h"

#define BUFF_SIZE 10000

// Framework by which to read an input file in C for lexer project
// Principles of Programming Languages
//
// Diego Angueira
// Lucas Arabi
//

int main() {
    // Open file and handle file read error
    FILE *input = fopen("file_dir/input_file.txt", "r");
    if(input == NULL) {
        fprintf(stderr, "Error: File not found\n");
        exit(EXIT_FAILURE);
    }
    
    // Line buffer    
    char *line_buf = (char*)malloc(BUFF_SIZE);
    
    // Loop line by line
    int line_num = 1;
    while(fgets(line_buf, BUFF_SIZE, input) != NULL) {
        tokenize_string(line_buf, line_num, &analyze);
        line_num++;
    }
}
