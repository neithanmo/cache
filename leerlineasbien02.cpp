#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{

    ifstream fin;
    fin.open("instrucciones", ifstream::in);
    string direccion, SoL;


    while(!fin.eof())
    {
        fin >> direccion >> SoL;
        cout << direccion << endl;

        /*int num = Int32.Parse(direccion, System.Globalization.NumberStyles.HexNumber); //esto no funciono porque hacia falta llamar al metodo Parse(String,\u2002NumberStyles)
        Console.WriteLine(num);*/

        /*unsigned int dir = std::stoi(direccion,nullptr,16);
        cout << dir;*/

        unsigned int numdir = strtoul(direccion.c_str(), NULL, 16);
        cout << numdir << endl;

        union deDireccion {
            unsigned int valor;

            struct { //esta estructura permite separar la variable "valor" en pedazos del tamano de la cantidad de bits definidos en a, b, c, d, e, f, g, h.
            unsigned a:4;
            unsigned b:4;
            unsigned c:4;
            unsigned d:4;
            unsigned e:4;
            unsigned f:4;
            unsigned g:4;
            unsigned h:4;
            } N;

        } Parte;

        Parte.valor = numdir; //aqui igualo "valor" de la union "deDireccion" con "numdir".

        cout << Parte.N.a << endl << endl; //imprimo los primeros 4 bits (tamano de a) de "Parte.valor" que es igual a "numdir". Parte.N.a es la variable que contiene estos 4 bits.
        //printf("0x%X",Parte.N.x);
    }

}

