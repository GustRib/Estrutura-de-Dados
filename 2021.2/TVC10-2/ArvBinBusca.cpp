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

int ArvBinBusca::getRaiz()
{
    if(raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Arvore vazia!" << endl;
        //exit(1);
    }
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::imprime()
{
    cout << "Arvore em Pre-Ordem: ";
    auxImprime(raiz);
    cout << endl;
}

void ArvBinBusca::auxImprime(NoArv *p)
{
    if(p != NULL)
    {
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;//(sub)árvore vazia
    else if(p->getInfo() == val)
        return true;//chave encontrada
    else if(val < p->getInfo()) //SAE
        return auxBusca(p->getEsq(), val);
    else // val > p->getInfo(), SAD
        return auxBusca(p->getDir(), val);
}

bool ArvBinBusca::buscaIt(int val)
{
    NoArv *p = raiz;
    while(p != NULL)
    {
        if(p->getInfo() == val)
            return true;
        else if(val < p->getInfo())
            p = p->getEsq();
        else
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
    else // val >= p->getInfo()
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}


void ArvBinBusca::auxImprimeMenores(NoArv* p, int val)
///Exercício 2 da lista anexada (pdf)
{
    if(p != NULL)
    {


        if(p->getInfo() >= val)
            auxImprimeMenores(p->getEsq(), val);
        else
        {
            cout<<p->getInfo()<<" ";
            auxImprimeMenores(p->getEsq(), val);

            auxImprimeMenores(p->getDir(), val);
        }
    }
}
void ArvBinBusca::auxPreencheVet(NoArv *p, int* v, int* i)
///Exercício 3 da lista anexada (pdf)
///Não foram considerados todos os nós da árvore
///No exercício (ver texto anexo) pede para adicionar
///apenas os valores dos nós da árvore que então no
///intervalo [a,b]
{
    if(p != NULL)
    {
        auxPreencheVet(p->getEsq(), v, i);
        v[*i] = p->getInfo();
        (*i)++;
        auxPreencheVet(p->getDir(), v, i);
    }
}

int*  ArvBinBusca::preencheVet(int *n)
{
    int tam = auxContaNos(raiz);
    int i = 0;
    int *vetor = new int [tam];

    auxPreencheVet(raiz, vetor, &i);
    *n = i;
    return vetor;
}

int ArvBinBusca::auxContaNos(NoArv* p)
{
    if (p != NULL)
        return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
    return 0;
}


void ArvBinBusca::contaParesImparesCaminho(int chave, int* pares, int* impares)
///Exercício 4 da lista anexada (pdf)
{
    NoArv* p = raiz;
    *pares = 0;
    *impares = 0;

    while(p != NULL)
    {
        if(p->getInfo()%2==0)
            pares = pares + 1;
        else
            impares = impares + 1;

        if(chave < p->getInfo())
            p = p->getEsq();
        else if(chave > p->getInfo())
            p = p->getDir();
        else ///encontrou chave
            p = NULL;
    }
}
///Atividade do arquivo: "Atividade 10 2021.1.D.pdf"
///Apresento 2 soluções
///solução 1 - estava no gabarito
/*
void ArvBinBusca::removeFilhoEsquerdaK(int k, int val)
{
    NoArv *p = raiz;
    int nivel = 0;
    while (p!=NULL && p->getInfo() != val && nivel<k)
    {
        if ( val < p->getInfo() )
        {
            p = p->getEsq();
        }
        else
        {
            p = p->getDir();
        }
        nivel++;
    }

    if (p == NULL)
    {
        cout << "Nao alcancou nenhum no caminho para o valor val na arvore." << endl;
    }
    else if (nivel==k)
    {
        if (p->getEsq() == NULL)
        {
            cout << "No com valor val nao possui subarvore a esquerda." << endl;
        }
        else
        {
            p->setEsq( auxRemove(p->getEsq(), p->getEsq()->getInfo()) );
        }
    }
    else
    {
        cout << "Nao foi possivel alcancar o valor val ate o nivel k ou o valor esta num nivel inferior." << endl;
    }
}
*/
///solução 2
void ArvBinBusca::removeFilhoEsquerdaK(int k, int val)
{
    NoArv* p = raiz;
    int nivel = 0;

    while(p != NULL)
    {
        if(nivel < k)
        {

            if(val == p->getInfo())
            {
                ///encontrou val
                cout<<"Achou val antes do nivel "<<k;
                break;
            }
            else
            {
                nivel ++;
                if(val < p->getInfo())
                    p = p->getEsq();
                else if(val > p->getInfo())
                    p = p->getDir();
            }
        }
        else ///nivel == k
        {
            libera(p->getEsq());
            p->setEsq(NULL);
            break;
        }
    }
    if(p == NULL)
        cout<<"Nivel "<<k<<" nao atigido na busca de "<<val;

}

int ArvBinBusca::noMaisEsquerda()
{
    NoArv *p = raiz;
    while(p->getEsq() != NULL)
        p = p->getEsq();
    return p->getInfo();
}


bool ArvBinBusca::auxEhABB(NoArv* p, int *ultimo)
///Exercício 5 da lista

///faz um percurso em ordem (valores dos nós em ordem crescente)
///ultimo: ponteiro para o valor do último nó visitado (percurso em ordem)
{


    if(p==NULL)
        return true;
    else
    {

        bool abbEsq = auxEhABB(p->getEsq(), ultimo);

        if(*ultimo > p->getInfo())
            return false;///não visita em ordem crescente os valores dos nós da ABB

        else
        {
            *ultimo = p->getInfo();

            bool abbDir = auxEhABB(p->getDir(), ultimo);

            return abbEsq && abbEsq;
        }
    }
}

bool ArvBinBusca::EhABB()
{
    int ultimo = noMaisEsquerda();
    return auxEhABB(raiz, &ultimo);
}
