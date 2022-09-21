#include <iostream>
#include <cmath>
#include "Caminho.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q3
Caminho::Caminho(int nn)
{
    // Implemente aqui sua solução para a questão 3 letra A.
    // Se necessário, remova o código abaixo.
    n = -1;
}

Caminho::~Caminho()
{
    // Implemente aqui sua solução para a questão 3 letra A.
}

int Caminho::calculaDistanciaPercorrida(int **distancias)
{
    // Implemente aqui sua solução para a questão 3 letra B.
    // Se necessário, remova o código abaixo.
    return 0;
}

void Caminho::buscaGulosa(int **distancias)
{
    // Implemente aqui sua solução para a questão 3 letra C.
}
//-Q3
// ----------------------------------------------------------------------------

void Caminho::ordem(int **distancias, int i, int *ordem)
{
    int cid = 0;
    for(int j = 0; j < n; j++)
        if(i != j)
            ordem[cid++] = j;
    for(cid = 0; cid < n-2; cid++)
    {
        int j = cid+1;
        int pivo = ordem[j];
        while(j > 0 && distancias[i][pivo] < distancias[i][ordem[j-1]])
        {
            ordem[j] = ordem[j-1];
            j--;
        }
        ordem[j] = pivo;
    }
}

void Caminho::imprimirCaminho()
{
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if(i == n-1)
            cout << endl;
        else
            cout << " --> ";
    }
}
