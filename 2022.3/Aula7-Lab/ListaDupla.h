#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    int get(int k);
    void set(int k, int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val); /// exercicio
    void removeFinal();        /// exercicio
    void insereK(int k, int val);
    void removeK(int k);
    void imprime();
    void imprimeReverso();
    ListaDupla* concatena(ListaDupla* l2);
    ListaDupla* partir(int x);
    void removeOcorrencias(int val);
    void removeEntre(NoDuplo *p, NoDuplo *q);
    NoDuplo *getNo(int k);

private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int n;
};
#endif
