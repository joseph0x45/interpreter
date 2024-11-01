SHELL := /bin/bash
CFLAGS = -g -Wall -Werror -Wextra -pedantic -I./include
CC = gcc
TARGET = interpreter.o
TEST_TARGET = test.o
SRC = ./src/lexer.c ./src/utils.c ./src/token.c

build:
	@$(CC) $(CFLAGS) -o $(TARGET) ./src/main.c $(SRC)

test-lexer:
	@$(CC) $(CFLAGS) -o $(TEST_TARGET) ./tests/lexer.c $(SRC)
	@time ./$(TEST_TARGET)

test-utils:
	@$(CC) $(CFLAGS) -o $(TEST_TARGET) ./tests/utils.c $(SRC)
	@time ./$(TEST_TARGET)


run:
	@./$(TARGET)
