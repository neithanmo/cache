Este es un programa para simulación de una memoria cache.
Se deja al usuario ajustar la simulación modificando lo siguiente:

	1. Tamaño de la cache
	2. Tamaño del bloque
	3. tipo de asociatividad:
	  	1. mapeo directo
          	2. 2-way set-associative
	  	4. 4-way set-associative

Luego de la simulación se imprime en pantalla el numero de hits y misses encontrados en la simulación
luego se grafican los resultados.

##########################################################################################

					DEPENDENCIAS

#########################################################################################

Se utiliza GnuPlot, el cual ofrece la opción de ejecutar comandos a traves de un objeto
iostream, para ello tambien es necesario instalar los siguientes paquetes

* gnuplot
* libboost1.55-all-dev
* libboost-iostreams1.55-dev
* libboost-filesystem1.55-dev
* libboost-system1.55-dev

si se tiene ubuntu 15.10 en adelante se sugiere estos mismos paquetes pero la version 1.58


si esta en un entorno `unix/debian-ubuntu` puede instalar los paquetes indicados utilizando
el siguiente comando:

>sudo apt-get install gnuplot libboost-iostreams1.55-dev libboost-filesystem1.55-dev libboost-system1.55-dev

una vez instalados puede compilar esta aplicación utilizando make. Una vez compilada la aplicación puede
ejecutarla usando lo siguiente
> ./cache 1024 32 2

>1024 es el primer argumento indica el tamaño de cache a emular
>32 es el segundo argumento, indica el tamaño del bloque en el cache
>2 tercer argumento , indica el tipo de asociatividad 1 para mapeo directo, 2 para 2-way y 4 para 4-way

