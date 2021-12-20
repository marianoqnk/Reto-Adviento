#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
int counter = 0;
char texto[20000];
char nueva[20000];
// char nuevaBat[10000];
/*****************************
 *  1 vuelta -> n+n-1= 2n-1
 * 2 vuelta -> 2n-1+2n-2=4n-3
 * 3 vuelta -> 4n-3+4n-4=8n-7=2^i*n-(2^i-1)= 2^i*n -2^i+1=2^i(n-1)+1
 * i vueltas -> 2^i(n-1)+1
 * 10 v -> 2^10(3)+1=1024*3+1=3072+1=3073
 * i=10 n=20 -> 2^10*19+1=1024*19+1=14457
 * i=1 n=20 2*19+1=39 20+19=39
 * i=2 39+38=77 4*19+1=77 ; i=3 77+76=153 8*19+1=153 i=4 153+152=305 16*19+1=305
 */
long k = 0, f = 0, v = 0, h = 0, s = 0, n = 0, c = 0, p = 0, o = 0;
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
        if (!strncmp(cadena, miDiccionario[n].palabra, 2))
            return miDiccionario[n].sustitucion;
    cout << "ERROR" << '\n';
    return '\0';
};
void cuenta(char c, bool suma = true)
{
    switch (c)
    {
    case 'K':
        suma?k++:k--;
        break;
    case 'F':
        suma?f++:f--;
        break;
    case 'V':
        suma?v++:v--;
        break;
    case 'H':
        suma?h++:h--;
        break;
    case 'S':
        suma?s++:s--;
        break;
    case 'N':
        suma?n++:n--;
        break;
    case 'C':
        suma?c++:c--;
        break;
    case 'P':
        suma?p++:p--;
        break;
    case 'O':
        suma?o++:o--;
        break;
    }
}
void explora(int nivel, char *silaba)
{
    char tem[3];
    char c = sustituye(silaba);
    if (nivel != 1)
    {

        tem[0] = silaba[0];
        tem[1] = c;
        tem[2] = '\0';
        explora(nivel - 1, tem);
        tem[0] = c;
        tem[1] = silaba[1];
        explora(nivel - 1, tem);
        cuenta(c,0);
    }else{
    //cout<<silaba[0]<<c<<silaba[1];
    cuenta(silaba[0]);
    cuenta(silaba[1]);
    cuenta(c);}
}
int main()
{
    leeDatos();
    char binomio[3];
    binomio[2] = '\0';
    //char texto[]="KF";
    int l=strlen(texto)-1;
    for (int x = 0; x < l; x++)
        {
            //nueva[pnueva++] = texto[n];
            binomio[0] = texto[x];
            binomio[1] = texto[x + 1];
            //char k = sustituye(binomio);
            //nueva[pnueva++] = k;
            explora(40,binomio);
        }
    /*char binomio[3];
    binomio[2] = '\0';
    int pnueva = 0;
    for (int p = 0; p < 10; p++)
    {
        pnueva = 0;
        // KFVHFSSVNCSNHCPCNPVO
        int ui = strlen(texto);
        int n;
        for (n = 0; n < strlen(texto) - 1; n++)
        {
            nueva[pnueva++] = texto[n];
            binomio[0] = texto[n];
            binomio[1] = texto[n + 1];
            char k = sustituye(binomio);
            nueva[pnueva++] = k;
        }
        nueva[pnueva++] = texto[n];
        nueva[pnueva] = '\0';
        strcpy(texto, nueva);
        cout << p + 1 << ',' << pnueva << '\n';
    }

    for (int t = 0; t < pnueva; t++)
    {

        switch (texto[t])
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
    }*/
    cout << k << ',' << f << ',' << v << ',' << h << ',' << s << ',' << n << ',' << c << ',' << p << ',' << o << ',' << '\n';
    // KFVHFSSVNCSNHCPCNPVO
    return 0;
}
// 2420
// 2509
//1913,3037,1942,1102,1670,2343,1233,1078,3587