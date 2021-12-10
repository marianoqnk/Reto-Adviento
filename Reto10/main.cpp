#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
int counter = 0;
int puntuacionTotal=0;
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
        // pch = strtok(cadena, "{([<>])}"); //open and closed Chunk
        // char *in = new char[strlen(cadena)];
        // strcpy(in, pch);
        // all[counter++] = in;
        int points = 0;
        for (auto c : cadena)
        {
            switch (c)
            {
            case '(':
                parentesis++;
                break;

            case ')':
                if (parentesis == 0) // line error
                {
                    error = true;
                    points = 3;
                    break;
                }
                parentesis--;
                break;
            case '[':
                corchetes++;
                break;

            case ']':
                if (corchetes == 0) // line error
                {
                    error = true;
                    points = 57;
                    break;
                }
                corchetes--;
                break;
            case '{':
                llaves++;
                break;

            case '}':
                if (llaves == 0) // line error
                {
                    error = true;
                    points = 1197;
                    break;
                }
                llaves--;
                break;
            case '<':
                angulos++;
                break;

            case '>':
                if (angulos == 0) // line error
                {
                    error = true;
                    points = 25137;
                    break;
                }
                angulos--;
                break;
            }
            if (error)
                break;
        }
        cout << "Puntos: " << points << '\n';
        puntuacionTotal+=points;
    } while (!fe.eof());
    /*// Test data input
    for (auto cadena : all)
         cout << cadena << '\n';*/
    return counter;
}

int main()
{
    printf("Starting...\n");
    leeDatos();
    cout<<"Total: "<<puntuacionTotal<<'\n';
    return 0;
}
//155067