#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"

using namespace std;

// construtor
PilhaEncad::PilhaEncad()
{
    cout << "Criando PilhaEncad" << endl;
    topo = NULL;
}

// destrutor
PilhaEncad::~PilhaEncad()
{
    cout << "Destruindo PilhaEncad" << endl;
    No* p = topo;
    while(topo != NULL)
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

void PilhaEncad::empilha(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
}

int PilhaEncad::desempilha()
{
    No* p;
    if(topo != NULL)
    {
        p = topo;
        topo = p->getProx();
        int val = p->getInfo();
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Pilha vazia!" << endl;
        exit(1);
    }
}

int PilhaEncad::getTopo()
{
    if(topo != NULL)
        return topo->getInfo();
    else
    {
        cout << "Pilha vazia!" << endl;
        exit(1);
    }
}

bool PilhaEncad::vazia()
{
    if(topo == NULL)
        return(true);
    else
        return(false);
}
