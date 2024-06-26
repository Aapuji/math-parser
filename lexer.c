#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "lexer.h"

Lexer init_lexer(const char *src) {
    return (Lexer) {
        .start = src,
        .current = src,
        .line = 1
    };
}

void advance(Lexer *lexer) {
    lexer->current++;
}

static bool is_at_end(Lexer *lexer) {
    return *lexer->current == '\0';
}

static bool is_whitespace(char c) {
    return isspace((int) c);
}

static bool is_alpha(char c) {
    return isalpha((int) c);
}

static bool is_numeric(char c) {
    return c >= '0' && c <= '9';
}

static bool is_ident(char c) {
    return is_alpha(c)
        || is_numeric(c)
        || c == '_';
}

static is_operator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
    };
}

static void skip_whitespace(Lexer *lexer) {
    while (is_whitespace(*lexer->current)) {
        if (*lexer->current == '\n')
            lexer->line++;
        
        advance(lexer);
    }
}

static Token lex_ident(Lexer *lexer) {
    char *lexeme_start = lexer->current;

    int i = 1;
    advance(lexer);
    for (; is_ident(*lexer->current); i++, advance(&lexer));

    char *lexeme_end = lexer->current[-1];

    return (Token) {
        .type = TT_IDENT,
        .start = lexeme_start,
        .len = i,
        .line = lexer->line
    };
}

static Token lex_number(Lexer *lexer) {}

static Token lex_operator(Lexer *lexer) {}

static void report_error(Lexer *lexer) {}

static Token lex_token(Lexer *lexer) {
    char c = *lexer->current;

    skip_whitespace(lexer);
    
    if (is_alpha(c)) {
        lex_ident(lexer);
    } else if (is_numeric(c)) {
        lex_number(lexer);
    } else if (is_operator(c)) {
        lex_operator(lexer);
    } else {
        report_error(lexer);
    }
}


