#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
private:
    NoArv *raiz; //ponteiro para o nó raiz da árvore

    void auxImprime(NoArv *p);
    void libera(NoArv *p);
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* removeFolha(NoArv *p); //caso1
    NoArv* remove1Filho(NoArv *p); //caso 2
    NoArv* menorSubArvDireita(NoArv *p); //caso 3

    void auxImprimeMenores(NoArv* p, int val);

    void auxPreencheVet(NoArv* p, int* v, int* i);

    int auxContaNos(NoArv* p);

    bool auxEhABB(NoArv* p, int *ultimo);
    int noMaisEsquerda();
public:
    ArvBinBusca();
    ~ArvBinBusca();
    int getRaiz();
    bool vazia();
    void imprime();
    bool busca(int val);
    bool buscaIt(int val);
    void insere(int val);
    void remove(int val);

    void imprimeMenores(int val){auxImprimeMenores(raiz, val);};
    int*  preencheVet(int *n);
    void contaParesImparesCaminho(int chave, int* pares, int* impares);
    bool EhABB();
    void removeFilhoEsquerdaK(int k, int val);
};

#endif // ARVBINBUSCA_H_INCLUDED
