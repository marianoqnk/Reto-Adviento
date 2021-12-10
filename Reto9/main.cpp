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
    /*// Test data input 
    for (auto cadena : all)
         cout << cadena << '\n';*/
    return counter;
}
long compruebaAltura(int x, int y)
{
    long misMarcados = 0;
    marcados[x][y] = 1;
    if (y < 99 && marcados[x][y + 1] == 0 && all[x][y + 1] != '9' && all[x][y + 1] > all[x][y])
    {
        misMarcados++;
        misMarcados += compruebaAltura(x, y + 1);
    };
    if (y > 0 && marcados[x][y - 1] == 0 && all[x][y - 1] != '9' && all[x][y - 1] > all[x][y])
    {

        misMarcados++;
        misMarcados += compruebaAltura(x, y - 1);
    };
    if (x < 99 && marcados[x + 1][y] == 0 && all[x + 1][y] != '9' && all[x + 1][y] > all[x][y])
    {
        misMarcados++;
        misMarcados += compruebaAltura(x + 1, y);
    };
    if (x > 0 && marcados[x - 1][y] == 0 && all[x - 1][y] != '9' && all[x - 1][y] > all[x][y])
    {
        misMarcados++;
        misMarcados += compruebaAltura(x - 1, y);
    };

    return misMarcados;
}

long buscaMinimos()
{
    long suma = 0;
    int n = 0, valor;
    for (n = 0; n < counter; n++)
    {
        for (int k = 0; k < 100; k++)
        {

            if (k > 0) // search left
                if (!(all[n][k] < all[n][k - 1]))
                    continue;
            if (k < counter - 1) // search right
                if (!(all[n][k] < all[n][k + 1]))
                    continue;
            if (n > 0) // search down
                if (!(all[n][k] < all[n - 1][k]))
                    continue;
            if (n < 99) // search up
                if (!(all[n][k] < all[n + 1][k]))
                    continue;
            valor = all[n][k] - '0' + 1;
            suma += valor;

            long valleSize = 0;
            valleSize = compruebaAltura(n, k) + 1;
            if (valleSize > maxValle[2])
            {
                maxValle[2] = valleSize;
                if (valleSize > maxValle[1])
                {
                    maxValle[2] = maxValle[1];
                    maxValle[1] = valleSize;
                    if (valleSize > maxValle[0])
                    {
                        maxValle[1] = maxValle[0];
                        maxValle[0] = valleSize;
                    }
                }
            }
            /*if (n > 0)
                cout << all[n - 1] << '\n';
            cout << all[n] << '\n';
            if (n < counter - 1)
                cout << all[n + 1] << '\n';

            printf("pos %i,%i minimo %i\n", n, k, valor);
            cout << "suma: " << suma << "Tamaño: " << valleSize << '\n';*/
        }
        // cout << "linea: " << n << " suma: " << suma << '\n';
    }

    return suma;
};

int main()
{
    printf("Starting...\n");
    leeDatos();
    cout << "Suma: " << buscaMinimos() << '\n';
    cout << "Tres mayores valles:" << maxValle[0] << ',' << maxValle[1] << ',' << maxValle[2] << '\n';
    cout << "producto:" << maxValle[0] * maxValle[1] * maxValle[2] << '\n';
    return 0;
}
// 500
// 970200
