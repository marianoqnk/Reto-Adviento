// Reto 4 BINGO
#include <stdio.h>
#include <string.h>
#include <iostream>
#include<fstream>
#include <math.h>
using namespace std;
int numerosSorteo[1024];//Guarda los número que han salido
int * cartones[100];



void separaComas(char *str)
{
	char *pch;
	pch = strtok(str, " ,.-");
	int n = 0;
	while (pch != NULL)
	{
		numerosSorteo[n++] = atoi(pch);
		//printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
	printf("Leidos Sorteo:%i\n", n);
}

void cargaLinea(char *str,int p[5])
{
	char *pch;
	pch = strtok(str, " ,.-");
		for (int k = 0; k < 5; k++)
		{
			p[k] = atoi(pch);
			pch = strtok(NULL, " ,.-");
		}

}

void printCarton(int carton[5][5])
{
	for (int n = 0; n < 5; n++)
	{
		for (int k = 0; k < 5; k++)
			printf("%i ", carton[n][k]);
		printf("\n");
	}
	printf("\n");
}

void muestraDatos()
{
	printf("Los numeros leidos son:\n");
	for (int n = 0; n < 100; n++)
	{
		printf("%i,", numerosSorteo[n]);
	}
	printf("\n");
	printf("Los cartones leidos son:\n");
	for (int n = 0; n < 100; n++)
	{
		printf("Carton %i:\n", n);
		int (*carton)[5] =( int (*)[5]) cartones[n];
		printCarton(carton);
	}

}

int compruebaLinea(int linea[5])
{
	int acertados = 0,n;
	for ( n = 0; n < 100; n++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (numerosSorteo[n] == linea[k])acertados++;
		}
		if (acertados == 5)break;
	}
	return n;
}

void giraCarton(int carton[5][5], int temp[5][5])
{
	//gira
	for (int n = 0; n < 5; n++)
	{
		for (int k = 0; k < 5; k++)
		{
			temp[n][k] = carton[k][n];
		}
	}
}

int sumaNoPremiados(int carton[5][5],int max)
{
	int suma = 0;
	for (int n = 0; n < 5; n++)
	{
		for (int k = 0; k < 5; k++)
		{
			int p;
			for (p = 0; p < max+1; p++)
			{
				if (carton[n][k] == numerosSorteo[p])break;
			}
			if(p>max)
				suma += carton[n][k];
			//printf("%i\n", suma);

		}
	}
	return suma;

}

int main(void)
{
	
	ifstream fe("dia4.txt");
	char  cadena[1024];
	fe >> cadena;
	separaComas(cadena);
	int leeCarton = 0;
	fe.getline(cadena, 512, '\n');
	while (!fe.eof()) {
		fe.getline(cadena, 512, '\n');
		int (*temp)[5]=new int[5][5];
		for (int p = 0; p < 5; p++)
		{
			fe.getline(cadena, 512, '\n');
			cargaLinea(cadena, temp[p]);
		}
		cartones[leeCarton] =(int *) temp;
		leeCarton++;
		//printf("Leidos: %i cartones\n", leeCarton);
	}
	//-------------------------------------muestraDatos();

	int extracion = 500;
	int cartonPremiado,ultimoNumero;
	//Comprueba filas y columnas 
	int mTemp[5][5];
	int(*temp)[5] = mTemp;
	for (int n = 0; n < 100; n++)
	{
	
		int(*carton)[5] = (int(*)[5]) cartones[n];
		giraCarton(carton, temp);
		for (int k = 0; k < 5; k++)
		{
			int actual = compruebaLinea(carton[k]);
			if (extracion > actual) { extracion = actual, cartonPremiado = n; }
			actual = compruebaLinea(temp[k]);
			if (extracion>actual){extracion = actual , cartonPremiado = n;	}
			//printf("EXtraccion:%i Carton:%i\n", extracion, cartonPremiado);
		}

	}

	printf("la minima es:%i Carton:%i Ultimo Numero: %i\n", extracion, cartonPremiado, numerosSorteo[extracion]);
	printCarton((int(*)[5])cartones[cartonPremiado]);
	int suma = sumaNoPremiados((int(*)[5])cartones[cartonPremiado], extracion);
	printf("SUMA: %i\n",suma);
	printf("SOLUCION: %i\n", suma*numerosSorteo[extracion]);
	//-----------------------PARTE 2 Ultimo en ganar----------------------
	extracion = 0;
	for (int n = 0; n < 100; n++)
	{

		int(*carton)[5] = (int(*)[5]) cartones[n];
		giraCarton(carton, temp);
		int minimaCarton = 500;
		for (int k = 0; k < 5; k++)
		{
			int actual = compruebaLinea(carton[k]);
			if (minimaCarton > actual) { minimaCarton = actual; }
			actual = compruebaLinea(temp[k]);
			if (minimaCarton> actual) { minimaCarton = actual; }
			//printf("EXtraccion:%i Carton:%i\n", extracion, cartonPremiado);
		}
		//printf("Carton:%i turno:%i\n", n, minimaCarton);
		if (minimaCarton > extracion)
		{
			extracion = minimaCarton;
			cartonPremiado = n;
		}

	}
	printf("la Maxima es:%i Carton:%i Ultimo Numero: %i\n", extracion, cartonPremiado, numerosSorteo[extracion]);
	printCarton((int(*)[5])cartones[cartonPremiado]);
	suma = sumaNoPremiados((int(*)[5])cartones[cartonPremiado], extracion);
	printf("SUMA: %i\n",suma );
	printf("SOLUCION: %i\n", suma*numerosSorteo[extracion]);
	getchar();
	return 0;
}
