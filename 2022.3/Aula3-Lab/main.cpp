#include <iostream>
#include "Aluno.h"
#include "Aluno.cpp"
using namespace std;

int main()
{
    char nome[6] = {'a', 'n', 'a', '\0'};
    char matr[6] = {'1', '2', '3', '4', '5', '\0'};
    Aluno a1(nome, matr);

    /*matr[0] = '9';
    nome[1] = "M";
    Aluno a2(nome, matr); */

    a1.leNotas();
    a1.setIdade(58);
    char *m = a1.getMatricula;

    cout<<"Idade: "<<a1.getIdade()<<endl;
    cout<<"Matricula: "<<a1.getMAtricula()<<endl;
    cout<<"Media: "<<a1.calculaMedia()<<endl;

    delete [] m;

    
    return 0;
}
