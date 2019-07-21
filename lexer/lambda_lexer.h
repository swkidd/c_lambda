#ifndef LAMBDA_LEXER_HEADER
#define LAMBDA_LEXER_HEADER

#define NAME_TYPE 2
#define LPAREN_TYPE 3
#define RPAREN_TYPE 4
#define GREATERTHAN_TYPE 5
#define BACKSLASH_TYPE 6

#include "lexer.h"
#include "token.h"

Lexer_t* init_lambda_lexer(int len, char* input);
char *getTokenName(int x);
int isLetter(char c);
void WS(Lexer_t* lexer);
Token_t* nextToken(Lexer_t* lexer);
Token_t* NAME(Lexer_t* lexer);
#endif