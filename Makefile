CFLAGS = -Wall -g -ansi
CC = gcc

uniq: uniq.c
	$(CC) $(CFLAGS) uniq.c -o uniq

clear: 
	rm *.o
