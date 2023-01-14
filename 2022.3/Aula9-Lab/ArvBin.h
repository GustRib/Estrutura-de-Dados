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
    int noMaisEsquerda();
    int noMaisDireita();
    void contaElegante();
    void contagens(int k);
    void contagens2(int val, int k);
    int difMaxMinFolha();

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
    int auxNoMaisEsquerda(NoArv *p);
    int auxNoMaisDireita(NoArv *p);
    void auxContaElegante(NoArv *p, int *mult3, int *folhaneg);
    void auxContagens(NoArv *p,int atual, int k, int *cont1, int *cont2);
    void auxContagens2(NoArv *p,int val, int atual, int k, int *cont1, int *cont2);
    int auxDifMaxMinFolha(NoArv *p, int *min, int *max);
    
};

#endif // ARVBIN_H_INCLUDED
