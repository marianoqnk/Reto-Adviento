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
	do
	{
		fe.getline(cadena, 1000, '\n'); // Load one line
		pch = strtok(cadena, " |");
		// Load 10 digits signal patterns
		for (int n = 0; n < 10; n++)
		{
			char *in = new char[7];
			strcpy(in, pch);
			todosMensajes[counter].signal[n] = in;
			pch = strtok(NULL, " |");
		}
		// Load 4 digits output value
		for (int n = 0; n < 4; n++)
		{
			char *in = new char[7];
			strcpy(in, pch);
			todosMensajes[counter].value[n] = in;
			pch = strtok(NULL, " |");
		}
		counter++;
	} while (!fe.eof());
	return counter;
}

int main()
{
	printf("Starting...\n");
	leeDatos();
	int veces = 0;
	for (int n = 0; n < counter; n++)
	{
		for (int s = 0; s < 4; s++)
		{
			int len = strlen(todosMensajes[n].value[s]);
			if (len == 2 || len == 3 || len == 4 || len == 7)
				veces++;
		}
	}
	printf("The numbers times:%i\n", veces);

	//______________PART 2________________________"
	veces = 0;
	long suma = 0;
	//Process all value codes
	for (int n = 0; n < counter; n++)
	{
		char *cf= NULL, *bcdf = NULL;		
		for (auto Cadena : todosMensajes[n].signal) //search for 2 and 4 codes
		{
			int len = strlen(Cadena);
			if (len == 2) //digit 1 segments cf
				cf= Cadena;
			else if (len == 4) //digit 4 segments bcdf
				bcdf = Cadena;
		}
		// extract codes for b and d sements
		char bd[3];
		int r = 0;
		for (int c = 0; c < 4; c++)
		{
			if (bcdf[c] != cf[0] && bcdf[c] != cf[1])
			{
				bd[r++] = bcdf[c];
			}
		};
		bd[2] = '\0';
		cout  << "1: " << cf<< " 4:" << bcdf << " bd:" << bd << ' ';

		char dato[4]; //here save 4 digits of code part
		int p = 0;
		cout<<" Code7: ";
		for (auto Cadena : todosMensajes[n].value)
		{
			cout<<" "<<Cadena;
			int len = strlen(Cadena);
			switch (len)
			{
			case 2:
				dato[p] = '1';
				break;
			case 3:
				dato[p] = '7';
				break;
			case 4:
				dato[p] = '4';
				break;
			case 5: //can be 3,5 or 2
				if (strchr(Cadena, cf[0]) != NULL && strchr(Cadena, cf[1]) != NULL)
					dato[p] = '3';
				else if (strchr(Cadena, bd[0]) != NULL && strchr(Cadena, bd[1]) != NULL)
					dato[p] = '5';
				else
					dato[p] = '2';
				break;
			case 6: // can be 6,9 or 0 
				if (strchr(Cadena, cf[0]) == NULL || strchr(Cadena, cf[1]) == NULL)
					dato[p] = '6';
				else if (strchr(Cadena, bd[0]) != NULL && strchr(Cadena, bd[1]) != NULL)
					dato[p] = '9';
				else
					dato[p] = '0';
				break;
			case 7:
				dato[p] = '8';
				break;
			default:
				dato[p] = 'X';
			}
			p++;
		}
		dato[4] = '\0';
		cout << " Code Number: " << dato << '\n';
		suma += atoi(dato);
	}
	printf("Sum:%d\n", suma);
	return 0;
}
// 412
// 978171