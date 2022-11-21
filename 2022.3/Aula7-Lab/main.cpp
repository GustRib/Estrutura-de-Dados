#include <iostream>
#include "ListaDupla.h"
#include "ListaDupla.cpp"

using namespace std;

int main()
{
    ListaDupla l1; /// cria lista vazia
    int NumNos = 5;
    ListaDupla l2;

    l1.insereFinal(55);
    l1.insereFinal(54);
    l1.insereFinal(53);
    l1.insereFinal(52);
    l1.insereFinal(51);

    l2.insereFinal(56);
    l2.insereFinal(57);
    l2.insereFinal(58);
    l2.insereFinal(59);
    l2.insereFinal(60);

    bool existe = l1.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    return 0;
}

