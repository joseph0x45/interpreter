#pragma once
typedef enum {
  ILLEGAL,
  EOF,
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
