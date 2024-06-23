#include <stdbool.h>
#include <string.h>

#include "lexer.h"

Lexer init_lexer(const char *src) {
    return (Lexer) {
        .start = src,
        .current = src,
        .line = 1
    };
}

static bool is_at_end(Lexer *lexer) {
    return *lexer->current == '\0';
}

static is_whitespace(char c) {}

static is_alpha(char c) {}

static is_numeric(char c) {}

static is_operator(char c) {}

static void skip_whitespace(Lexer *lexer) {

}

static Token lex_ident(Lexer *lexer) {}

static Token lex_number(Lexer *lexer) {}

static Token lex_operator(Lexer *lexer) {}

static void report_error(Lexer *lexer) {}

static Token lex_token(Lexer *lexer) {
    char c = lexer->current;

    if (is_whitespace(c)) {
        skip_whitespace(&lexer);
    } else if (is_alpha(c)) {
        lex_ident(&lexer);
    } else if (is_numeric(c)) {
        lex_number(c);
    } else if (is_operator(c)) {
        lex_operator(c);
    } else {
        report_error(&lexer);
    }
}


