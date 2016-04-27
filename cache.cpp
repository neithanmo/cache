#include "cache.h"


Cache::Cache()
{
    //printf("el tamaño del bloque es: %d", t_cache);
}

void Cache::configure(){
    //cache[t_cache][asoc] = 0;
    //std::cout << "cache posicion i-j:" << cache[t_cache][asoc] << std::endl;
    std::cout << "HOLLLAAAAA"<< std::endl;

    offset = log2(t_cache);
    n_sets = (t_cache)/(t_bloque * asoc);
    index = log2(n_sets);
    for(int i =0; i<n_sets;i++){
        for(int j=0;j<asoc;j++)
        {
            cache[i][j] = 0;
        }
    }


}
