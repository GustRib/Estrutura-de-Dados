#include <iostream>
#include "ListaCircular.h"

using namespace std;

ListaCircular::ListaCircular()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

NoDuplo* ListaCircular::insereNoAntes(NoDuplo *p, int val)
{
        If(primeiro == NULL) // lista vazia
        {
            NoDuplo *novo = new NoDuplo();
            novo->setProx(novo);
            novo->setAnt(novo);
            primeiro = ultimo = novo;
            n++;
            return novo;
        }

        else 
        {
            NoDuplo *q = p->getAnt();
            NoDuplo *novo = new NoDuplo();
            novo->setInfo(val);
            novo->setProx(ant);
            novo->setAnt(p);
            ant->setProx(novo);
            p->setAnt(novo);
            if(p == primeiro)
                primeiro = novo;
            n++;
            return novo;
        }
    else 
        return NULL;
}


void ListaCircular::insereFinal(int val)
{
    primeiro = insereNoAntes(primeiro, val);
}

void ListaCircular::imprime()
{
    cout << "Lista: ";
    int i=0;
    NoDuplo *p = primeiro;
    while(i<n)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
        i++;
    }
    cout << endl;
}
