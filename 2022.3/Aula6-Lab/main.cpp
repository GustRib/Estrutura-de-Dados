#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"
#include "ListaEncad.cpp"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1) ; /// retorna um numero inteiro aleatorio entre a e b
}

int main()
{
    // ListaEncad L1; /// cria lista vazia
    // int NumNos = 20;

    // srand(time(NULL));
    // /// ATENCAO: os valores inseridos na lista sao gerados
    // /// aleatoriamente e mudam em cada execucao do programa!!!
    // cout << "Inserindo valores: ";
    // for(int i = 1; i <= NumNos; i++)
    // {
    //     int val =  numAleatorio(0, 50); /// cria um valor aleatorio entre 0 e 50
    //     cout << val << ", ";
    //     L1.insereInicio(val);
    // }
    // cout << endl;

    // bool existe = L1.busca(13);
    // cout << "O valor 13 esta na lista? " << endl;
    // if(existe)
    //     cout << "Sim" << endl;
    // else
    //     cout << "Nao" << endl;

    // return 0;
    

    ListaEncad L1;
    ListaEncad l2;


    L1.insereFinal(11);
    L1.insereFinal(22);
    L1.insereFinal(33);
    L1.insereFinal(44);
    L1.insereFinal(55);

    l2.insereFinal(10);
    l2.insereFinal(20);
    l2.insereFinal(30);
    l2.insereFinal(40);
    l2.insereFinal(50);

    cout << "Lista: " << endl;
    L1.imprime();

    cout << L1.numNos() << endl;

    //     int indice = L1.buscaMaior(50);
    // if (indice != -1)
    //     cout << "Elemento maior: " << L1.get(indice) << endl;
    // else
    //     cout << "Nao foi encontrado valor maior na lista." << endl;

    // L1.limpar();
    // cout << "Lista limpa: " << endl;
    // L1.imprime();

    //L1.calculaMedia();
    cout << L1.calculaMedia() << endl;

    L1.concatena(&l2);

    L1.imprime();

   /* L1.insereFinal(66);
    L1.insereFinal(67);
    L1.insereFinal(77);
    L1.insereFinal(78);
    L1.insereFinal(88);
    L1.insereFinal(89);
    L1.insereFinal(99);
    L1.insereFinal(100);
    L1.insereFinal(00);
    L1.insereFinal(01);

    cout << "Lista intriseca, antes de partir:" << endl;
    L1.imprime();
    ListaEncad* l1 = L1.partir(4);
    cout << "Lista intriseca, depois de partir:" << endl;
    L1.imprime();
    cout << "Lista nova" << endl;
    l1->imprime();*/

    return 0;
};

