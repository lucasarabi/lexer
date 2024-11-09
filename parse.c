#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void analyze(char *token) {
	printf("%s\n", token);
}

// Tokenize string
// 	Iterate through string token by token, ignoring whitespace, and apply the function
// 	passed as an argument to the token; token will be stored in memory as a string.
//
// @param string to parse, pointer to function to apply to token
// @return void 
//
void tokenize_string(char *line, void (*analyze)(char*)) {
	const char delim[] = " \t\n";
	char *token = strtok(line, delim);

	while(token != NULL) {
		(*analyze)(token);
		token = strtok(NULL, delim);
	}
}

// Main function is purely for testing. Delete later
int main() {
	char str[] = "hello world!!!\0";
	tokenize_string(str, &analyze);

	return 0;
}
