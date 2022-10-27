#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    max = tam;
    n = 0;
    vet = new int[tam];
}

ListaCont::~ListaCont()
{
    delete [] vet;
}

int ListaCont::get (int k)
{
    if(k >= 0 && k < n)
        return vet[k];
    else 
    {
        cout << "Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::set (int k, int val)
{
    if(k >= 0 && k < n)
        vet[k] = val;
    else
    {
        cout << "Indice invalido!" << endl;
        exit(2);
    }
}

void ListaCont::insereFinal (int val)
{
    if(n == max)
    {
        cout << "Vetor cheio!" << endl;
        exit(3);
    }

    vet[n] = val;
    n = n + 1;
}

void ListaCont::removeFinal ()
{
    if(n == 0)
    {
        cout << "Lista Vazia!" << endl;
        exit(6);
    }
    n = n - 1;
}

void ListaCont::insereK(int k, int val)
{
    if(n == max)
    {
        cout << "Vetor Cheio!" << endl;
        exit(3);
    }
    if(k >= 0 && k < n)
    {
        for(int i = n-1; i >= k; i--)
            vet[i+1] = vet[i];
        vet[k] = val;
        n = n + 1;
    }
    else
    {
        cout << "Indice invalido!" << endl;
        exit(4);
    }
}

void ListaCont::removeK(int k)
{
    if(k >= 0 && k < n)
    {
        // copia da direita para esquerda 
        for(int i = k; i < n-1; i++)
            vet[i] = vet[i+1];
        n = n - 1;
    }
    else 
    {
        cout << "Indice invalido!" << endl;
        exit(5);
    }
}