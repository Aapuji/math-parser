#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>


/*

Ident, Operators, Numbers

*/

typedef enum {
    // Single Character
    TT_LEFT_PAREN, TT_RIGHT_PAREN, TT_PLUS, TT_MINUS, TT_STAR, TT_SLASH, TT_CARAT,
    // Literals
    TT_IDENT, TT_NUMBER,

    TT_ERR, TT_EOF
} TokenType;

typedef struct {
    TokenType type;
    const char *start;
    int len;
    int line;
} Token;

typedef struct {
    const char *start;
    const char *current;
    int line;
} Lexer;

Lexer init_lexer(const char *src);

#endif
