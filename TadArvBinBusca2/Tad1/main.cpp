#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    ArvBinBusca arv;
    arv.insere(15);
    arv.insere(10);
    arv.insere(8);
    arv.insere(25);
    arv.imprime();
    cout << arv.busca(18) << endl;
    return 0;
}
