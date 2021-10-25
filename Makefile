PROGS=4-1

all: $(PROGS)

4-1: 4-1.c
	gcc -Wall -o $@ $^