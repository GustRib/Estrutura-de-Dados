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
    ArvBin* vazia = new ArvBin();
    ArvBin* a1 = new ArvBin(), * a2 = new ArvBin(), * a3 = new ArvBin();

    a1->cria(16, vazia, vazia);
    a2->cria(19, vazia, vazia);
    a1->cria(18, a1, a2);

    a2->cria(38, vazia, vazia);
    a3->cria(14, vazia, vazia);
    a2->cria(25, a2, a3);

    a1->cria(10, a1, a2);

    a1->imprime();

    cout << endl << a1->busca(19) << endl;

    // cout << endl << "Numero nos: " << a1->numNos() << endl;

    // cout << endl << "Numero folhas: " << a1->nFolhas() << endl;

    // cout << endl << "altura: " << a1->altura() << endl;

    delete a1;
    delete vazia;
    return 0;
}