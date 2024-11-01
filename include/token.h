#pragma once
typedef enum {
  ILLEGAL,
  END_OF_FILE,
  IDENT,
  INT,
  ASSIGN,
  PLUS,
  COMMA,
  SEMICOLON,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,
  FUNCTION,
  LET
} TokenType;

typedef struct {
  TokenType Type;
  char *Literal;
} Token;

char *print_token_type(TokenType t);

TokenType get_identifier_type(Token *t);
