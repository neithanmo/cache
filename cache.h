#ifndef CACHE
#define CACHE

#endif // CACHE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

class cache
{
    public:
        cache();
        ~cache();
        friend class crap;

    private:
        int **cache; //matriz para el cache, lecturas y escrituras
        unsigned int dir;
        int hits;
        int miss;




};

