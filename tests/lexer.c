#include "lexer.h"
#include "token.h"
#include <stdio.h>
#include <string.h>

typedef struct {
  TokenType expected_type;
  char *expected_literal;
} test_struct;

void test_next_token() {
  char *input = "let five = 5;\n"
                "let ten = 10;\n"
                "let add = fn(x, y) {\n"
                "    x + y;\n"
                "};\n"
                "let result = add(five, ten);\n";
  test_struct tests[] = {
      (test_struct){.expected_type = LET, .expected_literal = "let"},
      (test_struct){.expected_type = IDENT, .expected_literal = "five"},
      (test_struct){.expected_type = ASSIGN, .expected_literal = "="},
      (test_struct){.expected_type = INT, .expected_literal = "5"},
      (test_struct){.expected_type = SEMICOLON, .expected_literal = ";"},
      (test_struct){.expected_type = LET, .expected_literal = "let"},
      (test_struct){.expected_type = IDENT, .expected_literal = "ten"},
      (test_struct){.expected_type = ASSIGN, .expected_literal = "="},
      (test_struct){.expected_type = INT, .expected_literal = "10"},
      (test_struct){.expected_type = SEMICOLON, .expected_literal = ";"},
      (test_struct){.expected_type = LET, .expected_literal = "let"},
      (test_struct){.expected_type = IDENT, .expected_literal = "add"},
      (test_struct){.expected_type = ASSIGN, .expected_literal = "="},
      (test_struct){.expected_type = FUNCTION, .expected_literal = "fn"},
      (test_struct){.expected_type = LPAREN, .expected_literal = "("},
      (test_struct){.expected_type = IDENT, .expected_literal = "x"},
      (test_struct){.expected_type = COMMA, .expected_literal = ","},
      (test_struct){.expected_type = IDENT, .expected_literal = "y"},
      (test_struct){.expected_type = RPAREN, .expected_literal = ")"},
      (test_struct){.expected_type = LBRACE, .expected_literal = "{"},
      (test_struct){.expected_type = IDENT, .expected_literal = "x"},
      (test_struct){.expected_type = PLUS, .expected_literal = "+"},
      (test_struct){.expected_type = IDENT, .expected_literal = "y"},
      (test_struct){.expected_type = SEMICOLON, .expected_literal = ";"},
      (test_struct){.expected_type = RBRACE, .expected_literal = "}"},
      (test_struct){.expected_type = SEMICOLON, .expected_literal = ";"},
      (test_struct){.expected_type = LET, .expected_literal = "let"},
      (test_struct){.expected_type = IDENT, .expected_literal = "result"},
      (test_struct){.expected_type = ASSIGN, .expected_literal = "="},
      (test_struct){.expected_type = IDENT, .expected_literal = "add"},
      (test_struct){.expected_type = LPAREN, .expected_literal = "("},
      (test_struct){.expected_type = IDENT, .expected_literal = "five"},
      (test_struct){.expected_type = COMMA, .expected_literal = ","},
      (test_struct){.expected_type = IDENT, .expected_literal = "ten"},
      (test_struct){.expected_type = RPAREN, .expected_literal = ")"},
      (test_struct){.expected_type = SEMICOLON, .expected_literal = ";"},
      (test_struct){.expected_type = EOF, .expected_literal = ""},
  };
  Lexer *l = new_lexer(input);
  int failed = 0;
  for (int i = 0; i < 8; i++) {
    Token token = next_token(l);
    test_struct current_test = tests[i];
    if (token.Type != current_test.expected_type) {
      printf("Expected: %d but got %d\n", token.Type,
             current_test.expected_type);
      failed++;
    }
    if (strcmp(token.Literal, current_test.expected_literal) != 0) {
      printf("Expected: %s but got %s\n", token.Literal,
             current_test.expected_literal);
      failed++;
    }
  }
  printf("Tests finished! %d Failed\n", failed);
}

int main() {
  test_next_token();
  return 0;
}
