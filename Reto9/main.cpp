#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
char *all[100];
char marcados[100][100];
int counter = 0;
int maxValle[3];
int leeDatos()
{
    ifstream fe("input.txt");
    char cadena[1024];
    char *pch;
    do
    {
        fe.getline(cadena, 1000, '\n'); // Load one line
        if (strlen(cadena) == 0)
            break;
        pch = strtok(cadena, " |");
        char *in = new char[strlen(cadena)];
        strcpy(in, pch);
        all[counter++] = in;
    } while (!fe.eof());
    /* for (auto cadena : all)
         cout << cadena << '\n';*/
    return counter;
}
long compruebaAltura(int x, int y)
{
    long misMarcados = 0;
    // comprobar limites para que no se salgo 0 100
    marcados[x][y] = 1;
    if (y < 99 && marcados[x][y + 1] == 0 && all[x][y + 1] != '9' && all[x][y + 1] > all[x][y])
    {
        //marcados[x][y] = 1;
        misMarcados++;
        misMarcados += compruebaAltura(x, y+1);
    };
    if (y > 0 && marcados[x][y - 1] == 0 && all[x][y - 1] != '9' && all[x][y - 1] > all[x][y])
    {
        //marcados[x][y] = 1;
        misMarcados++;
        misMarcados += compruebaAltura(x, y-1);
    };
    if (x < 99 && marcados[x + 1][y] == 0 && all[x + 1][y] != '9' && all[x + 1][y] > all[x][y])
    {
        //marcados[x][y] = 1;
        misMarcados++;
        misMarcados += compruebaAltura(x + 1, y);
    };
    if (x > 0 && marcados[x - 1][y] == 0 && all[x - 1][y] != '9' && all[x - 1][y] > all[x][y])
    {
        //marcados[x][y] = 1;
        misMarcados++;
        misMarcados += compruebaAltura(x - 1, y);
    };

    return misMarcados;
}

long buscaMinimos()
{
    long suma = 0, suma2 = 0;
    int n = 0, valor, valor2;
    for (n = 0; n < counter; n++)
    {
        /*if (n > 0)
            cout << all[n - 1] << '\n';
        cout << all[n] << '\n';
        if (n < counter - 1)
            cout << all[n + 1] << '\n';*/
        for (int k = 0; k < 100; k++)
        {
            /*if ((k==99?1:all[n][k] < all[n][k + 1]) && (k == 0 ? 1 : all[n][k] < all[n][k - 1]) &&
                (n == counter - 1 ? 1 : all[n][k] < all[n + 1][k]) && (n == 0 ? 1 : all[n][k] < all[n - 1][k]))
            {

                valor2 = all[n][k] - 48 + 1;
                suma2 += valor2;
            }*/

            bool min = false;
            if (k > 0) // compara con anterior
                if (all[n][k] < all[n][k - 1])
                    min = false;
                else
                    continue;
            if (k < counter - 1) // compara con siguiente
                if (all[n][k] < all[n][k + 1])
                    min = false;
                else
                    continue;
            if (n > 0) // compara con anterior
                if (all[n][k] < all[n - 1][k])
                    min = false;
                else
                    continue;
            if (n < 99) // compara con siguiente
                if (all[n][k] < all[n + 1][k])
                    min = false;
                else
                    continue;
            min = false;
            valor = all[n][k] - 48 + 1;
            suma += valor;

            if (1)
            {
                long valleSize = 0;
                valleSize = compruebaAltura(n, k)+1;
                if(valleSize>maxValle[2])
                {
                    maxValle[2]=valleSize;
                    if(valleSize>maxValle[1])
                    {
                        maxValle[2]=maxValle[1];
                        maxValle[1]=valleSize;
                        if(valleSize>maxValle[0])
                        {
                           maxValle[1]=maxValle[0];
                        maxValle[0]=valleSize; 
                        }
                    }
                }
                /*if (n > 0)
                    cout << all[n - 1] << '\n';
                cout << all[n] << '\n';
                if (n < counter - 1)
                    cout << all[n + 1] << '\n';

                printf("pos %i,%i minimo %i\n", n, k, valor);
                // printf("2-pos %i,%i minimo %i\n", n, k, valor2);
                cout << "suma: " << suma << "Tamaño: " << valleSize << '\n';*/
                cout<<"tamano: "<<valleSize<<'\n';
                // suma2=suma;
            }
        }
        //cout << "linea: " << n << " suma: " << suma << " suma2: " << suma2 << '\n';
    }

    return suma;
};

int main()
{
    printf("Starting...\n");
    leeDatos();
    buscaMinimos();
    cout<<"Tres mayores valles:"<<maxValle[0]<<','<<maxValle[1]<<','<<maxValle[2]<<'\n';
    cout<<"producto:"<<maxValle[0]*maxValle[1]*maxValle[2]<<'\n';
    return 0;
}
// 500
//970200
