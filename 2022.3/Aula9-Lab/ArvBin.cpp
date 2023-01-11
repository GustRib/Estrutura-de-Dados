#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"
#include <math.h>

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "�rvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    int nivel = 0;
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore(nivel);
    }
}

NoArv* ArvBin::auxMontaArvore(int nivel)
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();

        p->setInfo(valor);

        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore(nivel + 1));
        cout << "Volta no noh " << p->getInfo() << endl;

        cout << "Direita" << endl;
        p->setDir(auxMontaArvore(nivel + 1));
        cout << "Volta no noh " << p->getInfo() << endl;

        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

void ArvBin::imprime()
{
    auxImprime(raiz);
}

void ArvBin::auxImprime(NoArv *p)
{
    if(p != NULL)
    {
        auxImprime(p->getEsq());
        cout << p->getInfo() << endl;
        auxImprime(p->getDir());
    }
}

int *ArvBin::criaVetNegativos(int k, int *n)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    int val = 0;
    *n = pow(2, k);
    int *vet = new int[*n];

    for (int i = 0; i < *n; i++)
    {
        vet[i] = -1;
    }

    auxCriaVetNegativos(raiz, k, n, vet, &val);
    
    if (val == 0)
    {
        cout << "A arvore nao tem valores negativos nesse nivel" << endl;
    }

    return n;
}

void ArvBin::auxCriaVetNegativos(NoArv *p, int k, int *n, int *vet, int *elem)
{
    if (k== 0 && p != NULL)
    {
        if(p->getInfo() < 0)
        {
            vet[*elem] = p->getInfo();
            *elem = *elem + 1;
        }
        else
            return;
    }
    else if (p != NULL)
    {
        auxCriaVetNegativos(p->getEsq(), k - 1, n, vet, elem);
        auxCriaVetNegativos(p->getDir(), k - 1, n, vet, elem);
    }
}

int ArvBin::contaNos()
{
    if(!vazia())
        return auxContaNos(raiz);
    else
        exit(1);
}

int ArvBin::auxContaNos(NoArv *p)
{
    if(p == NULL)
        return 0;
    else
        return 1 + auxContaNos(p->getDir()) + auxContaNos(p->getEsq());
}

int ArvBin::contaNosFolhas()
{
	return auxContaNosFolhas(raiz);
}

int ArvBin::auxContaNosFolhas(NoArv* p)
{
	if (p == NULL)
		return 0;

	int total = auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
	if (p->getEsq() == NULL && p->getDir() == NULL)
		total++;
	return total;
}