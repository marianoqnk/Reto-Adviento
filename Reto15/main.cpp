#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
using namespace std;
int counter = 0;
#define FILAS 3
#define COLUMNAS 3
#define POSICION(f,c) (c*COLUMNAS+f)
#define FN(n) (n/COLUMNA)
#define FC(n) (n%COLUMNA)

int matriz[3][3]{{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9}

};
class Rama
{
public:
    int to;
    int cost;
    Rama();
};
class Node
{
public:

    array <Rama,4> misRamas()
    {
       
        _misRamas[0].to = fila - 1 * COLUMNAS + columna;
         _misRamas[0].cost = matriz[fila - 1][columna];

        _misRamas[1].to = fila - 1 * COLUMNAS + columna;
         _misRamas[1].cost = matriz[fila + 1][columna];

         _misRamas[2].to = fila * COLUMNAS + columna;
         _misRamas[2].cost = matriz[fila + 1][columna+1];

         _misRamas[3].to = fila * COLUMNAS + columna;
         _misRamas[3].cost = matriz[fila + 1][columna-1];
         return _misRamas;
    }
    
private:
    array <Rama,4> _misRamas;
    int antecesor=-1;
    int distanciaOrigen=0;
    bool visitado=false;
    int peso;
};

vector<Node *> grafo;

void matrizToGrafo(int filas, int columnas, int *datos)
{
    int *p = datos;
    for (int x = 0; x < filas; x++)
        for (int y = 0; y < columnas; y++)
        {
            Node *N = new Node(x, y);
            grafo.push_back(N);
            cout << *p++ << ',';
        }
    // cout<<grafo[1]->misRamas[0]->to;
}

int leeDatos()
{
    ifstream fe("input.txt");
    char cadena[1024];
    char *pch;
    fe.getline(cadena, 1000, '\n');
    // strcpy(texto, cadena);
    fe.getline(cadena, 1000, '\n');
    do
    {

        fe.getline(cadena, 1000, '\n');
        if (strlen(cadena) == 0)
            break;
        pch = strtok(cadena, " ");
        // strcpy(miDiccionario[counter].palabra, pch);
        pch = strtok(NULL, " ");
        pch = strtok(NULL, " ");
        // miDiccionario[counter++].sustitucion = pch[0];
        //  cout<<"x:"<<miPoint->x<<"y:"<<miPoint->y<<'\n';
    } while (1);

    return counter;
}
int main()
{
    // leeDatos();
    /*for (int x=0;x<3;x++)
        for (int y=0;y<3;y++)
            cout<<matriz[x][y]<<',';*/
    matrizToGrafo(3, 3, (int *)matriz);
    return 0;
}