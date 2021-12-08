//day2 reto 2
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
    unsigned int count = 0, anterior = 0, n,sale[3];
    string linea;
    ifstream archivo("input1.txt");

    getline(archivo, linea);
    sscanf(linea.c_str(),"%i", &n);
    sale[0]=n;
    anterior+=n;

    getline(archivo, linea);
    sscanf(linea.c_str(),"%i", &n);
    sale[1]=n;
    anterior+=n;

    getline(archivo, linea);
    sscanf(linea.c_str(),"%i", &n);
    sale[2]=n;
    anterior+=n;

    while (getline(archivo, linea))
    {
        sscanf(linea.c_str(),"%i", &n);
        if (n > anterior)
            ++count;
        anterior=anterior+n-sale;
        anterior = n;
    }
    cout << count;
}