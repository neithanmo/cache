#include "cache.h"


Cache::Cache()
{
    done = false;
}

Cache::~Cache(){

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

    //######### Ajuste dinámico de la matriz cache e inicializacióm ####################################
    cache = new int *[n_sets];

    for(int i =0; i<n_sets;i++){
        cache[i] = new int[asoc];
    }


    for(int i =0; i<n_sets;i++){
        for(int j=0;j<asoc;j++)
        {
            cache[i][j] = 0;//evitar basura en mi cache, arranque inicial del sistema es borrar la memoria
        }
    }

    //#################################################################################################
}

void Cache::run_simulation(){

    cout << "ingrese el nombre del archivo con las direcciones"<<endl;
    cout << "el archivo debe estar en el path actual"<<endl;
    string filename;
    cin >> filename;
    cout<<"el nombre del archivo es: "<<filename<<endl;
    ifstream fin;
    fin.open(filename.c_str(), ifstream::in);
    string direccion, SoL;
    std::vector<std::pair<double, double> > xy_pts_A;//vetores para graficar resultados
    std::vector<std::pair<double, double> > xy_pts_B;
    clock_t inicio = clock();
    double hitrate;
    double missrate;
    while(!fin.eof())
    {
        fin >> direccion >> SoL;
        sscanf(direccion.c_str(), "%x", &dir);//conversion de hex a decimal y se asigna a dir
                                              //con dir se obtiene el tag y el set dependiendo de
                                              //el offset, index calculados inicialmente
        
        this->select_set = obtener_set(this->dir, this->n_sets, this->offset);
        this->tag = obtener_tag(this->dir, this->indexMasoffset);

        //######################## Accesando al cache y comparando tags ##################################################

        for(int j =0; j<asoc;j++){
            if(cache[select_set][j] == tag){
                hits++; //el dato se encuentra en el cache - hay un hit, no se hace nada más
                accesos++;
            }
            else{
                miss++; //no esta en el cache es un miss
                int nuevo_set = rand()%n_sets;//la política de escritura en cache es aleatória
                cache[nuevo_set][j] = tag;
                accesos++;
            }
           }
        //hitrate=((double)hits/accesos)*100;
        missrate=((double)miss/accesos)*100;
        //grificamos unicamente las primeras 10000 instrucciones - evitamos el gnuplot cuelgue
	if(accesos<=10000){
        	xy_pts_A.push_back(std::make_pair(accesos,missrate));//actualizo vectores con datos adquiridos
        	//xy_pts_B.push_back(std::make_pair(accesos, hitrate));
        	gnp << "set xlabel 'Numero de instrucciones'\n";
        	gnp << "set ylabel 'missrate (%)'\n";
        	gnp << "set xrange [0:"<<accesos<<"]\nset yrange [0:100]\n"; //pasando comandos al gnuplot object
        	gnp << "plot" << gnp.file1d(xy_pts_A) << "with lines title 'missrate'"<<std::endl;
		//gnp.binFile1d(xy_pts_A,"record");// << "with lines title 'missrate'";
        	cout<<"passing data to gnuplot==>>"<<missrate<<endl;
	}
    }
    cout<<"numero total de hits: "<<hits<<endl;
    cout<<"numero total de misses: "<<miss<<endl;
    cout<<"numero total de accesos a cache fue de: "<<accesos<<endl;
    delete(cache);//limpiado de memoria
}




