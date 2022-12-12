#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"
#include "PilhaEncad.cpp"
#include "FilaEncad.cpp"

using namespace std;

FilaEncad* intercala(FilaEncad *f1, FilaEncad *f2)
{
    FilaEncad *f3 = new FilaEncad();

    while ((!f1->vazia()) || (!f2->vazia()))
    {
        if ((f1->vazia()) && (!f2->vazia()))
        {
            f3->enfileira(f2->desenfileira());
            continue;
        }
        if(!f1->vazia() && (f2->vazia()))
        {
            f3->enfileira(f1->desenfileira());
            continue;
        }

        f3->enfileira(f1->desenfileira());
        f3->enfileira(f2->desenfileira());
    }
    
    return f3;
}

int main()
{
    /// TESTE COM PILHA
    // PilhaEncad p;

    // for(int i = 0; i < 5; i++) p.empilha(i);
    // cout << "Pilha apos inserir 5 valores" << endl;
    // //p.imprime();

    // for(int i = 20; i < 25; i++) p.empilha(i);
    // cout << "Pilha apos inserir mais 5 valores" << endl;
    // //p.imprime();

    // cout << "numero de elementos: " << p.tamanho() << endl;

    // /// TESTE COM FILA

    FilaEncad f;
    for(int i=0; i<5; i++) f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    f.imprime();

    FilaEncad f2;
    for(int i = 20; i < 25; i++) f2.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    f2.imprime();

    FilaEncad *f3 = NULL;

    f3 = intercala(&f, &f2);

    f3->imprime();

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

    FilaEncad fila;
    ....
    fila.enfileira(15);
    fila.enfileira(85);
    fila.enfileira(71);
    fila.enfileira(75);
    fila.enfileira(62);
    fila.enfileira(70);
    fila.enfileira(15);
    fila.enfileira(15);


    return 0;
}
