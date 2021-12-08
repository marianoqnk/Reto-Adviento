#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
char *signal[10];
char *value[4];
struct mensaje
{
	char *signal[10];
	char *value[4];
};
mensaje todosMensajes[250];

int counter = 0;
int leeDatos()
{
	ifstream fe("input.txt");
	char cadena[1024];
	int count = 0;
	char *pch;
	while (counter<200)
	{
		fe.getline(cadena, 1000, '\n'); // carga Linea
		// 14 vece?
		pch = strtok(cadena, " |");

		for (int n = 0; n < 10; n++)
		{

			char *in = new char[8];
			strcpy(in, pch);
			// signal[n] = in;
			in[7]='\0';
			todosMensajes[counter].signal[n] = in;
			pch = strtok(NULL, " |");
		}

		for (int n = 0; n < 4; n++)
		{

			char *in = new char[7];
			strcpy(in, pch);
			// value[n] = in;
			todosMensajes[counter].value[n] = in;
			pch = strtok(NULL, " |");
		}
		counter++;
	}

	/*for (int n = 0; n < counter; n++)
	{
		for (int s = 0; s < 10; s++)
		{
			printf("%s ", todosMensajes[n].signal[s]);
		}
		printf("| ");
		for (int s = 0; s < 4; s++)
			printf("%s ", todosMensajes[n].value[s]);
		printf("\n");
	}*/
	return counter;
}

int main()
{
	printf("EMPEZando...\n");
	leeDatos();
	int veces=0;
	for (int n = 0; n < counter; n++)
	{
		for (int s = 0; s < 4; s++)
		{
			int len=strlen(todosMensajes[n].value[s]);
			if(len==2 || len==3 || len==4 || len==7) veces++;
		}
			

	}
	printf("Los numeros aparecen:%i", veces);
	return 0;
}