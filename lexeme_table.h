typedef enum {
    // Keywords
    TOKEN_INT,
    TOKEN_BOOL,
    TOKEN_FLOAT,
    TOKEN_CHAR,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_MAIN,

    // Literals
    TOKEN_INTEGER_LITERAL,
    TOKEN_BOOLEAN_LITERAL,   // true or false
    TOKEN_FLOAT_LITERAL,
    TOKEN_CHAR_LITERAL,

    // Identifiers
    TOKEN_IDENTIFIER,

    // Operators
    TOKEN_ASSIGN,            // =       !!!
    TOKEN_EQUAL,             // ==
    TOKEN_NOT_EQUAL,         // !=
    TOKEN_LESS_THAN,         // <       !!!
    TOKEN_LESS_EQUAL,        // <=
    TOKEN_GREATER_THAN,      // >       !!!
    TOKEN_GREATER_EQUAL,     // >=
    TOKEN_LOGICAL_OR,        // ||
    TOKEN_LOGICAL_AND,       // &&
    TOKEN_PLUS,              // +       !!!
    TOKEN_MINUS,             // -       !!!
    TOKEN_ASTERISK,          // *       !!!
    TOKEN_SLASH,             // /       !!!
    TOKEN_PERCENT,           // %       !!!
    TOKEN_UNARY_MINUS,       // -       !!!
    TOKEN_LOGICAL_NOT,       // !

    // Punctuation
    TOKEN_LPAREN,            // (       !!!
    TOKEN_RPAREN,            // )       !!!
    TOKEN_LBRACKET,          // [       !!!
    TOKEN_RBRACKET,          // ]       !!!
    TOKEN_LBRACE,            // {       !!!
    TOKEN_RBRACE,            // }       !!!
    TOKEN_COMMA,             // ,       !!!
    TOKEN_SEMICOLON,         // ;       !!!

    // End of file
    TOKEN_EOF,

    // Error handling
    TOKEN_UNKNOWN            // Unrecognized token
} TokenType;

typedef struct lexeme_table_entry {
    int line_num;
    TokenType type;
    char *value;
} entry;