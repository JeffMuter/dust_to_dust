CC = clang
CFLAGS = -Wall -Wextra -std=c11 -g $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib)

game: src/main.c
	$(CC) $(CFLAGS) -o game src/main.c $(LIBS)

.PHONY: clean
clean:
	rm -f game
