#include "lexer.h"
#include "token.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lexer *new_lexer(char *input) {
  Lexer *l = malloc(sizeof(Lexer));
  if (l == NULL) {
    perror("malloc:");
    return NULL;
  }
  memset(l, 0, sizeof(Lexer));
  l->input = input;
  l->input_size = strlen(l->input);
  read_char(l);
  return l;
}

void read_char(Lexer *l) {
  if (l->read_position >= l->input_size) {
    l->current_character = 0;
  } else {
    l->current_character = l->input[l->read_position];
  }
  l->position = l->read_position;
  l->read_position++;
}

Token next_token(Lexer *l) {
  Token t;
  switch (l->current_character) {
  case '=':
    t = (Token){.Type = ASSIGN, .Literal = "="};
    break;
  case '+':
    t = (Token){.Type = PLUS, .Literal = "+"};
    break;
  case '(':
    t = (Token){.Type = LPAREN, .Literal = "("};
    break;
  case ')':
    t = (Token){.Type = RPAREN, .Literal = ")"};
    break;
  case '{':
    t = (Token){.Type = LBRACE, .Literal = "{"};
    break;
  case '}':
    t = (Token){.Type = RBRACE, .Literal = "}"};
    break;
  case ',':
    t = (Token){.Type = COMMA, .Literal = ","};
    break;
  case ';':
    t = (Token){.Type = SEMICOLON, .Literal = ";"};
    break;
  case '0':
    t = (Token){.Type = EOF, .Literal = ""};
    break;
  }
  read_char(l);
  return t;
}

char *read_identifier(Lexer *l) {
  int identifier_len = 0;
  int position = l->position;
  while (is_letter(l->current_character)) {
    read_char(l);
    identifier_len++;
  }
  char *identifier = malloc(identifier_len + 1);
  if (identifier == NULL) {
    return NULL;
  }
  for (int i = 0; i < identifier_len; i++, position++) {
    identifier[i] = l->input[position];
  }
  identifier[identifier_len] = '\0';
  return identifier;
}

void print_lexer(Lexer *l) {
  printf("Lexer input: %s\n", l->input);
  printf("Lexer input size: %ld\n", l->input_size);
  printf("Lexer position: %d\n", l->position);
  printf("Lexer read position: %d\n", l->read_position);
  printf("Lexer current character: '%c'\n", l->current_character);
}
