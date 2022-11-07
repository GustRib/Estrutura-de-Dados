#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    cout << "Criando objeto ListaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad()
{
    cout << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaEncad::busca(int val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaEncad::get(int k)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
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

void ListaEncad::set(int k, int val)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}


void ListaEncad::insereInicio(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;

    n++;
    if(n == 1) ultimo = p;
}

void ListaEncad::insereFinal(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);

    if(ultimo != NULL) ultimo->setProx(p);
    ultimo = p;

    n++;
    if(n == 1) primeiro = p;
}

void ListaEncad::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if(n == 0) ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::imprime()
{
	No* p = primeiro;
	while (p != NULL)
	{
		cout << p->getInfo() << "    ";
		p = p->getProx();
	}
	cout << endl << endl << endl;
}

int ListaEncad::numNos()
{
    return n;
}

int ListaEncad::buscaMaior(int val)
{
	int k = 0;
	for (No* i = primeiro; i != NULL; i = i->getProx())
	{
		if (i->getInfo() > val)
		{
			return k;
		}
		k++;
	}
    return -1;
	//cout << "Nao ha elemento na lista que seja maior!" << endl;
}

void ListaEncad::limpar()
{
    No* p = primeiro;

	while (p != NULL)
	{
		primeiro = primeiro->getProx();
		delete p;
		p = primeiro;
	}
	primeiro = NULL;
	ultimo = NULL;
	n = 0;
}

float ListaEncad::calculaMedia()
{
        int soma = 0;
	for (No* i = primeiro; i != NULL; i = i->getProx())
	{
		soma += i->getInfo();
	}
	return soma / (float)n;
}

void ListaEncad::concatena(ListaEncad *l2)
{
    for (No* p = l2->primeiro; p != NULL; p = p->getProx())
		insereFinal(p->getInfo());
}

ListaEncad* ListaEncad::partir(int x)
{
    ListaEncad* newList = new ListaEncad();
	No* ant = NULL;
	No* p = primeiro;
	int i = -1;

	// percorre lista intriseca ate o indice x
	while (p != NULL && i < x) {
		ant = p;
		p = p->getProx();
		i = i + 1;
	}

	if (p != NULL)
	{
		// Nova lista
		newList->primeiro = p;
		newList->ultimo = ultimo;
		newList->n = n - i;

		if (i == 0)
			primeiro = NULL;
		else
			ant->setProx(NULL);

		// Lista intriseca
		ultimo = ant;
		n = n - newList->n;
	}
	return newList;
}

