#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
char *all[100];
char marcados[100][100];
int counter = 0;
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
            if ((k==99?1:all[n][k] < all[n][k + 1]) && (k == 0 ? 1 : all[n][k] < all[n][k - 1]) &&
                (n == counter - 1 ? 1 : all[n][k] < all[n + 1][k]) && (n == 0 ? 1 : all[n][k] < all[n - 1][k]))
            {

                valor2 = all[n][k] - 48 + 1;
                suma2 += valor2;
            }

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

            if (valor2 != valor)
            {
                if (n > 0)
                    cout << all[n - 1] << '\n';
                cout << all[n] << '\n';
                if (n < counter - 1)
                    cout << all[n + 1] << '\n';

                printf("pos %i,%i minimo %i\n", n, k, valor);
                printf("2-pos %i,%i minimo %i\n", n, k, valor2);
                cout << "suma: " << suma << " Suma2:" << suma2 << '\n';
                // suma2=suma;
            }
        }
        cout << "linea: " << n << " suma: " << suma << " suma2: " << suma2 << '\n';
    }

    return suma;
};

long compruebaAltura(int x,int y)
{
    int misMarcados=0;
    //comprobar limites para que no se salgo 0 100 
    if(marcados[x+1][y]==0 && all[x+1][y]!='9' && all[x+1][y]>all[x][y] ) 
    {
        misMarcados++;
        misMarcados+=compruebaAltura(x+1,y);
    };
    if(marcados[x-1][y]==0) 
    {
        misMarcados++;
        misMarcados+=compruebaAltura(x-1,y);
    };
    if(marcados[x][y+1]==0) 
    {
        misMarcados++;
        misMarcados+=compruebaAltura(x+1,y);
    };
    if(marcados[x][y-1]==0) 
    {
        misMarcados++;
        misMarcados+=compruebaAltura(x+1,y);
    };
 
    return misMarcados;
}
int main()
{
    printf("Starting...\n");
    leeDatos();
    buscaMinimos();

    return 0;
}
// 500
//
