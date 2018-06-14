CC = gcc
CFLAGS = -g -Wall -std=c99
demo: main.o
	$(CC) $(CFLASGS) main.c -o tp3
