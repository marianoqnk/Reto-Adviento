#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <stack>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
int counter = 0;
long puntuacionTotal = 0;
char pila[200];
int ppila = 0;
int incompletas=0;
long long resultados[50];
char cierre(char c)
{
    if (c == '(')
        return '(' + 1;
    else
        return c + 2;
}
int leeDatos()
{
    ifstream fe("input.txt");
    char cadena[1024];
    char *pch;
    int parentesis = 0, corchetes = 0, llaves = 0, angulos = 0;
    do
    {
        bool error = false;
        parentesis = 0, corchetes = 0, llaves = 0, angulos = 0;
        fe.getline(cadena, 1000, '\n'); // Load one line
        if (strlen(cadena) == 0)
            break;
        int points = 0;
        int y = 0;
        for (y = 0; y < strlen(cadena); y++)
        {
            char c = cadena[y];
            // cout<<c;
            if (c == '(' || c == '[' || c == '{' || c == '<')
            {
                pila[++ppila] = c;
            }
            else
            {
                char k = cierre(pila[ppila--]);
                if (c != k)
                {
                    cout << "Error en linea,punto:" << counter << "," << y << " cara " << c << ' ' << k << '\n';
                    switch (c)
                    {
                    case ')':
                        points = 3;
                        break;
                    case ']':
                        points = 57;
                        break;
                    case '}':
                        points = 1197;
                        break;
                    case '>':
                        points = 25137;
                        break;
                    }
                    break;
                };
            }
        }
        if(points==0)//linea incompleta
        {
            //vaciar la pila
            
            long long points2=0;
            while(ppila>0)
            {
                char c=cierre( pila[ppila--]);
                cout<<c;
                points2*=5;
                switch (c)
                    {
                    case ')':
                        points2 += 1;
                        break;
                    case ']':
                        points2 += 2;
                        break;
                    case '}':
                        points2 += 3;
                        break;
                    case '>':
                        points2 += 4;
                        break;
                    }


            }
            cout<<points2<<'\n';
            resultados[incompletas++]=points2;
        }
        puntuacionTotal += points;
        ppila = 0;
        counter++;
    } while (!fe.eof());
    return counter;
}

int main()
{
    printf("Starting...\n");
    leeDatos();
    cout << "Total: " << puntuacionTotal << '\n';
    cout<<"Incompletas :"<<incompletas<<'\n';
    std::vector<long long> mivector(resultados,resultados+incompletas);
    std::sort(mivector.begin(),mivector.end());
    int cuenta=1;
    for (std::vector<long long>::iterator it=mivector.begin(); it!=mivector.end(); ++it)
    std::cout<<cuenta++<< ' ' << *it<<'\n';
        std::cout << '\n';
    return 0;
}
// 155067