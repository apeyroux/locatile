typedef struct osm_gps_s osm_gps_t;
typedef struct osm_tile_s osm_tile_t;

struct osm_gps_s {
	double x;
	double y;
};

struct osm_tile_s {
	int x;
	int y;
	int z;
	char * server_name;
	osm_gps_t gps;
};

int long2tilex(double lon, int z);
int lat2tiley(double lat, int z);
double tilex2long(int x, int z);
double tiley2lat(int y, int z); 

int tile2gps(osm_tile_t *tile, osm_gps_t *gps);
int url2tile(char *url, osm_tile_t *tile);
