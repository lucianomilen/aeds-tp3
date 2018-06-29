CC = gcc
CFLAGS = -g -Wall -std=c99
all: main.o
	$(CC) $(CFLASGS) main_heuristica.c heuristica.c -o tp3h
	$(CC) $(CFLASGS) main_bruta.c bruta.c -o tp3fb
