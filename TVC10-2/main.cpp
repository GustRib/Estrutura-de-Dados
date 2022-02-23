#include <iostream>
#include "ArvBinBusca.h"

using namespace std;


int main()
{
    ArvBinBusca arv;

    arv.insere(15);
    arv.insere(10);
    arv.insere(6);
    arv.insere(8);
    arv.insere(3);
    arv.insere(20);
    arv.insere(17);
    arv.insere(25);
    arv.insere(30);
    ///arv.imprime();

    ///arv.imprimeMenores(15);
/*
    int n;
    int* v = arv.preencheVet(&n);

    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";

    delete [] v;
*/
    cout<<endl<<endl<<arv.EhABB();

    return 0;
}
