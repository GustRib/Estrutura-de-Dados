#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
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

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
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
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
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
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
    //raiz = NULL;
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;

        // libera(p->getEsq());
        // libera(p->getDir());
        // delete p;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}

int ArvBinBusca::maior()
{
    if(raiz != NULL)
        return auxMaior(raiz);
    else
        exit(1);
}
int ArvBinBusca::auxMaior(NoArv* p)
{
	if (p->getDir() != NULL)
		return auxMaior(p->getDir()); // na ultima chamada teremos a info do ultimo no a direita e retornaremos ele.
	else
		return p->getInfo();
}

// int ArvBinBusca::maioriterativo()
// {
//     if(raiz == NULL)
//     {
//         cout << "ERRO: Arvore vazia!" << endl;
//         exit(1);
//     }
//     NoArv *p = raiz;
//     while(p->getDir() != NULL)
//     p = p->getDir();

//     return p->getInfo();
// }

int ArvBinBusca::menor()
{
    if(raiz != NULL)
        return auxMenor(raiz);
    else
        exit(3);
}

int ArvBinBusca::auxMenor(NoArv *p)
{
    if (p->getEsq() != NULL)
        return auxMenor(p->getEsq());
    else
        return p->getInfo();
}

void ArvBinBusca::removeMaior()
{
        if(!vazia())
        raiz = auxRemoveMaior(raiz);
    else    
        exit(4);
}

NoArv *ArvBinBusca::auxRemoveMaior(NoArv *p)
{
    if(p != NULL)
    {
        if (p->getDir() == NULL)
        {
            NoArv *q = p->getDir();
            delete p;
            return q;
        }
        p->setDir(auxRemoveMaior(p->getDir()));
        return p;
    }
}

void ArvBinBusca::removeMenor()
{
    if(!vazia())
        raiz = auxRemoveMenor(raiz);
    else    
        exit(5);
}

NoArv *ArvBinBusca::auxRemoveMenor(NoArv *p)
{
    if(p != NULL)
    {
        if (p->getEsq() == NULL)
        {
            NoArv *q = p->getEsq();
            delete p;
            return q;
        }
        p->setEsq(auxRemoveMenor(p->getEsq()));
        return p;
    }
}

// int ArvBinBusca::contaParesCaminho(int x)
// {

// }

// int ArvBinBusca::auxContaParesCaminho(NoArv *p, int x)
// {
    
// }

void ArvBinBusca::nosImpares02Filhos(int *nImpar, int *n2Filhos)
{
    if(!vazia())
    {
        auxNosImpares02Filhos(raiz, nImpar, n2Filhos);
        cout << "Quantos nos tem valores impares: " << *nImpar << endl;
        cout << "Quantos nos tem zero ou dois filhos: " << *n2Filhos << endl;
    }
    else
        exit(6);
}

void ArvBinBusca::auxNosImpares02Filhos(NoArv *p, int *nImpar, int *n2Filhos)
{
    if(p != NULL)   
    {
        if (p->getInfo() % 2 != 0)
            (*nImpar)++;

        if(p->getEsq() == NULL && p->getDir() == NULL || p->getEsq() != NULL && p->getDir() != NULL) 
            (*n2Filhos)++;
            
        auxNosImpares02Filhos(p->getEsq(), nImpar, n2Filhos);
        auxNosImpares02Filhos(p->getDir(), nImpar, n2Filhos);
    }
}