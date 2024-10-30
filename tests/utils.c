#include "utils.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *input = "hello world";
  Lexer *l = new_lexer(input);
  if (l == NULL) {
    return 0;
  }
  char *id = read_identifier(l);
  if (id == NULL) {
    return 0;
  }
  return 0;
}
