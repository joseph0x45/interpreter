#include "token.h"
#include <string.h>

char *print_token_type(TokenType t) {
  switch (t) {
  case ILLEGAL:
    return "ILLEGAL";
  case END_OF_FILE:
    return "END_OF_FILE";
  case IDENT:
    return "IDENT";
  case INT:
    return "INT";
  case ASSIGN:
    return "ASSIGN";
  case PLUS:
    return "PLUS";
  case COMMA:
    return "COMMA";
  case SEMICOLON:
    return "SEMICOLON";
  case LPAREN:
    return "LPAREN";
  case RPAREN:
    return "RPAREN";
  case LBRACE:
    return "LBRACE";
  case RBRACE:
    return "RBRACE";
  case FUNCTION:
    return "FUNCTION";
  case LET:
    return "LET";
  }
  return "";
}

TokenType get_identifier_type(Token *t) {
  if (strcmp(t->Literal, "let") == 0) {
    return LET;
  }
  if (strcmp(t->Literal, "fn") == 0) {
    return FUNCTION;
  }
  return IDENT;
}
