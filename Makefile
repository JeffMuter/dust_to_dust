# Variables
CC = clang
CFLAGS = -Wall -Wextra -std=c11 -g $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib)

# The main target - this is what happens when you type "make" with no arguments
game: src/main.c
	$(CC) $(CFLAGS) -o game src/main.c $(LIBS)

# build and run in one command
run: game
	./game

# removes generated files
.PHONY: clean run
clean:
	rm -f game
