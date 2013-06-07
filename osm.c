#include <math.h>
#include <stdlib.h>

#include "osm.h"

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

osm_gps_t * tile2gps(osm_tile_t *tile) {
	osm_gps_t *gps = NULL;
	if(NULL == (gps = malloc(sizeof(osm_gps_t))))
		 exit(0); // mettre du messsage d'erreur
	if(NULL == tile)
		exit(0);
	gps->x = tiley2lat(tile->y,tile->z);
	gps->y = tilex2long(tile->x,tile->z);
	return gps;	
}

osm_tile_t * url2tile(char *url) {
	osm_tile_t *tile = NULL;
	return tile;
}
