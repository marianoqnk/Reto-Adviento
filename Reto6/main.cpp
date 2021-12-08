// Reto6.cpp: define el punto de entrada de la aplicación de consola.
// Los que se reproducen cada x dias


#include <stdio.h>
#include <string.h>
#include <iostream>
#include<fstream>
//#include <math.h>

using namespace std;

int peces[1000000];
unsigned long counter = 0;
int leeDatos()
{
	ifstream fe("input.txt");
	char  cadena[1024];
	//fe >> cadena;
	int count = 0;
	char *pch;
	fe.getline(cadena, 1000, '\n'); //carga Linea
	pch = strtok(cadena, ",");
	peces[counter++] = atoi(pch);
	while (1)
	{		

			pch = strtok(NULL, ",");
			if (pch == NULL)break;else peces[counter++] = atoi(pch);

	}
	/*for(int n=0;n<counter;n++)
	printf("%i,", peces[n]);*/
	return counter;
}
int main()
{
	int dias = 256;
	leeDatos();
	unsigned long long  diaIniciales[10];
	//Count how many in each day
	for (int k = 0; k < 9; k++)
	{
		int d = 0;
		for (int n = 0; n < counter; n++)
			if (peces[n] == k)d++;
		diaIniciales[k] = d;
		//printf("%i - %i\n", k, d);
	}

	int d;
	unsigned long long  suma = 0;
	for ( d = 0; d < dias; d++)//interpola dia a dia para comprobar
	{
		unsigned long long t = diaIniciales[0];
		for (int n = 0; n < 9; n++)
			diaIniciales[n] = diaIniciales[n+1];
		diaIniciales[6] += t;
		diaIniciales[8] = t;
		suma = 0;
		for (int n = 0; n < 9; n++)
			suma += diaIniciales[n];
		if(d==79)printf("dia %i :%llu\n", d + 1, suma);		
	}
	printf("dia %i :%llu\n", d + 1, suma);
	getchar();
    return 0;
}
//391888
//1754597645339