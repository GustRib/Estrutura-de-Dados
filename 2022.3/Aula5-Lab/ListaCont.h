#ifndef LISTACONT_H_INCLUDED
#define LISTACONT_H_INCLUDED


class ListaCont
{
private:
    int max; // capacidade maxima de elementos
    int n; // quantidade de nos da lista
    int *vet; // vetor que armazena a lista

public:
    ListaCont(int tam); //construtor
    ~ListaCont(); // destrutor

    int get(int k); // da o valor solicitado
    void set(int k, int val); // altera o valor
    void insereFinal(int val); // insere no final
    void removeFinal(); // remove ultimo nó
    void insereK(int k, int val); // antes de xk
    void removeK(int k); // remove o nó xk
    void insereInicio(int val); // insere no inicio da lista
    void removeInicio(); // remove o primeiro nó
    void imprime();
};

#endif 