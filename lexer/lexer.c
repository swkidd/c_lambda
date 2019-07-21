#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"

Lexer_t* init_lexer(int len, char* input) {
  Lexer_t* lexer = (Lexer_t*)malloc(sizeof(Lexer_t));
  lexer->c = (len > 0? input[0] : EOF);
  lexer->p = 0;
  lexer->input = strdup(input);
  lexer->len = len;
  return lexer;
}

void consume(Lexer_t* lexer) {
    int p = ++lexer->p;
    if (p >= lexer->len) {
        lexer->c = EOF;
    } else lexer->c = lexer->input[p];
}

int match(Lexer_t* lexer, char x) {
    if (lexer->c == x) {
        consume(lexer); 
        return 0;
    } else fprintf(stderr, "EXPECTING %c FOUND %c\n", x, lexer->c);
    return -1;
}
/*
int main() {
  Lexer_t* lexer = init_lexer(2, "hi");
  printf("c: %d\np: %d\ninput: %s\nlen: %d\n", lexer->c, lexer->p, lexer->input, lexer->len);
  match(lexer, 'h');
  match(lexer, 'i');
  printf("c: %d\np: %d\ninput: %s\nlen: %d\n", lexer->c, lexer->p, lexer->input, lexer->len);
}
 */
