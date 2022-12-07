#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
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

void ListaDupla::insereFinal(int val) {
    NoDuplo* p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);

    if (n == 0) primeiro = p;
    else ultimo->setProx(p);

    ultimo = p;
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

void ListaDupla::removeFinal()
{
    if (primeiro != NULL)
    {
        NoDuplo* p = ultimo;
        ultimo = p->getAnt();
        delete p;
        if (ultimo == NULL)
            primeiro = NULL;
        else
            ultimo->setProx(NULL);
        n--;
    }
    else
        cout << "ERRO: Lista vazia." << endl;
}

void ListaDupla::removeK(int k)
{
    if (k < 0 || k >= n)
        cout << "Indice invalido" << endl;
    else if (k == 0)
        removeInicio();
    else if (k == n - 1)
        removeFinal();
    else
    {
        NoDuplo* p = primeiro;
        for (int i = 0; i < k; i++)
            p = p->getProx();
        NoDuplo* ant = p->getAnt();
        NoDuplo* prox = p->getProx();
        ant->setProx(prox);
        prox->setAnt(ant);
        delete p;
        n--;
    }
}
void ListaDupla::imprime() {
    cout << "Imprimindo a lista a partir do inicio: " << endl;
    NoDuplo* p = primeiro;
    if (p != NULL) {
        while (p != NULL) {
            cout << p->getInfo() << " -> ";
            p = p->getProx();
        }
        cout << endl;
    }
    else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::imprimeReverso() {
    cout << "Imprimindo a lista a partir do final: " << endl;
    NoDuplo* p = ultimo;
    if (p != NULL) {
        while (p != NULL) {
            cout << p->getInfo() << " <- ";
            p = p->getAnt();
        }
        cout << endl;
    }
    else
        cout << "ERRO: lista vazia" << endl;
}

ListaDupla* ListaDupla::concatena(ListaDupla* l2) {
    ListaDupla* listaNova = new ListaDupla();
    // insere elementos da primeira lista
    NoDuplo* p = primeiro;
    while (p != NULL) {
        listaNova->insereFinal(p->getInfo());
        p = p->getProx();
    }
    // insere elementos da segunda lista
    p = l2->primeiro;
    while (p != NULL) {
        listaNova->insereFinal(p->getInfo());
        p = p->getProx();
    }

    return listaNova;
}

ListaDupla* ListaDupla::partir(int x) {
    ListaDupla* listaNova = new ListaDupla();
    NoDuplo* p = ultimo;
    while ((p != NULL) && (p->getInfo() != x)) {
        listaNova->insereInicio(p->getInfo());
        p = p->getAnt();
        this->removeFinal();
    }
    return listaNova;
}

void ListaDupla::removeOcorrencias(int val) {
    NoDuplo* p = primeiro;
    while (p != NULL) {
        if (p->getInfo() == val) {
            // se for o primeiro no
            if (p->getAnt() == NULL)
                this->removeInicio();
            // se for o ultimo no
            else if (p->getProx() == NULL)
                this->removeFinal();
            // se for intermediario
            else {
                NoDuplo* aux = p->getAnt();
                aux->setProx(p->getProx());
                aux = p->getProx();
                aux->setAnt(p->getAnt());

                n = n - 1;
                p = p->getAnt();
            }

        }
        p = p->getProx();
    }
}
