#include <iostream>
#include <cstdlib>
#include "MatrizDistancias.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q4
MatrizDistancias::MatrizDistancias(int ordem)
{
    // Implemente aqui sua solução para a questão 4 letra A.
    // Se necessário, remova o código abaixo.
    n = 0;
}

MatrizDistancias::~MatrizDistancias()
{
    // Implemente aqui sua solução para a questão 4 letra A.
}

int MatrizDistancias::detInd(int i, int j)
{
    // Implemente aqui sua solução para a questão 4 letra B.
    // Se necessário, remova o código abaixo.
    return 0;
}

int MatrizDistancias::get(int i, int j)
{
  // Implemente aqui sua solução para a questão 4 letra C.
  // Se necessário, remova o código abaixo.
    return 0;
}

void MatrizDistancias::set(int i, int j, int val)
{
  // Implemente aqui sua solução para a questão 4 letra C.
}
//-Q4
// ----------------------------------------------------------------------------

void MatrizDistancias::imprime()
{
    cout << "Matriz " << n << " x " << n << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << get(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
}
