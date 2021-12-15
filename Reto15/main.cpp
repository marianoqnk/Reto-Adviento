#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
int counter = 0;

int leeDatos()
{
    ifstream fe("input.txt");
    char cadena[1024];
    char *pch;
    fe.getline(cadena, 1000, '\n');
    strcpy(texto, cadena);
    fe.getline(cadena, 1000, '\n');
    do
    {

        fe.getline(cadena, 1000, '\n');
        if (strlen(cadena) == 0)
            break;
        pch = strtok(cadena, " ");
        strcpy(miDiccionario[counter].palabra, pch);
        pch = strtok(NULL, " ");
        pch = strtok(NULL, " ");
        miDiccionario[counter++].sustitucion = pch[0];
        // cout<<"x:"<<miPoint->x<<"y:"<<miPoint->y<<'\n';
    } while (1);

    return counter;
}
int main()
{
    leeDatos();
    return 0;
}