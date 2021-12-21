#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
//Inicio
long long player1Pos=8;
long long player2Pos=6;

long long player1Point=0;
long long player2Point=0;
unsigned int pointsToWin=1000;
long veces=0;
int dado()
{ 
    static unsigned int puntos=1;
    veces++;
    if(puntos==101)puntos=1;
    //cout<<puntos<<' ';
    return puntos++;
}
int main()
{
    //turno 1
    do{
    //cout<<"P1 ";
    player1Pos+=dado()+dado()+dado();
    int pos=player1Pos%10;
    if(pos==0)pos=10;
    player1Point+=pos;
    if(player1Point>=pointsToWin)break;
    //cout<<" Pos:"<<pos<<" Puntos:"<<player1Point<<'\n';
    //cout<<"P2 Pos:"<<' ';
    player2Pos+=dado()+dado()+dado();
    pos=player2Pos%10;
    if(pos==0)pos=10;
    player2Point+=pos;
    //cout<<" Pos:"<<pos<<" Puntos:"<<player2Point<<'\n';
    }while(player1Point<pointsToWin && player2Point<pointsToWin);
    cout<< ((player1Point>pointsToWin)?"WIN PLLAYER1":"WIN PLLAYER2 ")<<"Tiradas: "<<veces<<'\n';
    cout<< "P1:"<<player1Point<< " P2: "<<player2Point<<'\n';
    cout<<"Solucion: "<<(veces*(player1Point>player2Point?player2Point:player1Point))<<'\n';
    return 0;
}