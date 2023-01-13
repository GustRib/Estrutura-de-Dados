#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    void imprime();
    int* criaVetNegativos(int k, int *n);
    int contaNos();
    int contaNosFolhas();
    int altura();
    int contaImpar();
    int contaFolhaImpar();
    void imprimeNivel(int k);
    float mediaNivel(int k);
    int min();
    int max();
    void inverte();

  private:
    NoArv *raiz; // ponteiro para o No raiz da �rvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore(int nivel);
    void auxImpNivel(NoArv *p, int atual, int k);
    NoArv* auxInsere(NoArv *p, int x);
    void auxImprime(NoArv *p);
    void auxCriaVetNegativos(NoArv *p, int k, int *n, int *vet, int *elem);
    int auxContaNos(NoArv *p);
    bool EhFolha(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxContaFolhaImpar(NoArv *p);
    void auxImprimeNivel(NoArv *p, int k, int atual);
    void auxMediaNivel(NoArv *p, int k, int *soma, int *cont);
    void auxMin(NoArv *p, int *menor);
    void auxMax(NoArv *p, int *maior);
    void auxInverte(NoArv * p);
    
};

#endif // ARVBIN_H_INCLUDED
