all:
	gcc -D_GNU_SOURCE -ansi -std=c99 -o locatile -lm locatile.c main.c
