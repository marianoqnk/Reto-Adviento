#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

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

struct Extremos
{
    unsigned long long int min, max;
};

unordered_map<string, unsigned long long> cuentaPares;
unordered_map<string, char> mapeado;
char last;
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
        auto par = cuentaPares.insert({{cadena[n], cadena[n + 1]}, 1}); // devuelve iterador al primer elemento y bool si se ha insertado corectamente
        if (!par.second)
            par.first->second++; // ya existe el par y lo que hay que hacer es incrementar
    };
    // contar el ultimo
    last = cadena[cadena.size() - 1];
    getline(fe, cadena);
    while (getline(fe, cadena))
    {

        string par{cadena[0], cadena[1]};
        char res = cadena[6];
        mapeado.insert({par, res});
        // cout<<"x:"<<miPoint->x<<"y:"<<miPoint->y<<'\n';
    };

    return 0;
}

Extremos cuenta()
{
    unsigned long long int min = ULLONG_MAX, max = 0;
    unordered_map<char, unsigned long long> contadores;
    for (auto k : cuentaPares)
    {
        // busca la primera letra la funcion devuelve un puntero a ella, si está la hacemos igual al valor del par
        auto p1 = contadores.insert({k.first[0], k.second}); // inserta y si hay error es que ya existe
        if (!p1.second)                                      // como hay error es que ya existe y entonce sumo
            p1.first->second += k.second;
        
    }
    auto it_p = contadores.insert({last, 1});
    if (!it_p.second)
        it_p.first->second++;
    for (auto p : contadores)
    {
        max = p.second > max ? p.second : max;
        min = p.second < min ? p.second : min;
    }

    return {min, max};
}

void algoritmo()
{
    // KF->KVF para el siguiente KV + VF
    auto temp = cuentaPares; // lo hace porque no puedo manipular el mapa mientras lo recorro
    for (auto k : cuentaPares)
    {
        temp.find(k.first)->second -= k.second;             // busca el par y lo resta porque lo va a convertir en 2 pares KF
        char c = mapeado.find(k.first)->second;             // mapa de sustituciones
        auto p1 = temp.insert({{k.first[0], c}, k.second}); // KV
        auto p2 = temp.insert({{c, k.first[1]}, k.second}); // VF
        if (!p1.second)                                     // si no se ha insertado se crea nuevo
            p1.first->second += k.second;
        if (!p2.second) // si no se ha insertado se crea nuevo
            p2.first->second += k.second;
    }
    cuentaPares = temp;
};
int main()
{
    leeDatos();
    for(size_t i = 0; i < 40; i++)
		algoritmo();

	Extremos extr = cuenta();

	std::cout << extr.max - extr.min << std::endl;

    
    // KFVHFSSVNCSNHCPCNPVO*/
    return 0;
}
// 2420
// 1913,3037,1942,1102,1670,2343,1233,1078,3587