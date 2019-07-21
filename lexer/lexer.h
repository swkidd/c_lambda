#ifndef LEXER_HEADER
#define LEXER_HEADER

#define EOF_TYPE 1

struct Lexer {
    char* input;
    int len;
    int p; //index into input
    char c; //current char
};
typedef struct Lexer Lexer_t;

Lexer_t* init_lexer(int len, char* input); 
void consume(Lexer_t* lexer); //advance lexer forward one char
int match(Lexer_t* lexer, char x); //check if current char == x

#endif