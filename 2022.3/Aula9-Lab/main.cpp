#include <iostream>
#include "ArvBin.h"
#include "ArvBin.cpp"
using namespace std;

// int main()
// {
//     ArvBin arv;
//     arv.montaArvore();
//     arv.insere(15);
//     arv.insere(25);
//     arv.insere(10);
//     arv.preOrdem();
//     return 0;
// }


int main()
{
    // ArvBin* vazia = new ArvBin();
    // ArvBin* a1 = new ArvBin(), * a2 = new ArvBin(), * a3 = new ArvBin();

    // a1->cria(16, vazia, vazia);
    // a2->cria(19, vazia, vazia);
    // a1->cria(18, a1, a2);

    // a2->cria(38, vazia, vazia);
    // a3->cria(14, vazia, vazia);
    // a2->cria(25, a2, a3);

    // a1->cria(10, a1, a2);

    // a1->imprime();

    // cout << endl << "O valor informado esta na arvore?" << a1->busca(20) << endl;

    // cout << endl << "Numero nos: " << a1->contaNos() << endl;

    // cout << endl << "Numero folhas: " << a1->contaNosFolhas() << endl;

    // cout << endl << "altura: " << a1->altura() << endl;

    // delete a1;
    // delete vazia;

    //Q1

    ArvBin arv, vazia, a1, a2, a3;
    a1.cria(-35, &vazia, &vazia);
    a2.cria(-19, &vazia, &vazia);
    a3.cria(-20, &a1, &a2);
    a1.cria(-5, &vazia, &vazia);
    a2.cria(10, &a1, &vazia);
    a1.cria(-15, &a3, &a2);
    a2.cria(45, &vazia, &vazia);
    a3.cria(60, &vazia, &vazia);
    a2.cria(50, &a2, &a3);
    a3.cria(80, &vazia, &vazia);
    a2.cria(75, &a2, &a3);
    arv.cria(40, &a1, &a2);
    arv.imprime();
    cout << "Total de nos: " << arv.contaNos() << endl;
	cout << "Total de folhas: " << arv.contaNosFolhas() << endl;
    cout << "Altura da arvore: " << arv.altura() << endl;
    cout << "Total de nos impares: " << arv.contaImpar() << endl;
    a1.anulaRaiz();
    a2.anulaRaiz();
    a3.anulaRaiz();
    return 0;
}