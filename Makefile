all:
	gcc -D_GNU_SOURCE -ansi -std=c99 -o locatile -lm osm.c main.c
