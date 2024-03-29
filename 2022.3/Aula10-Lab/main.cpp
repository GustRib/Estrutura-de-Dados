#include <iostream>
#include "ArvBinBusca.h"
#include "ArvBinBusca.cpp"

using namespace std;

int main()
{
    ArvBinBusca arv;

    cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(15);
    arv.insere(9);
    arv.insere(20);
    arv.insere(7);
    arv.insere(11);
    arv.insere(18);
    arv.insere(24);
    arv.insere(6);
    arv.insere(8);
    arv.insere(10);
    arv.insere(12);
    arv.insere(17);
    arv.insere(19);
    arv.imprime();
    cout << endl;

    cout << "Media do caminho ate o no com valor 18: " << arv.mediaCaminho(18) << endl;

    cout << "Busca o valor 20: " << arv.busca(20) << endl;
    cout << "Busca o valor  5: " << arv.busca(5) << endl;
    cout << endl;

    cout << "Removendo os valores 24, 6, 7, 12, 18, 5." << endl;
    arv.remove(24);
    arv.remove(6);
    arv.remove(7);
    arv.remove(12);
    arv.remove(5);
    arv.remove(9);
    arv.remove(10);
    cout << endl;

    cout << "Arvore Binaria de Busca final:" << endl;
    arv.imprime();


//EX 1
    cout << "Maior valor da Arvore: " << arv.maior() << endl;
//EX 2
    cout << "Menor valor da Arvore: " << arv.menor() << endl;
//EX 3
    // arv.removeMaior();
    arv.imprime();
    cout << endl;
//EX 4
    // arv.removeMenor();
    arv.imprime();
    cout << endl;
//EX 5
    int nImpar = 0;
    int n2Filhos = 0;
    arv.nosImpares02Filhos(&nImpar, &n2Filhos);
    arv.imprime();


    return 0;
}

