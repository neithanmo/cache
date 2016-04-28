//#include <iostream>
#include <assert.h>
#include <stdio.h>
#include "cache.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cache *miCache = new Cache();

    if(argc==4)
    {

        cout << "inicializando el objeto Cache!" << endl;
        sscanf(argv[1], "%d", &miCache->t_cache);
        sscanf(argv[2], "%d", &miCache->t_bloque);
        sscanf(argv[3], "%d", &miCache->asoc);
        cout << "Tamaño del cache es: "<< miCache->t_cache << endl;
        cout << "Tamaño del bloque es: "<< miCache->t_bloque << endl;
        cout << "tipo de asociatividad es: " <<miCache->asoc<<endl;
    }
    else
    {
        cout<<"se requieren tres argumentos, vuelva a ejecutar el programa"<<endl;
        exit(-1);
    }

    miCache->configure();
    unsigned int num = 0;
    string hola ="8";
    sscanf(hola.c_str(), "%x", &num);
    std::cout<<num<<endl;
    unsigned int rot = num>>2;
    cout<<rot;//

}

