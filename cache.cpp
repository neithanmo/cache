#include "cache.h"


Cache::Cache()
{

}

void Cache::configure(){

    //calculo parámetros globales de la cache
    offset = log2(t_cache);
    n_sets = (t_cache)/(t_bloque * asoc);
    index = log2(n_sets);
    indexMasoffset = index + offset;//numero de bits a correr Dir para leer el tag
    printf("el offsets es: %d\n", offset);
    printf("numero de sets: %d\n", n_sets);
    printf("el index es: %d\n", index);
    dir = 20005489125478;


    //######### Ajuste dinámico de la matriz cache e inicializacióm ####################################
    cache = new int *[n_sets];

    for(int i =0; i<n_sets;i++){
        cache[i] = new int[asoc];
    }


    for(int i =0; i<n_sets;i++){
        for(int j=0;j<asoc;j++)
        {
            cache[i][j] = rand()%200;
        }
    }

    //para mostrar la matriz
   for (int i = 0; i < n_sets; i++)
    {
        for (int j = 0; j < asoc; j++)
        {
            cout << cache[i][j] << "\t"<<endl;
        }

     }
    //#################################################################################################

     cout<<"select_sets: #################################"<<endl;
     for(int j =0; j<asoc;j++){
         cout << cache[Cache::obtener_set(this->dir, this->n_sets, this->offset)][j] << "\t"<<endl;
        }
     cout<<"set seleccionado es: "<<Cache::obtener_set(this->dir, this->n_sets, this->offset)<<endl;
     cout<<"este es el tag: "<<Cache::obtener_tag(this->dir, this->indexMasoffset)<<endl;
}




