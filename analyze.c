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
        case TOKEN_INT: return "TOKEN_INT";
        case TOKEN_BOOL: return "TOKEN_BOOL";
        case TOKEN_FLOAT: return "TOKEN_FLOAT";
        case TOKEN_CHAR: return "TOKEN_CHAR";
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
        case TOKEN_ASTERISK: return "TOKEN_ASTERISK";
        case TOKEN_SLASH: return "TOKEN_SLASH";
        case TOKEN_PERCENT: return "TOKEN_PERCENT";
        case TOKEN_UNARY_MINUS: return "TOKEN_UNARY_MINUS";
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

void analyze(args *arguments) {
    // Unpack arguments
    int line_num = arguments->line_num;
    char* token = arguments->token;

    // Write analysis here
    /*  BLUEPRINT FOR table_entry INTIALIZATION
    entry *table_entry = create_entry(token);
    init_entry(table_entry, line_num, TOKEN_UNKNOWN, token);
    printf("%s\n", entry_to_string(table_entry));
    */
}