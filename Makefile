CFLAGS = -Wall -Werror -Wextra -pedantic -I./include
CC = gcc

build:
	$(CC) $(CFLAGS) -o interpreter.o ./src/main.c
