#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaDupla::imprime()
{
    NoDuplo *p;
    cout<<endl;
    for(p = primeiro; p != NULL; p = p->getProx())
        cout<<p->getInfo()<<"  ";
    cout<<endl;
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) ultimo = p;
	else primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	ultimo = NULL;
		else primeiro->setAnt(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo();

    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);

    if(n != 0)
        ultimo->setProx(p);
    else
        primeiro = p;

    ultimo = p;
    n = n + 1;
}

void ListaDupla::removeFinal()
{
    if(primeiro != NULL)
    {
        NoDuplo *p = ultimo;

        ultimo = ultimo->getAnt();

        if(primeiro == ultimo) //lista com 1 unico n�
            primeiro = NULL;
        else //lista com mais de um n�
            ultimo->setProx(NULL);
        delete p;
        n = n - 1;
    }
}
    void ListaDupla::removeEntreInter(int v1, int v2)
{   
    if(primeiro != NULL) 
    {
        if(v2 < v1) 
        {
            int aux = v1;
            v1 = v2;
            v2 = aux;
        }
        for(NoDuplo *p = primeiro; p!=NULL; p = p->getProx()){
            if(p->getInfo() >= v1 && p->getInfo() <= v2)
            {
                NoDuplo *ant = p->getAnt();
                NoDuplo *prox = p->getProx();
                ant->setProx(prox);
                prox->setAnt(ant);
                delete p;
                tam--;
            }
        }
    }
    else
        cout << "Lista vazia." << endl;
}


void ListaDupla::removeV(int v1, int v2)
{   
    if(primeiro != NULL) 
    {
        if(v2 < v1) 
        {
            int a = v1;
            v1 = v2;
            v2 = aux;
        }
        for(No *p = primeiro; p!=NULL; p = p->getProx()){
            if(p->getAtual() >= v1 && p->getAtual() <= v2)
            {
                No *ant = p->getAnte();
                No *prox = p->getProx();
                ante->setProx(prox);
                prox->setAnte(ante);
                delete p;
                n--;
            }
        }
    }
    }
    else {
        cout << "Lista vazia" << endl;
    };
        

