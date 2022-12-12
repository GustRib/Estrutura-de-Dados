#include <iostream>
#include "ListaDupla.h"
#include "ListaDupla.cpp"

using namespace std;

int main()
{
    // ListaDupla l1; /// cria lista vazia
    // int NumNos = 5;
    // ListaDupla l2;

    // l1.insereFinal(55);
    // l1.insereFinal(54);
    // l1.insereFinal(53);
    // l1.insereFinal(52);
    // l1.insereFinal(51);

    // l2.insereFinal(56);
    // l2.insereFinal(57);
    // l2.insereFinal(58);
    // l2.insereFinal(59);
    // l2.insereInicio(60);

    // bool existe = l1.busca(20);
    // cout << "O valor 20 esta na lista? ";
    // if(existe)
    //     cout << "Sim" << endl;
    // else
    //     cout << "Nao" << endl;

    // return 0;

    listaDupla l;
    int numNos = 10;

    l.insereFinal(55);
    l.insereFinal(55);
    l.insereFinal(55);
    l.insereFinal(55);
    l.insereFinal(55);
    l.insereFinal(55);

    NoDuplo *p = l.getNo(3);
    NoDuplo *q = l.getNo(5);

    l.removeOcorrencias(24);
    l.imprime();
    

}

