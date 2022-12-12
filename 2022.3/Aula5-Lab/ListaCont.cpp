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

void ListaCont::insereInicio(int val)
{
    if (n == 0)
    {   //lista vazia. Sera o unico no da lista
        vet[n] = val;
        n = n + 1;
    }
    else // se a lista nao for vazia precisa deslocar todos os elementos
        insereK(0, val);
}

void ListaCont::removeInicio()
{
    removeK(0);
}

void ListaCont::imprime()
{
    if (n != 0) {
        cout << "Imprimindo a Lista Contigua (" << n << " elementos)" << endl;
        for (int i = 0; i < n; i++) {
            cout << vet[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Lista vazia" << endl;
}

int ListaCont::numNos()
{
    return n;
}

int ListaCont::buscaMaior(int val)
{
    for (int i = 0; i < n; i++) {
        if (vet[i] > val)
            return i;
    }

    return -1;
}


void ListaCont::limpar()
{
    n = 0;
}

void ListaCont::insereValores(int tam, int vet[])
{
    if (tam > (max - n)) {
        cout << "ERRO: Nao ha espaco suficiente!" << endl;
        exit(1);
    }
    else {
        for (int i = 0; i < tam; i++)
            insereFinal(vet[i]);
    }
}

void ListaCont::removeMultiplos(int val)
{
    int *aux = new int[max]; //vetor auxiliar
    bool foiAlterado = false;
    int j = 0;
    int numRemocoes = 0;

    for (int i = 0; i < n; i++)
    {
        if(get(i) % val != 0)
        {
            foiAlterado = true;
            aux[j] = get(i);
            j++;
        }
    }
    if (foiAlterado)
    {
        delete[] vet;
        vet = aux;
        n = j;
    }
}