#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);
    int maior();
    int menor();
    void removeMaior();
    void removeMenor();
    int contaParesCaminho(int x);
    void nosImpares02Filhos(int *nImpar, int *n2Filhos);


private:
    NoArv* raiz; // ponteiro para o No raiz da �rvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* removeFolha(NoArv *p);
    NoArv* remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* libera(NoArv *p);
    int auxMaior(NoArv *p);
    int auxMenor(NoArv *p);
    NoArv* auxRemoveMaior(NoArv *p);
    NoArv* auxRemoveMenor(NoArv *p);
    int auxContaParesCaminho(NoArv *p, int x);
    void auxNosImpares02Filhos(NoArv *p, int *nImpar, int *n2Filhos);


};

#endif // ARVBINBUSCA_H_INCLUDED
