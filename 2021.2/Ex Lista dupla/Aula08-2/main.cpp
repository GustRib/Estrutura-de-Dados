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
    ListaDupla l, l2, l3;

    l.insereInicio(3);
    l3.insereInicio(5);
    l3.insereInicio(2);
    l3.insereInicio(12);
    l3.insereInicio(4);
    l3.insereInicio(13);
    l3.insereInicio(-1);

    l.imprime();
    l2.imprime();

    l.adicionaListaFinal(&12);
    l.imprime();
    l2.imprime();

    return 0;
};

