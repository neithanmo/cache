Este es un programa para simulación de una memoria cache.
Se deja al usuario ajustar la simulación modificando lo siguiente:
	Tamaño de la cache
	Tamaño del bloque
	tipo de asociatividad:
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

gnuplot
libboost-iostreams1.58-dev
libboost-filesystem-dev
libboost-system-dev

sin estos la compilación de esta aplicación no sera posible

si esta en un entorno unix/debian-ubuntu puede instalar los paquetes indicados utilizando
el siguiente comando:

 sudo apt-get install gnuplot libboost-system-dev libboost-filesystem-dev libboost-iostreams1.58-dev

una vez instalados puede compilar esta aplicación utilizando make

