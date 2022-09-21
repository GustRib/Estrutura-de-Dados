#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    libera(raiz);
    raiz = NULL;
}
void ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        libera(p->getEsq());
        libera(p->getDir());
        delete p;
    }
}

void ArvBinBusca::imprime()
{
    cout << "Arvore:" << endl;
    auxImprime(raiz, 0);
    cout << endl;
}
void ArvBinBusca::auxImprime(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ") " << p->getInfo() << endl;
        auxImprime(p->getEsq(), nivel+1);
        auxImprime(p->getDir(), nivel+1);
    }
}

int ArvBinBusca::getRaiz()
{
    if(raiz != NULL)
        return raiz->getInfo();
    cout << "Arvore vazia" << endl;
    exit(1);
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}
bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;// árvore vazia
    else if(p->getInfo() == val)
        return true;// chave encontrada
    else if(val < p->getInfo()) // val pertence a SAE de p
        return auxBusca(p->getEsq(), val);
    else // val > p->getInfo(), val pertence a SAD de p
        return auxBusca(p->getDir(), val);
}

bool ArvBinBusca::buscaIt(int val)
{
    NoArv *p = raiz;
    while(p != NULL)
    {
        if(p->getInfo() == val)
            return true;
        if(val < p->getInfo())
            p = p->getEsq();
        else // val > p->getInfo()
            p = p->getDir();
    }
    return false;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}
NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}
NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else // val == p->getInfo()
    {
        if(p->getEsq() == NULL && p->getDir() == NULL) //folha
            p = removeFolha(p);
        else if(p->getEsq() == NULL || p->getDir() == NULL) //1 filho
            p = remove1Filho(p);
        else //2 filhos
        {
            NoArv *aux = menorSubArvDireita(p);
            p->setInfo(aux->getInfo());
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}
NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}
NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux= p->getDir(); //filho único é da direita
    else
        aux= p->getEsq();//filho único é da esquerda
    delete p;
    return aux;
}
NoArv*ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux= p->getDir(); //nó à direita de p
    while(aux->getEsq() != NULL)
        aux= aux->getEsq();
    return aux;
}

int ArvBinBusca::contaNos()
{
    return auxContaNos(raiz);
}
int ArvBinBusca::auxContaNos(NoArv *p)
{
    if(p != NULL)
        return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
    return 0;
}

int ArvBinBusca::contaNos2()
{
    int cont = 0;
    auxContaNos2(raiz, &cont);
    return cont;
}
void ArvBinBusca::auxContaNos2(NoArv *p, int *cont)
{
    if(p != NULL)
    {
        *cont = *cont + 1;
        auxContaNos2(p->getEsq(), cont);
        auxContaNos2(p->getDir(), cont);
    }
}

int ArvBinBusca::somaNos()
{
    return auxSomaNos(raiz);
}
int ArvBinBusca::auxSomaNos(NoArv *p)
{
    if(p != NULL)
        return p->getInfo() + auxSomaNos(p->getEsq()) + auxSomaNos(p->getDir());
    return 0;
}

float ArvBinBusca::mediaNos()
{
    return (float)auxSomaNos(raiz)/auxContaNos(raiz);
}

float ArvBinBusca::mediaNos2()
{
    int cont = 0, soma = 0;
    auxMediaNos2(raiz, &cont, &soma);
    return (float) soma/cont;
}
void ArvBinBusca::auxMediaNos2(NoArv *p, int *cont, int *soma)
{
    if(p != NULL)
    {
        *cont = *cont + 1;
        *soma = *soma + p->getInfo();
        auxMediaNos2(p->getEsq(), cont, soma);
        auxMediaNos2(p->getDir(), cont, soma);
    }
}

void ArvBinBusca::imprimeNivel(int k)
{
    cout << "Nivel " << k << ": ";
    auxImprimeNivel(raiz, 0, k);
    cout << endl;
}
void ArvBinBusca::auxImprimeNivel(NoArv *p, int atual, int k)
{
    if(p != NULL)
    {
        if(atual == k)
            cout << p->getInfo() << " ";
        else
        {
            auxImprimeNivel(p->getEsq(), atual+1, k);
            auxImprimeNivel(p->getDir(), atual+1, k);
        }
    }
}
