// Reto5.cpp: define el punto de entrada de la aplicación de consola.
//Lineas que se cruzan


#include <stdio.h>
#include <string.h>
#include <iostream>
#include<fstream>
//#include <math.h>

using namespace std;

struct Punto { int x, y; };
Punto origen[1200], destino[1200];
int mapa[1000][1000];//iniciar a cero

int leeDatos()
{
	ifstream fe("input.txt");
	char  cadena[1024];
	//fe >> cadena;
	int count = 0;
	while (!fe.eof())
	{
		fe.getline(cadena, 512, '\n'); //carga Linea
		char *pch;
		pch = strtok(cadena, ",>");
		Punto MiPunto;
		origen[count].x = atoi(pch);
		pch = strtok(NULL, ",>");
		origen[count].y = atoi(pch);
		pch = strtok(NULL, ",>");
		destino[count].x = atoi(pch);
		pch = strtok(NULL, ",>");
		destino[count].y = atoi(pch);
		count++;
	}
	//for(int n=0;n<count;n++)
	//printf("%i,%i -> %i,%i\n", origen[n].x, origen[n].y, destino[n].x, destino[n].y);
	return count;
	
}

void sennalaLinea(Punto puntoInicio, Punto puntoFin)
{
	int x = puntoInicio.x, y = puntoInicio.y;
	int dx, dy;
	
	//Solucion 1
	int incrementoX = puntoFin.x - puntoInicio.x;
	dx= (incrementoX==0)?0:incrementoX/abs(incrementoX);
	int incrementoY = puntoFin.y - puntoInicio.y;
	dy = (incrementoY==0)?0:incrementoY / abs(incrementoY);
	int incremento = abs(incrementoX) > abs(incrementoY) ? abs(incrementoX) : abs(incrementoY);
	//Alternativa
	/*
	if (puntoInicio.x == puntoFin.x) //H 
	{
		dy = puntoFin.y > puntoInicio.y ? 1 : -1; 
		dx = 0;
	}
	else if (puntoInicio.y == puntoFin.y) //V
	{
		dx = puntoFin.x > puntoInicio.x ? 1 : -1;
		dy = 0;
	}
	else //Diagonal
	{
		dy = puntoFin.y > puntoInicio.y ? 1 : -1;
		dx = puntoFin.x > puntoInicio.x ? 1 : -1;
	}
	int incrementoX = abs(puntoFin.x - puntoInicio.x);
	int incrementoY = abs(puntoFin.y - puntoInicio.y);
	int incremento = incrementoX > incrementoY ? incrementoX : incrementoY;*/
	//diagonal

	for (int k = 0; k <= incremento; k++)
	{
		mapa[x][y] += 1;
		x += dx;
		y += dy;
	}

}

int cuentaSuperposiciones()
{
	int superposiciones = 0;
	for (int x = 0; x < 1000; x++)
		for (int y = 0; y <= 1000; y++)
			if (mapa[x][y] > 1)superposiciones++;
	return superposiciones;
}
int main()
{
	//inicia la matriz
	for (int x = 0; x < 1000; x++)
		for (int y = 0; y < 1000; y++)
			mapa[x][y] = 0;
	int count= leeDatos();

	//*********************Parte 1******************************/
	for (int n = 0; n < count; n++)
	{
		if (origen[n].x == destino[n].x || origen[n].y == destino[n].y)// si son horizontales o verticales
			sennalaLinea(origen[n], destino[n]);
	}
	int solucion1 = cuentaSuperposiciones();
	printf("H y VPuntos con mas de dos: %i\n", solucion1);

	//********************* Parte 2 incluir diagonales ***********/
	//limpia mapa
	for (int x = 0; x < 1000; x++)
		for (int y = 0; y < 1000; y++)
			mapa[x][y] = 0;
	for (int n = 0; n < count; n++)		
			sennalaLinea(origen[n], destino[n]);
	int solucion2 = cuentaSuperposiciones();
	printf("H y VPuntos con mas de dos: %i\n", solucion2);
	getchar();
    return 0;
}
//5084 correcto
//20027
//17882