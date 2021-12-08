//Day 1 Reto 1
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
    unsigned int count = 0, anterior = 10000, n;
    string linea;
    ifstream archivo("input1.txt");
    while (getline(archivo, linea))
    {
        sscanf(linea.c_str(),"%i", &n);
        if (n > anterior)
            ++count;
        anterior = n;
    }
    cout << count;
}