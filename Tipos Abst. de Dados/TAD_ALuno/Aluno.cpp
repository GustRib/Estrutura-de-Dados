#include <iostream>

#include "Aluno.hpp"
//#include "string.h"


using namespace std;
Aluno (char n, char mat)
{
    //strcpy(matricula, n);
    int i = 0;
    ///leitura do nome
    for (int i=0; n[i]!='\0'; i++)
    {
        nome[i] = n[i];
    }
    nome [i] = '\0';   

    ///leitura matricula
    for (int i=0; mat[i]!='\0'; i++)
    {
        matricula[i] = mat[i];
    }
    matricula[i] = '\0';  
}

Aluno::~Aluno()
{
    cout<<"destruindo obj"<<endl;
}

void Aluno::leNotas()
{
    for(int i=0; i<7; i++)
    {
        cout<<"Nota["<<i<<"] = ";
        cin>>notas[i];
    }
}

double Aluno::calculaMedia();
{
    double soma = 0.0;
    for(int i=0; i<7; i++)
        soma = soma + notas[i];

        return soma/7.0;

void Aluno::setMatricula (char mat[])
{
    int i;
    ///leitura matricula
    for (int i=0; mat[i]!='\0'; i++)
        matricula[i] = mat[i];
    matricula[i] = '\0';  
}

char* Aluno::getMatricula()
{
    int i;
    char *m = new char[15];
    
    ///copia matricula
    for (int i=0; i<15 && matricula[i]!='\0'; i++)
        m[i] = matricula[i];
    m[i] = '\0';
    return m;
}
