#pragma once
#include "token.h"

typedef struct {
  char *input;
  long input_size;
  unsigned int position;
  unsigned int read_position;
  char current_character;
} Lexer;

Lexer *new_lexer(char *input);

void free_lexer(Lexer *l);

void read_char(Lexer *l);

Token next_token(Lexer *l);

char *read_identifier(Lexer *l);

void print_lexer(Lexer *l);
