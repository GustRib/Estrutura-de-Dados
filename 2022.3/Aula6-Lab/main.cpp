#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"
#include "ListaEncad.cpp"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1) ; /// retorna um numero inteiro aleatorio entre a e b
}

int main()
{
    ListaEncad l; /// cria lista vazia
    int NumNos = 49;

    srand(time(NULL));
    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleatorio entre 0 e 50
        cout << val << ", ";
        l.insereInicio(val);
    }
    cout << endl;

    bool existe = l.busca(13);
    cout << "O valor 13 esta na lista? " << endl;
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    return 0;
};

