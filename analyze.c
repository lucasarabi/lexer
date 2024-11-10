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
    entry *new_entry = (entry*)malloc(sizeof(entry));
    new_entry->value = (char*)malloc(strlen(value)+1);
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

const char* token_type_to_string(TokenType type) {
    switch (type) {
        case TOKEN_TYPE_INT: return "TOKEN_TYPE_INT";
        case TOKEN_TYPE_BOOL: return "TOKEN_TYPE_BOOL";
        case TOKEN_TYPE_FLOAT: return "TOKEN_TYPE_FLOAT";
        case TOKEN_TYPE_CHAR: return "TOKEN_TYPE_CHAR";
        case TOKEN_IF: return "TOKEN_IF";
        case TOKEN_ELSE: return "TOKEN_ELSE";
        case TOKEN_WHILE: return "TOKEN_WHILE";
        case TOKEN_MAIN: return "TOKEN_MAIN";
        case TOKEN_INTEGER_LITERAL: return "TOKEN_INTEGER_LITERAL";
        case TOKEN_BOOLEAN_LITERAL: return "TOKEN_BOOLEAN_LITERAL";
        case TOKEN_FLOAT_LITERAL: return "TOKEN_FLOAT_LITERAL";
        case TOKEN_CHAR_LITERAL: return "TOKEN_CHAR_LITERAL";
        case TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
        case TOKEN_ASSIGN: return "TOKEN_ASSIGN";
        case TOKEN_EQUAL: return "TOKEN_EQUAL";
        case TOKEN_NOT_EQUAL: return "TOKEN_NOT_EQUAL";
        case TOKEN_LESS_THAN: return "TOKEN_LESS_THAN";
        case TOKEN_LESS_EQUAL: return "TOKEN_LESS_EQUAL";
        case TOKEN_GREATER_THAN: return "TOKEN_GREATER_THAN";
        case TOKEN_GREATER_EQUAL: return "TOKEN_GREATER_EQUAL";
        case TOKEN_LOGICAL_OR: return "TOKEN_LOGICAL_OR";
        case TOKEN_LOGICAL_AND: return "TOKEN_LOGICAL_AND";
        case TOKEN_PLUS: return "TOKEN_PLUS";
        case TOKEN_MINUS: return "TOKEN_MINUS";
        case TOKEN_MULTIP: return "TOKEN_MULTIP";
        case TOKEN_DIVIDE: return "TOKEN_DIVIDE";
        case TOKEN_MODULUS: return "TOKEN_MODULUS";
        case TOKEN_LOGICAL_NOT: return "TOKEN_LOGICAL_NOT";
        case TOKEN_LPAREN: return "TOKEN_LPAREN";
        case TOKEN_RPAREN: return "TOKEN_RPAREN";
        case TOKEN_LBRACKET: return "TOKEN_LBRACKET";
        case TOKEN_RBRACKET: return "TOKEN_RBRACKET";
        case TOKEN_LBRACE: return "TOKEN_LBRACE";
        case TOKEN_RBRACE: return "TOKEN_RBRACE";
        case TOKEN_COMMA: return "TOKEN_COMMA";
        case TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";
        case TOKEN_EOF: return "TOKEN_EOF";
        case TOKEN_UNKNOWN: return "TOKEN_UNKNOWN";
        default: return "UNKNOWN_TOKEN";
    }
}

char* entry_to_string(const entry *e) {
    const char *type_str = token_type_to_string(e->type);
    const char *value_str = e->value ? e->value : "NULL";
    
    char *result = malloc(100 + strlen(value_str));
    
    snprintf(result, 100 + strlen(value_str), "Line: %d, Type: %s, Value: %s",
             e->line_num, type_str, value_str);
    return result;
}

char* trim(char* str) {
    // Trim leading spaces
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // Trim trailing spaces
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Null-terminate the string at the new end
    *(end + 1) = '\0';

    return str;
}

void analyze_single_char_tokens(args *arguments) {
    // Unpack arguments
    int line_num = arguments->line_num;
    char* token = arguments->token;

    // Write analysis here

    /*  BLUEPRINT FOR table_entry INTIALIZATION
    entry *table_entry = create_entry(token);
    init_entry(table_entry, line_num, TOKEN_UNKNOWN, token);
    printf("%s\n", entry_to_string(table_entry));
    */
    
    entry *table_entry = create_entry(token);
    for(int i = 0; i < strlen(token); i++) {
        // printf("%c\n", token[i]);
        char str[2];
        str[1] = '\0';
        switch(token[i]) {
            case '(':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_LPAREN, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case ')':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_RPAREN, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '{':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_LBRACE, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '}':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_RBRACE, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '[':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_LBRACKET, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break; 
            case ']':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_RBRACKET, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case ';':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_SEMICOLON, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;  
            case ',':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_COMMA, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '=':
                if(token[i+1] == '=' || token[i-1] == '=' || token[i-1] == '>' || token[i-1] == '<' || token[i-1] == '!') break;
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_EQUAL, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '<':
                if(token[i+1] == '=') break;
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_LESS_THAN, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '>':
                if(token[i+1] == '=') break;
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_GREATER_THAN, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '+':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_PLUS, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '-':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_MINUS, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '*':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_MULTIP, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '/':
                if(token[i+1] == '/' || token[i-1] == '/') break;
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_DIVIDE, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '%':
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_MODULUS, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
            case '!':
                if(token[i+1] == '=') break;
                str[0] = token[i];
                init_entry(table_entry, line_num, TOKEN_LOGICAL_NOT, str);
                printf("%s\n", entry_to_string(table_entry));
                token[i] = ' ';
                break;
        }  
    }
    
    token = trim(token);
    //
    // Find a way to split lines that only got separated in the switch case
    //
    printf("%s\n", token);
    if(strcmp(token, "int") == 0) {
        init_entry(table_entry, line_num, TOKEN_TYPE_INT, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "bool") == 0) {
        init_entry(table_entry, line_num, TOKEN_TYPE_BOOL, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "float") == 0) {
        init_entry(table_entry, line_num, TOKEN_TYPE_FLOAT, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "char") == 0) {
        init_entry(table_entry, line_num, TOKEN_TYPE_CHAR, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "if") == 0) {
        init_entry(table_entry, line_num, TOKEN_IF, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "else") == 0) {
        init_entry(table_entry, line_num, TOKEN_ELSE, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "while") == 0) {
        init_entry(table_entry, line_num, TOKEN_WHILE, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "main") == 0) {
        init_entry(table_entry, line_num, TOKEN_MAIN, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "true") == 0) {
        init_entry(table_entry, line_num, TOKEN_BOOLEAN_LITERAL, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "false") == 0) {
        init_entry(table_entry, line_num, TOKEN_BOOLEAN_LITERAL, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "==") == 0) {
        init_entry(table_entry, line_num, TOKEN_EQUAL, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "!=") == 0) {
        init_entry(table_entry, line_num, TOKEN_NOT_EQUAL, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "<=") == 0) {
        init_entry(table_entry, line_num, TOKEN_LESS_EQUAL, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, ">=") == 0) {
        init_entry(table_entry, line_num, TOKEN_GREATER_EQUAL, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "||") == 0) {
        init_entry(table_entry, line_num, TOKEN_LOGICAL_OR, token);
        printf("%s\n", entry_to_string(table_entry));
    }
    else if(strcmp(token, "&&") == 0) {
        init_entry(table_entry, line_num, TOKEN_LOGICAL_AND, token);
        printf("%s\n", entry_to_string(table_entry));
    }
}