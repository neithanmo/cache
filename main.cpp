//#include <iostream>
#include <assert.h>
#include <stdio.h>
#include "cache.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cache *miCache = new Cache();
    printf("argumentos son: %d\n", argc);
    cout<<"primer argumento es: "<< argv[1]<<endl;
    printf("x = %d\n",(int)(*argv[1]));

    if(argc==4)
    {

        cout << "inicializando el objeto Cache!" << endl;
        sscanf(argv[1], "%d", &miCache->t_cache);
        sscanf(argv[2], "%d", &miCache->t_bloque);
        sscanf(argv[3], "%d", &miCache->asoc);
        cout << "Tamaño del cache es: "<< miCache->t_cache << endl;
        cout << "Tamaño del bloque es: "<< miCache->t_bloque << endl;
        cout << "tipo de asociatividad es" <<miCache->asoc<<endl;
        cout << "son :"<< argc << endl;
    }
    else
    {
        cout<<"se requieren tres argumentos, vuelva a ejecutar el programa"<<endl;
        exit(-1);
    }

    miCache->configure();








}

