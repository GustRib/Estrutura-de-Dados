#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1); /// retorna um numero inteiro aleat�rio entre a e b
}

int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 10;
    srand(time(NULL));

    for(int i = 1; i <= NumNos; i++)
        l.insereInicio(numAleatorio(0, 50));

    l.imprime();
    l.insereDepoisMenor(60);
    l.imprime();
    l.insereDepoisMenor(70);
    l.imprime();
    l.insereDepoisMenor(80);
    l.imprime();
    
    return 0;
};

