#include <iostream>
#include "FilaEncad.h"

using namespace std;

int main()
{

    /// TESTE COM FILA

    FilaEncad f;
    for(int i=0; i<5; i++)
        f.enfileira(i);

    cout << "Fila apos inserir 5 valores" << endl;
    f.imprime();///não foi implementado

    for(int i = 20; i < 25; i++)
        f.enfileira(i);

    cout << "Fila apos inserir mais 5 valores" << endl;
    f.imprime();

    return 0;
}
