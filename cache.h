#ifndef CACHE
#define CACHE
#endif // CACHE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;
class Cache
{
    public:
        Cache();
        ~Cache();
        friend class grap;
        unsigned int t_cache;
        int t_bloque;
        int asoc;
        //int **cache; //matriz para el cache, lecturas y escrituras

        unsigned int get_tag();
        unsigned int get_set();
        void poner_enCache();
        void buscar_enCache();
        void configure();// funcion para calcular el offset, index, set,
                         //y tag e inicializa la cache.


    private:

        unsigned int hits;
        unsigned int miss;
        int offset;//offset
        int index;//index
        int n_bloques;//numero total de bloques
        int n_sets; //numero total de sets
        int **cache;
        unsigned int tag;//tag a buscar o leer
        unsigned int select_set;//index a buscar en el cache para leer cache
        unsigned int dir;
        int indexMasoffset; //numero de bits a correr para leer el tag

        inline unsigned int obtener_set(unsigned int &dir, int &n_sets, int &offset){
            unsigned int data = (dir>>offset)%n_sets;
            return data;
       }
        inline unsigned int obtener_tag(unsigned int &dir, int &indexMasoffset){
            unsigned int data = dir>>indexMasoffset;
            return data;
        }
        void rwCache(unsigned int &tag, unsigned int &select_set, int &asoc);//buscar el tag y/o
                                                                              //guardarlo en cache
        void run_simulation(ifstream &file);//funcion lee lineas del archivo
                                            //hace conversion, verifica si tag esta o no en el cache
                                            //lleva estadisticas de hit y misses, y va graficando en

        //en tiempo real.

};

