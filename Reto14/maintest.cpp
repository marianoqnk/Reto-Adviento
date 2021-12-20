#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
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
 *Haciendolo por recurrencia a lo bruto tarda muchisimo, quizas si se guardan resutados parciales se tarde menos
 Compiado de otra persona:
 https://github.com/Ily3s/AdventOfCode2021/tree/master/Day14
 lo que hace es contar cuantos pares hay de cada cosa en la cadena inicial
 luego en cada interaccion cuenta que por cada par en la sustitucion se generan dos pares p.e. KF en la sustitucion salen KH y HF luego habra un
 KF un KH y un HF. Al hacer la cuenta tengo que restar
 KF->KHF
 */
long k = 0, f = 0, v = 0, h = 0, s = 0, n = 0, c = 0, p = 0, o = 0;
struct Sum
{
    long k = 0, f = 0, v = 0, h = 0, s = 0, n = 0, c = 0, p = 0, o = 0;
};
struct Extremos
{
	unsigned long long int min, max;
};
struct diccionario
{
    char palabra[3];
    char sustitucion;
};

struct Almacen
{
    int n;
    char palabra[3];
    Sum *su;
};
diccionario miDiccionario[100];
Almacen *almacen[4000];
unordered_map<string, unsigned long long> cuentaPares;
unordered_map<string, char> mapeado;

int palmacen = 0;
array<unsigned long, 26> mapa;
int leeDatos()
{
    std::ifstream fe("input.txt");
    string cadena;
    getline(fe, cadena);
    // genera pares
    for (auto n = 0; n < (cadena.length() - 1); n++)
    {
        auto par = cuentaPares.insert({{cadena[n], cadena[n + 1]}, 1});//devuelve iterador al primer elemento y bool si se ha insertado corectamente
        if (!par.second)
            par.first->second++;//ya existe el par y lo que hay que hacer es incrementar
    };
    // contar el ultimo
    getline(fe, cadena);
    while (getline(fe, cadena))
    {

        string par{cadena[0], cadena[1]};
        char res = cadena[6];
        mapeado.insert({par, res});
        // cout<<"x:"<<miPoint->x<<"y:"<<miPoint->y<<'\n';
    };

    return counter;
}

Extremos cuenta()
{
    unordered_map<char,unsigned long long> contadores;
    for(auto k:cuentaPares)
 {
     contadores.find(k.first[0])->
     contadores.insert({'a',1});
 }
}

void algoritmo()
{
    //KF->KVF para el siguiente KV + VF
    auto temp = cuentaPares; // lo hace porque no puedo manipular el mapa mientras lo recorro
 for(auto k:cuentaPares)
 {
     temp.find(k.first)->second-=k.second; //busca el par y lo resta porque lo va a convertir en 2 pares KF
     char c = mapeado.find(k.first)->second; //mapa de sustituciones
		auto p1 = temp.insert({{k.first[0], c}, k.second});//KV
		auto p2 = temp.insert({{c, k.first[1]}, k.second});//VF
		if(!p1.second)//si no se ha insertado se crea nuevo
			p1.first->second += k.second;
		if(!p2.second)//si no se ha insertado se crea nuevo
			p2.first->second += k.second;
}
cuentaPares=temp;
};
int main()
{
    leeDatos();
    algoritmo();
    /*char binomio[3];
    binomio[2] = '\0';
    //char texto[]="KF\0";
    int l=strlen(texto)-1;
    for (int x {0}; x < l; x++)
        {
            //nueva[pnueva++] = texto[n];
            binomio[0] = texto[x];
            binomio[1] = texto[x + 1];
            //char k = sustituye(binomio);
            //nueva[pnueva++] = k;
            explora(10,binomio);
        }

    cout << k << ',' << f << ',' << v << ',' << h << ',' << s << ',' << n << ',' << c << ',' << p << ',' << o << ',' << '\n';
    // KFVHFSSVNCSNHCPCNPVO*/
    return 0;
}
// 2420
// 2509
// 1913,3037,1942,1102,1670,2343,1233,1078,3587