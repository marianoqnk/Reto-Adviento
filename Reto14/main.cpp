#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
int counter = 0;
char texto[20000];
char nueva[20000];
//char nuevaBat[10000];
/*****************************
 *  1 vuelta -> 2n-1
 * 2 vuelta -> 4n-3
 * i vueltas -> 2^i(n-1)+1
 * 10 v -> 2^10(3)+1=1024*3+1=3072+1=3073
 *
 *
 */
struct diccionario
{
    char palabra[3];
    char sustitucion;
};
diccionario miDiccionario[100];
int leeDatos()
{
    ifstream fe("input.txt");
    char cadena[1024];
    char *pch;
    fe.getline(cadena, 1000, '\n');
    strcpy(texto, cadena);
    fe.getline(cadena, 1000, '\n');
    do
    {

        fe.getline(cadena, 1000, '\n');
        if (strlen(cadena) == 0)
            break;
        pch = strtok(cadena, " ");
        strcpy(miDiccionario[counter].palabra, pch);
        pch = strtok(NULL, " ");
        pch = strtok(NULL, " ");
        miDiccionario[counter++].sustitucion = pch[0];
        // cout<<"x:"<<miPoint->x<<"y:"<<miPoint->y<<'\n';
    } while (1);

    return counter;
}
char sustituye(char *cadena)
{
    for (int n = 0; n < counter; n++)
        if (!strncmp(cadena, miDiccionario[n].palabra,2))
            return miDiccionario[n].sustitucion;
    cout<<"ERROR"<<'\n';
    return '\0';
};

int main()
{
    leeDatos();
    char binomio[3];
    binomio[2] = '\0';
    int pnueva=0;
    for(int p=0;p<10;p++)
    {
    pnueva=0;
    for (int n = 0; n < strlen(texto) - 1; n++)
    {
        nueva[pnueva++]=texto[n];
        binomio[0] = texto[n];
        binomio[1] = texto[n + 1];
        char k=sustituye(binomio);
        nueva[pnueva++]=k;       
    }
    nueva[pnueva]='\0';
    strcpy(texto,nueva);
    cout<<p<<','<<pnueva<<'\n';
    }
     int k=0,f=0,v=0,h=0,s=0,n=0,c=0,p=0,o=0;
    for(int t=0;t<pnueva;t++)
    {
        
        switch(texto[t])
        {
            case 'K':
                k++;
                break;
            case 'F':
            f++;
                break;
            case 'V':
            v++;
                break;
            case 'H':
            h++;
                break;
            case 'S':
            s++;
                break;
            case 'N':
            n++;
                break;
            case 'C':
            c++;
                break;
            case 'P':
            p++;
                break;
            case 'O':
            o++;
                break;
        }

    }
    cout<<k<<','<<f<<','<<v<<','<<h<<','<<s<<','<<n<<','<<c<<','<<p<<','<<o<<','<<'\n';
    //KFVHFSSVNCSNHCPCNPVO
    return 0;
}
//2420