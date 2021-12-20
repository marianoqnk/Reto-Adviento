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
#define POSICION(f, c) ((f)*COLUMNAS + c)
#define FIL(n) ((n) / COLUMNAS)
#define COL(n) ((n) % COLUMNAS)

int matriz[3][3]{{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9}

};
class Rama
{
public:
    int to;
    int cost;
    // Rama();
};
class Node
{
public:
    void print()
    {

        cout << "N:" << nodeN << " Visitado:" << visitado << " Do:" << distanciaOrigen << " A:" << antecesor << '\n';
        cout << "ADJ: ";
        for (auto rama : _misRamas)
            if (rama.to >= 0)
                cout << "T:" << rama.to << " C:" << rama.cost << ' ';
        cout << '\n';
    };
    Node(int n) : nodeN(n){};
    int nodeN;
    array<Rama, 4> _misRamas;
    bool visitado = false;
    int distanciaOrigen = 0xFFFFFFFF; // muchas distancia
    int antecesor = -1;
    int peso;
};

vector<Node *> grafo;

void matrizToGrafo(int filas, int columnas, int *datos)
{
    // carga los datos del grafo y fin, no genera matriz de adyacencias porque exite en matriz pero quizás sea mejor crearlas
    int *p = datos;
    int nodoActual = 0;
    for (int f = 0; f < filas; f++)
        for (int c = 0; c < columnas; c++)
        {
            Node *N = new Node(nodoActual++);
            // N->distanciaOrigen = 0xFFFFFFFF;
            int nrama = 0;
            // adyacencias
            if (f > 0)
            {
                N->_misRamas[nrama].cost = matriz[f - 1][c];
                N->_misRamas[nrama++].to = POSICION(f - 1, c);
            }
            if (f < filas - 1)
            {
                N->_misRamas[nrama].cost = matriz[f + 1][c];
                N->_misRamas[nrama++].to = POSICION(f + 1, c);
            }
            if (c > 0)
            {
                N->_misRamas[nrama].cost = matriz[f][c - 1];
                N->_misRamas[nrama++].to = POSICION(f, c - 1);
            }
            if (c < columnas - 1)
            {
                N->_misRamas[nrama].cost = matriz[f][c + 1];
                N->_misRamas[nrama++].to = POSICION(f, c + 1);
            }
            grafo.push_back(N);
            // cout << *p++ << ',';
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
    matrizToGrafo(FILAS, COLUMNAS, (int *)matriz); // crea la matriz
    for (auto nodo : grafo)
        nodo->print();
    grafo[0]->distanciaOrigen = 0;
    grafo[0]->antecesor = 0;
    grafo[0]->visitado=true;
    
    auto nodoAtual = *grafo[0];
    bool salir;
    do
    {
        unsigned int minima = 0xFFFF;
        unsigned int nodoMinima = 0x0;

        /* code */
        salir = true;
        for (auto rama :  nodoAtual._misRamas)
        {
            if(rama.to<=0)break;
            Node nodoDestino=*grafo[rama.to];
            if (nodoDestino.visitado == false)
            {
                // calcula coste
                int coste = nodoAtual.distanciaOrigen + rama.cost;
                if (coste < nodoDestino.distanciaOrigen || nodoDestino.distanciaOrigen==-1)
                {
                    nodoDestino.distanciaOrigen = coste;
                    nodoDestino.antecesor = nodoAtual.nodeN;
                    salir = false;
                };
                if (coste < minima)
                {
                    minima = coste;
                    nodoMinima = rama.to;
                };
                
            };
        };
        nodoAtual=*grafo[nodoMinima];
        nodoAtual.visitado=true;
    } while (!salir);

    return 0;
}