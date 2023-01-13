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
    if (p == NULL) // a esta arvore vazia
        return false;
    else if (p->getInfo() == x) // o valor X está na arvore
        return true;
    else if (auxBusca(p->getEsq(), x)) // buscando o calor pela esquerda
        return true;
    else
        return auxBusca(p->getDir(), x); // se ele nao estiver na esquerda ele obrigatoriamente esta na direita
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
        //Percurso em Pré ordem:
        cout << p->getInfo() << " " << endl;
        auxImprime(p->getEsq());
        auxImprime(p->getDir());

        //Percurso em ordem:
        // auxImprime(p->getEsq());
        // cout << p->getInfo() << " " << endl;
        // auxImprime(p->getDir());
        
        //Percuso em Pós Ordem:
        // auxImprime(p->getEsq());
        // auxImprime(p->getDir());
        // cout << p->getInfo() << " " << endl; 
        
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
        exit(2);
}

int ArvBin::auxContaNos(NoArv *p)
{
    if(p == NULL)
        return 0;
    else
        return 1 + auxContaNos(p->getDir()) + auxContaNos(p->getEsq());
}

bool ArvBin::EhFolha(NoArv *p)
{
    return p->getEsq()==NULL && p->getDir()==NULL;
}

int ArvBin::contaNosFolhas()
{
    if(!vazia())
        return auxContaNosFolhas(raiz);
    else
        exit(3);
}

int ArvBin::auxContaNosFolhas(NoArv* p)
{
    if (p == NULL)
        return 0;
    
    if(p->getEsq() == NULL && p->getDir() == NULL)
        return auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir()) + 1;
    else
        return auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());

    //Criando uma variavel pra armazenar o resultado:
	// if (p == NULL)
	// 	return 0;

	// int total = auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
	// if (p->getEsq() == NULL && p->getDir() == NULL)
	// 	total++;
	// return total;

    //utilizando a funcao EhFolha:
    // if(p == NULL)
    //     return 0;
    // else if(EhFolha(p))
    //     return 1;
    // else
    //     return auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
}

int ArvBin::altura()
{
    if(!vazia())
        return auxAltura(raiz);
    else
        exit(4);
}

int ArvBin::auxAltura(NoArv *p)
{
    if (p == NULL)
        return -1;
    else
    {
        int he = auxAltura(p->getEsq());
        int hd = auxAltura(p->getDir());
        return ( he>hd ? he : hd) + 1;
    }
}

int ArvBin::contaImpar()
{
    if(!vazia())
        return auxContaImpar(raiz);
    else
        exit(5);
}

int ArvBin::auxContaImpar(NoArv *p)
{
    if(p == NULL)   
        return 0;

    int impares = auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
	if (p->getInfo() % 2 != 0)
		impares++;
	return impares;
}

int ArvBin::contaFolhaImpar()
{
    if(!vazia())
        return auxContaFolhaImpar(raiz);
    exit(6);
}

int ArvBin::auxContaFolhaImpar(NoArv *p)
{
    if(p == NULL)
        return 0;

    int folhaImpar = auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
        if (p->getInfo() % 2 != 0 && p->getEsq() == NULL && p->getDir() == NULL)
            folhaImpar++;
        return folhaImpar;
}

void ArvBin::imprimeNivel(int k)
{
    if(!vazia())
        auxImprimeNivel(raiz, k , 0);
    else
        exit(7);
}

void ArvBin::auxImprimeNivel(NoArv *p, int k, int atual)
{
    if(p != NULL && atual <= k)
    {
        if(k == atual)
            cout << p->getInfo() << " ";

        auxImprimeNivel(p->getEsq(), k, atual+1);
        auxImprimeNivel(p->getDir(), k, atual+1);
    }
}

float ArvBin::mediaNivel(int k)
{
    int soma = 0, cont = 0;
        auxMediaNivel(raiz, k, &soma, &cont);
    if(cont > 0)
        return (soma) / (float)cont;
    else
        return 0;
}

void ArvBin::auxMediaNivel(NoArv *p, int k, int *soma, int *cont)
{
    if(p != NULL &&  k >= 0)
    {
        if(k == 0)
        {
            *soma = *soma + p->getInfo();
            (*cont)++;
        }

        auxMediaNivel(p->getEsq(), k-1, soma, cont);
        auxMediaNivel(p->getDir(), k-1, soma, cont);
    }
}

int ArvBin::min()
{
    if(!vazia())
    {
        int menor = raiz->getInfo();
        auxMin(raiz, &menor);
        return menor;
    }
    else
    {
        exit(8);
    }
}

void ArvBin::auxMin(NoArv *p, int *menor)
{
    if(p != NULL)
    {
        if(p->getInfo() < *menor)
            *menor = p->getInfo();
        
        auxMin(p->getEsq(), menor);
        auxMin(p->getDir(), menor);
    }
}

int ArvBin::max()
{
    if(!vazia())
    {
        int maior = raiz->getInfo();
        auxMax(raiz, &maior);
        return maior;
    }
    else
        exit(8);
}

void ArvBin::auxMax(NoArv *p, int *maior)
{
    if(p != NULL)
    {
        if(p->getInfo() > *maior)
            *maior = p->getInfo();
        
        auxMax(p->getEsq(), maior);
        auxMax(p->getDir(), maior);
    }
}

void ArvBin::inverte()
{
    if(!vazia())
        auxInverte(raiz);
    else
        exit(9);
}

void ArvBin::auxInverte(NoArv *p)
{
    if(p != NULL)
    {
        auxInverte(p->getEsq());
        auxInverte(p->getDir());

        NoArv *q = p->getEsq();
        p->setEsq(p->getDir());
        p->setDir(q);
    }
}
