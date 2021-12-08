#include <stdio.h>
#include <string.h>
#include <iostream>
#include<fstream>
//using namespace std;

int peces[1000000];
unsigned long counter = 0;
int leeDatos()
{
	ifstream fe("input.txt");
	char  cadena[1024];
	int count = 0;
	char *pch;
	fe.getline(cadena, 1000, ','); //carga Linea
	pch = strtok(cadena, ",");
	peces[counter++] = atoi(pch);
	while (1)
	{
		fe.getline(cadena, 1000, ',');
		pch = strtok(cadena, ",");
		if (pch == NULL)break; else peces[counter++] = atoi(pch);

	}
	/*for(int n=0;n<counter;n++)
	printf("%i,", peces[n]);*/
	return counter;
}
unsigned long long calculaCoste(unsigned long long km)
{
	unsigned long long suma=0;
	for (int n = 0; n < km; n++)suma += n;
	return suma;

}
int main()
{
	int dias = 256;
	leeDatos();
	unsigned long long km =10000000000000 ;
	
	for (int n = 0; n < 3000; n++) //todos al punto n
	{
		int punto = n;
		unsigned long long distanciaActual=0;
		for (int k = 0; k < counter; k++)
		{
			unsigned long long  distancia= abs(peces[k] - punto);
			unsigned long long gasto = (distancia*(distancia + 1)) / 2;
			distanciaActual += gasto;
			
		}
		if (distanciaActual < km)km= distanciaActual;
		printf("distancia: %lu\n", distanciaActual);
	}
	printf("Distancia minima:%lu", km);
	getchar();
	return 0;
}
//352331
//99266343 NO