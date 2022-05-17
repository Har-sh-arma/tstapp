CC = gcc

all: listener.c
	$(CC) listener.c -o listener
	$(CC) server.c -o server



