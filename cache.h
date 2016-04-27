#ifndef CACHE
#define CACHE
#endif // CACHE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>

class Cache
{
    public:
        Cache();
        ~Cache();
        friend class grap;
        unsigned int t_cache;
        int t_bloque;
        int asoc;
        int **cache; //matriz para el cache, lecturas y escrituras
        unsigned int dir;
        unsigned int get_tag();
        unsigned int get_set();
        void poner_enCache();
        void buscar_enCache();
        void configure();// funcion para calcular el offset, index, set, y tag e inicializa la cache.


    private:

        int hits;
        int miss;
        int offset;
        int index;
        int n_bloques;
        int n_sets;
        unsigned int tag;
        int set;






};

