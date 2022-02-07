#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    ArvBinBusca arv;
    arv.insere(15);
    arv.insere(10);
    arv.insere(20);
    arv.insere(6);
    arv.insere(12);
    arv.insere(17);
    arv.insere(25);
    arv.insere(-3);
    arv.insere(8);
    arv.insere(30);
    arv.insere(40);
    arv.imprime();
    cout << "Conta:  " << arv.contaNos() << endl;
    cout << "Conta2: " << arv.contaNos2() << endl;
    cout << "Soma:   " << arv.somaNos() << endl;
    cout << "Media:  " << (float)arv.somaNos()/arv.contaNos() << endl;
    cout << "Media:  " << arv.mediaNos() << endl;
    cout << "Media2: " << arv.mediaNos2() << endl;

    arv.imprimeNivel(2);

    /*
    arv.remove(8);
    arv.imprime();
    arv.remove(25);
    arv.imprime();
    arv.remove(20);
    arv.imprime();
    arv.remove(15);
    arv.imprime();
    */

    /*
    cout << arv.busca(18) << endl;
    cout << arv.buscaIt(18) << endl;
    cout << arv.busca(25) << endl;
    cout << arv.buscaIt(25) << endl;
    */
    return 0;
}
