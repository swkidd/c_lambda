#ifndef TOKEN_HEADER
#define TOKEN_HEADER

struct Token {
    int type;
    char *text;
    char* (*getTokenName)(int);
};
typedef struct Token Token_t;

Token_t* init_token(int type, char* text, char* (*getTokenName)(int));
char* toString(Token_t *token);

#endif