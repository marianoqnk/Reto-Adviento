#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
int counter = 0;
int pliegues = 0;
int puntuacionTotal = 0;
struct point
{
    int x;
    int y;
};
point *puntos[1000];
int lineas[25];
int leeDatos()
{
    ifstream fe("input.txt");
    char cadena[1024];
    char *pch;
    do
    {

        fe.getline(cadena, 1000, '\n'); 
        if (strlen(cadena) == 0)
            break;
        pch = strtok(cadena, ","); 
        point *miPoint = new point;
        miPoint->x = atoi(pch);
        pch = strtok(NULL, ",");
        miPoint->y = atoi(pch); 
        puntos[counter++] = miPoint;
        // cout<<"x:"<<miPoint->x<<"y:"<<miPoint->y<<'\n';
    } while (1);
    do
    {
        fe.getline(cadena, 1000, '\n'); // Load one line
        if (strlen(cadena) == 0)
            break;
        pch = strtok(cadena, "="); // open and closed Chunk
        pch = strtok(NULL, ",");
        int linea = atoi(pch);
        lineas[pliegues++] = linea;
        // cout<<linea<<'\n';
    } while (1);
    return counter;
}
void pliegaLeft(int donde)
{
    // mover y quitar repes
    for (int n = 0; n < counter; n++)
    {
        if (puntos[n]->x >= donde && puntos[n]->x != -1)
            puntos[n]->x = 2 * donde - puntos[n]->x;
        for (int k = 0; k < counter; k++)
        {
            if (puntos[n]->x == puntos[k]->x && (puntos[n]->y == puntos[k]->y && n != k))
            {
                puntos[n]->x = -1;
                break;
            };
        }
    };
}
void pliegaUp(int donde)
{
    // mover y quitar repes
    for (int n = 0; n < counter; n++)
    {
        if (puntos[n]->y >= donde && puntos[n]->x != -1)
            puntos[n]->y = 2 * donde - puntos[n]->y;
        for (int k = 0; k < counter; k++)
        {
            if (puntos[n]->x == puntos[k]->x && (puntos[n]->y == puntos[k]->y && n != k))
            {
                puntos[n]->x = -1;
                break;
            };
        }
    };
}

int cuentaValidos()
{
    int validos = 0;
    for (int n = 0; n < counter; n++)
        if (puntos[n]->x != -1)
            validos++;
    return validos;
}
/*int printValidos()
{
    int validos = 0;
    for (int n = 0; n < counter; n++)
        if (puntos[n]->x != -1)
        {
            validos++;
            cout << puntos[n]->x << ',' << puntos[n]->y << '\n';
        }
    return validos;
};*/
int main()
{
    leeDatos();

    pliegaLeft(655);
    cout<<"Solucion 1:"<<cuentaValidos()<<'\n';
    pliegaUp(447);
    pliegaLeft(327);
    pliegaUp(223);
    pliegaLeft(163);
    pliegaUp(111);
    pliegaLeft(81);
    pliegaUp(55);
    pliegaLeft(40);
    pliegaUp(27);
    pliegaUp(13);
    pliegaUp(6);
    int g = cuentaValidos();
    cout << "validos:" << g << '\n';
    // printValidos();
    char dibujos[10][40];
    for (int t = 0; t < 40; t++)
        for (int p = 0; p < 10; p++)
        {
            dibujos[p][t] = ' ';
            //cout<<(char)dibujos[t][p];
        }

    for (int t = 0; t < counter; t++)
    {
        int x=puntos[t]->x;
        if(x!=-1)
        {
        int y=puntos[t]->y;
        dibujos[y][x] = 'X';
        //cout<<x<<','<<y<<'\n';
        }
    }
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 40; x++)
            cout << dibujos[y][x];
        cout << '\n';
    }
    return 0;
}