#ifndef CACHE
#define CACHE
#endif // CACHE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include "gnuplot-iostream.h"
/*
 * Cache memory simulator
 * by Natanael Mojica
 * Alonso Rojas
 *
 *  */

using namespace std;
class Cache
{
    public:
        Cache();
        ~Cache();
        unsigned int t_cache;
        int t_bloque;
        int asoc;
        unsigned int get_tag();
        unsigned int get_set();
        Gnuplot gnp;
        bool done;
        void configure();// funcion para calcular el offset, index, set,
                         //y tag e inicializa la cache.
        void run_simulation();//funcion lee lineas del archivo
                                            //hace conversion, verifica si tag esta o no en el cache
                                            //lleva estadisticas de hit y misses, y va graficando en

                                           //en tiempo real.


    private:

        unsigned int hits;
        unsigned int miss;
        int offset;//offset
        int index;//index
        int n_bloques;//numero total de bloques
        int n_sets; //numero total de sets
        int **cache;
        int tag;//tag a buscar o leer
        int select_set;//index a buscar en el cache para leer cache
        unsigned int dir;
        int indexMasoffset; //numero de bits a correr para leer el tag
        unsigned int accesos;//control del numero de lineas y calcular el hitrate y misrate
        inline int obtener_set(unsigned int &dir, int &n_sets, int &offset){
            unsigned int data = (dir>>offset)%n_sets;
            return data;//
       }
        inline unsigned int obtener_tag(unsigned int &dir, int &indexMasoffset){
            unsigned int data = dir>>indexMasoffset;
            return data;
        }

};

