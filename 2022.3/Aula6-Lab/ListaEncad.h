#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"

class ListaEncad
{
public:
    ListaEncad();                   /// construtor
    ~ListaEncad();                  /// destrutor

    int get(int k);                 /// retorna o valor do k
    void set(int k, int val);       /// altera o valor do k

    void insereInicio(int val);     /// insere um novo No contendo val no inicio da lista
    void insereFinal(int val);      /// insere um novo No contendo val no final da lista
    void removeInicio();            /// remove o primeiro No da lista
    void removeFinal();             /// remove o ultimo No da lista

    bool busca(int val);            /// retorna true caso val esteja na lista e false caso contrario
    void imprime();                 /// imprime todo o conteudo da lista 
    int numNos(){return n;}         /// retorna o numero de nós da lista
    int buscaMaior(int val);        /// verifica se existe um numero maior que o fornecido 
    void limpar();                  /// remove todos os elemento da lista
    float calculaMedia();           /// calcula a media dos valores fornecidos
    void concatena(ListaEncad *l2); /// Juntar a lista L2 ao final da lista L1
    ListaEncad* partir(int x);      /// Parte a lista interna em duas partes, de maneira que o nó de indice x se torne o primeiro nó da nova lista

private:
    No *primeiro;  /// ponteiro para o primeiro No da lista
    No *ultimo;    /// ponteiro para o ultimo No da lista
    int n;         /// numero de nos na lista
};
#endif
