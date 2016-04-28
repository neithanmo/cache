//#include <iostream>
#include "cache.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cache *miCache = new Cache();
    assert(argc>=4);


    cout << "inicializando el objeto Cache!" << endl;
    sscanf(argv[1], "%d", &miCache->t_cache);
    sscanf(argv[2], "%d", &miCache->t_bloque);
    sscanf(argv[3], "%d", &miCache->asoc);
    cout << "Tamaño del cache es: "<< miCache->t_cache << endl;
    cout << "Tamaño del bloque es: "<< miCache->t_bloque << endl;
    cout << "tipo de asociatividad es: " <<miCache->asoc<<endl;
    clock_t inicio = clock();
    miCache->configure();//configuración de la cache, variables y constantes etc.
    miCache->run_simulation();
    if(miCache->done){
        delete(miCache);//liberando mememoria y objetos dinámicos
    }

    clock_t final = clock();
    double tiempo_sim = (final - inicio)/ CLOCKS_PER_SEC;

    cout<<"se finalizo la simulación"<<endl;
    cout<<"el tiempo total de simulación fue de: "<<tiempo_sim<<" segundos"<<endl;



}

