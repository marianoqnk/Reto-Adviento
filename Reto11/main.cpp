#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
unsigned int pulpos[10][10];

int leeDatos()
{
    std::ifstream fe("input.txt");
    string cadena;
    for(int n=0;n<10;n++)
    {
        getline(fe, cadena);
        for(int k=0;k<10;k++)
        {
             
        }

    }

    while (getline(fe, cadena))
    {

        string par{cadena[0], cadena[1]};
        char res = cadena[6];
        mapeado.insert({par, res});
        // cout<<"x:"<<miPoint->x<<"y:"<<miPoint->y<<'\n';
    };

    return 0;
}

int main()
{
    leeDatos();
    for(size_t i = 0; i < 40; i++)
		algoritmo();

	Extremos extr = cuenta();

	std::cout << extr.max - extr.min << std::endl;

    
    // KFVHFSSVNCSNHCPCNPVO*/
    return 0;
}