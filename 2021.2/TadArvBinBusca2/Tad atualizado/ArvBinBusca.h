#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
private:
    NoArv *raiz;
    void libera(NoArv *p);
    void auxImprime(NoArv *p, int nivel);
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val); //remove nó
    NoArv* removeFolha(NoArv *p); //caso 1
    NoArv* remove1Filho(NoArv *p); //caso 2
    NoArv* menorSubArvDireita(NoArv *p); //caso 3
    int auxContaNos(NoArv *p);
    void auxContaNos2(NoArv *p, int *cont);
    int auxSomaNos(NoArv *p);
    void auxMediaNos2(NoArv *p, int *cont, int *soma);
    void auxImprimeNivel(NoArv *p, int atual, int k);

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
    int contaNos();
    int contaNos2();
    int somaNos();
    float mediaNos();
    float mediaNos2();
    void imprimeNivel(int k);
};

#endif // ARVBINBUSCA_H_INCLUDED
