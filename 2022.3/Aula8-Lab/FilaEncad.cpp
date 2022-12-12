#include <iostream>
#include <cstdlib>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    cout << "Criando FilaEncad" << endl;
    inicio = NULL;
    fim = NULL;
}

FilaEncad::~FilaEncad()
{
    cout << "Destruindo FilaEncad" << endl;
    No* p = inicio;
    while(inicio != NULL)
    {
        inicio = p->getProx();
        delete p;
        p = inicio;
    }
    fim = NULL;
}

bool FilaEncad::vazia()
{
    if(inicio == NULL)
        return true;
    else
        return false;
}

void FilaEncad::enfileira(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim == NULL)
        inicio = p;
    else
        fim->setProx(p);
    fim = p;
}

int FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
}

int FilaEncad::desenfileira()
{
    No* p;
    if(inicio != NULL)
    {
        p = inicio;
        inicio = p->getProx();
        if(inicio == NULL)
            fim = NULL;
        int val = p->getInfo();
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::imprime()
{
    No* p = inicio;

	cout << endl;
	while (p != NULL)
	{
		cout << p->getInfo() << " ";
		p = p->getProx();
	}
	cout << endl;
}

FilaEncad* FilaEncad::reorganiza(FilaEncad *f)
{
    FilaEncad *nova = new FilaEncad();
    int qtdEnfileirada = 0;

    for (No* no = inicio; No != NULL; no = no_>getProx())
    {
        if(no->getInfo() >70 && (no->getProx()->getInfo() >70))
        {
            nova->enfileira(no->getProx()->getInfo());
        }
        f->enfileira(no->getInfo())
        qtdEnfileirada++;
    }
    
    for(int i = 0; i < qtdEnfileirada; i++)
    {
        f->desenfileira();
    }
    return nova;
}