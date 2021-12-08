// Reto3.cpp: define el punto de entrada de la aplicación de consola.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include<fstream>
using namespace std;

int mapa[1000];
int cadenasValidas[1000];
char *cadenas[1000];
int counter;

int binToInt(char cadena[])
{
	int resultado=0;
		for(int n = 0; n < 12; n++)
			resultado += cadena[11-n] == '1' ? 1<<n: 0;
		return resultado;
}

int leeDatos()
{
	ifstream fe("input.txt");
	char  cadena[1024];
	//fe >> cadena;
	int count = 0;
	while (!fe.eof())
	{
		fe.getline(cadena, 512, '\n'); //carga Linea
		char *dato = new char[13];
		strcpy(dato, cadena);
		cadenas[count] = dato;
		mapa[count] = binToInt(cadena);
		count++;
	}
	/*for(int n=0;n<count;n++)
	printf("%s - %i\n", cadenas[n], mapa[n]);*/
	return count;

}
int cuentaUnos(char *cadenas[1000],int columna) //solo de validas
{
	int unos = 0;
	for (int n = 0; n < counter; n++)
		if (cadenasValidas[n]==1 && cadenas[n][columna] == '1')unos++;
	return unos;
}

int main()
{
	//inicia la matriz

	counter = leeDatos();
	for (int n = 0; n < counter; n++)
		cadenasValidas[n] = 1;
	char salida[13];
	for (int n = 0; n < 12; n++)
	{
		
		int unos = cuentaUnos(cadenas, n);
		salida[n] = unos > 500 ? '1' : '0';
		printf("unos columna %i - %i\n", n,unos );
	};
	salida[12] = '\0';
	int gamma = binToInt(salida);
	printf("Gamma: %s,%i - Epsilon:%i\n", salida, gamma, 4095 - gamma); 
		printf("Solucion 1:%i\n", gamma* (4095 - gamma));

	//----------------------------PArte 2----------------------
		//cuenta 
		int validas = 1000;
		int n,k;
		for ( n = 0; n < 12; n++)
		{

			int unos = cuentaUnos(cadenas, n);
			int ceros = validas - unos;
			char valido = unos >=ceros ? '1' : '0';
			for ( k = 0; k < counter; k++) //quita los no validos
				if (cadenasValidas[k] == 1 && cadenas[k][n] != valido)
				{
					cadenasValidas[k] = 0;
					validas--;
					if (validas == 1)break;
				}
			printf("Validas:%i Unos:%i Ceros:%i Busco:%c\n", validas,unos,ceros,valido);
			if (validas == 1)break;
		};
		for (k = 0; k < counter; k++)if (cadenasValidas[k] == 1) 
		{
			printf("%i %s\n", k, cadenas[k]); 
			break;
		}
		int oxigeno = binToInt(cadenas[k]);
		printf("Cadena buena:%i,%s,%i\n", k, cadenas[k], oxigeno);


		//validas menos
		validas = 1000;
		for (int n = 0; n < counter; n++)
			cadenasValidas[n] = 1;
		for (n = 0; n < 12; n++)
		{

			int unos = cuentaUnos(cadenas, n);
			int ceros = validas - unos;
			char valido = unos >= ceros ? '0' : '1';
			for (k = 0; k < counter; k++) //quita los no validos
				if (cadenasValidas[k] == 1 && cadenas[k][n] != valido)
				{
					cadenasValidas[k] = 0;
					validas--;
					if (validas == 1)break;
				}
			int validasBis = 0;
			for (int y = 0; y < counter; y++)if (cadenasValidas[y] == 1)validasBis++;
			printf("Validas:%i %i Unos:%i Ceros:%i Busco:%c\n", validas, validasBis, unos,ceros,valido);
			if (validas == 1)break;
		};
		for (k = 0; k < counter; k++)if (cadenasValidas[k] == 1) {
			printf("%i %s\n", k, cadenas[k]); break;
		}

		int co = binToInt(cadenas[k]);
		printf("Cadena buena:%i,%s,%i\n", k, cadenas[k], co);
		printf("SOLUCION 2: %i\n", oxigeno*co);
	getchar();
	return 0;
}
//4192244 NO
//8178
//2387790 NO
//2372923