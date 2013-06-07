#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#include "osm.h"

void usage() {
	puts("Exemple :");
	puts("\tVignette : http://a.tile.openstreetmap.org/18/136194/95787.png");
	puts("\t- z:18");
	puts("\t- x:136194");
	puts("\t- y:95787");
	exit(0);
}

int main(int argc, char **argv) {
	if(4 != argc) 
		usage();
		
	int z = atoi(argv[1]);
	int x = atoi(argv[2]);
	int y = atoi(argv[3]);

	osm_tile_t *tile = NULL;
	if(NULL == (tile = malloc(sizeof(osm_tile_t))))
		exit(0);

	osm_gps_t *gps = NULL;
	if(NULL == (gps = malloc(sizeof(osm_gps_t))))
		exit(0);
	
	tile->x = x;
	tile->y = y;
	tile->z = z;	

	gps = tile2gps(tile);	

	printf("Pour z:%d x:%d y:%d\n", z, x, y);
	//printf("La vignette se trouve : %f,%f - ", tiley2lat(tile->y,tile->z), tilex2long(tile->x,tile->z));
	printf("La vignette se trouve : %f,%f - ", gps->x, gps->y);
	printf("http://www.openstreetmap.org/?mlat=%f&mlon=%f&zoom=15\n", gps->x, gps->y);

	free(tile);
	free(gps);
}
