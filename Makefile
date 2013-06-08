all:
	gcc -D_GNU_SOURCE -ansi -std=c99 -o whereismytile -lm osm.c main.c
