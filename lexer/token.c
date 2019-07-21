
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

Token_t* init_token(int type, char* text, char* (*getTokenName)(int)) {
    Token_t* token = (Token_t*)malloc(sizeof(Token_t));
    token->type = type;
    token->text = strdup(text);
    token->getTokenName = getTokenName;
    return token;
}

char* toString(Token_t* token) {
    char* tname = token->getTokenName(token->type);
    char *buf = (char *)malloc(32);
    snprintf(buf, 32, "< %s %s >", token->text, tname);
    return buf; 
}