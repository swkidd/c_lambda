#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "lexer.h"
#include "lambda_lexer.h"


char* tokenNames[] = { 
    "n/a",
    "<EOF>",
    "NAME",
    "LPAREN",
    "RPAREN",
    "GREATERTHAN"
};
const int tokenNamesLen = 6;

char* getTokenName(int x) {
    if (x < tokenNamesLen) {
        return tokenNames[x];
    }
    perror("INVALID TOKEN NAME REQUEST");
    return "";
}

Lexer_t* init_lambda_lexer(int len, char* input) {
    return init_lexer(len, input);
}

Token_t* nextToken(Lexer_t* lexer) {
    while(lexer-> c != EOF) {
        switch(lexer->c) {
            case ' ':
            case '\t':
            case '\r':
            case '\n':
              WS(lexer);
              continue;
            case '(':
              consume(lexer);
              return init_token(LPAREN_TYPE, "(", &getTokenName);
            case ')':
              consume(lexer);
              return init_token(RPAREN_TYPE, ")", &getTokenName);
            case '>':
              consume(lexer);
              return init_token(GREATERTHAN_TYPE, ">", &getTokenName);
            default:
              if (isLetter(lexer->c)) {
                  return NAME(lexer);
              } else {
                  fprintf(stderr, "INVALID CHAR: %c", lexer->c);
              }
        }
    }
    return init_token(EOF_TYPE, "<EOF>", &getTokenName);
}

Token_t* NAME(Lexer_t* lexer) {
    char* buf = (char*)malloc(32);
    int i = 0;
    char c = lexer->c;
    do {
       buf[i++] = c;
       consume(lexer);
       c = lexer->c; 
    } while (isLetter(c) && i < 32);
    buf[i] = '\0';
    return init_token(NAME_TYPE, buf, &getTokenName);
}

int isLetter(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

void WS(Lexer_t* lexer) {
    char c = lexer->c;
    do {
        consume(lexer);
        c = lexer->c;
    } while (c == '\t' || c == ' ' || c == '\n' || c == '\r');
}

int main() {
    Lexer_t* lexer = init_lambda_lexer(13, "(xxy) > ypple");
    Token_t* tok = nextToken(lexer);
    int i = 0;
    while (tok->type != EOF_TYPE && ++i < 10) {
        printf("%s\n", toString(tok));
        tok = nextToken(lexer);
    }
}