#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "locatile.h"

int tile2gps(osm_tile_t *tile, osm_gps_t *gps) {
	if(NULL == gps)
		return 0;
	if(NULL == tile)
		return 0;

	gps->x = tiley2lat(tile->y,tile->z);
        gps->y = tilex2long(tile->x,tile->z);

	return 1;
}

int url2tile(char *url, osm_tile_t *tile) {
	if(NULL == url)
		return 0;
	if(NULL == tile)
		return 0;
	// faire un split puis creer la tile
	char *tocken = NULL;
	char **buf = malloc(sizeof(char *)*512);
	int i = 0;
	while(url != NULL) {
		if(i >= 512)
			exit(0); // URL trop grosse !
		tocken = strsep(&url, "/");
		buf[i] = tocken;
		i++;
	}
	int nbBufEl = 0;
	for(int i = 0; buf[i] != NULL; i++) 
		nbBufEl++;

	if(nbBufEl <= 2) // verif si ya bien minimu trois match si non segfault
		return 0;

	tile->server_name = buf[2];
	tile->x = atoi(buf[nbBufEl-2]);
	tile->y = atoi(buf[nbBufEl-1]); // propre ? (vire implicitement le .png)
	tile->z = atoi(buf[nbBufEl-3]);

	osm_gps_t *gps = NULL;
	if(NULL == (gps = malloc(sizeof(osm_gps_t))))
		return 0;

	if(tile2gps(tile, gps)) {
		tile->gps = *gps;
	} else 
		return 0;

	return 1;
}

/*
 * Slippy map : http://wiki.openstreetmap.org/wiki/Slippy_map_tilenames#C.2FC.2B.2B
 */

int long2tilex(double lon, int z) { 
	return (int)(floor((lon + 180.0) / 360.0 * pow(2.0, z))); 
}
 
int lat2tiley(double lat, int z) { 
	return (int)(floor((1.0 - log( tan(lat * M_PI/180.0) + 1.0 / cos(lat * M_PI/180.0)) / M_PI) / 2.0 * pow(2.0, z))); 
}
 
double tilex2long(int x, int z) {
	return x / pow(2.0, z) * 360.0 - 180;
}
 
double tiley2lat(int y, int z) {
	double n = M_PI - 2.0 * M_PI * y / pow(2.0, z);
	return 180.0 / M_PI * atan(0.5 * (exp(n) - exp(-n)));
}
