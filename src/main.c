#include <stdio.h>
#include <stdlib.h>

#include "locatile.h"

void usage() {
	puts("Exemple :");
	puts("\tlocatile http://c.tile.openstreetmap.org/15/17020/11746.png");
	exit(0);
}

int main(int argc, char **argv) {
	if(2 != argc) 
		usage();

	char *url = argv[1];

	osm_tile_t *tile = NULL;
	if(NULL == (tile = malloc(sizeof(osm_tile_t))))
		exit(0);

	osm_gps_t *gps = NULL;
	if(NULL == (gps = malloc(sizeof(osm_gps_t))))
		exit(0);

	if(!url2tile(url, tile))
		exit(0);
	
	//printf("x:%d\n", tile->x);
	//printf("y:%d\n", tile->y);
	//printf("z:%d\n", tile->z);
	printf("gps:%f,%f\n", tile->gps.x, tile->gps.y);
	printf("loc:http://www.openstreetmap.org/?mlat=%f&mlon=%f&zoom=15\n", tile->gps.x, tile->gps.y); 
	printf("srv:%s\n", tile->server_name);

	free(tile);
	free(gps);
}
