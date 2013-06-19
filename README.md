[![Build Status](https://travis-ci.org/j4/locatile.png?branch=master)](https://travis-ci.org/j4/locatile)

locatile
========

This program shows how we can easily locate an OSM tile. For example, it can be used for a cache manager to see association with a box. The ideal would be to use this function with a module cache nginx for OSM. We could specify the bbox to put or not put in the nginx cache.


Usage
-----

	./locatile http://a.tile.openstreetmap.org/16/34025/23500.png


Exemple
-------

	ja@lapy:~/codaz/locatile$ ./locatile http://a.tile.openstreetmap.org/16/34025/23500.png
	gps:45.290347,6.904907
	loc:http://www.openstreetmap.org/?mlat=45.290347&mlon=6.904907&zoom=15
	srv:a.tile.openstreetmap.org
