#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"
#include "PilhaEncad.cpp"
#include "FilaEncad.cpp"

using namespace std;

int main()
{
    /// TESTE COM PILHA
    PilhaEncad p;

    for(int i = 0; i < 5; i++) p.empilha(i);
    cout << "Pilha apos inserir 5 valores" << endl;
    p.imprime();

    for(int i = 20; i < 25; i++) p.empilha(i);
    cout << "Pilha apos inserir mais 5 valores" << endl;
    p.imprime();

    cout << "numero de elementos: " << p.tamanho() << endl;

    /// TESTE COM FILA

    FilaEncad f;
    for(int i=0; i<5; i++) f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    f.imprime();

    for(int i = 20; i < 25; i++) f.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    f.imprime();

    int *inverte(int vet[], int n)
    {
        int *novoVet = new int[n];
        PilhaEncad p;

        for(int i=0; i<n; i++)
            p.empilha(vet[i]);

        int i=0;
        while(p!vazia())
        {
            novoVet[i] = p.desempilha();
            i++;
        }
        return novoVet;
    }

    return 0;
}
