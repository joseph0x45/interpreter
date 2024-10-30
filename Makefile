CFLAGS = -Wall -Werror -Wextra -pedantic -I./include
CC = gcc
TARGET = interpreter.o

build:
	$(CC) $(CFLAGS) -o $(TARGET) ./src/main.c

run:
	@./$(TARGET)

