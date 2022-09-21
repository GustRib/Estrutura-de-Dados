#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Caminho.h"
#include "MatrizDistancias.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q1
// Implemente aqui sua solução para as tarefas da questão 1.
// Letra A

void questao1()
{
    // Letra B


    // Letra C


    // Letra D


    // Letra E


    // Letra F


    // Letra G


    // Letra H


    // Letra I


    // Letra J

}
//-Q1
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
//Q2

int strToInt(char *s, int n)
{
    // Implemente aqui sua solução para a questão 2.
    // Se necessário, remova o código abaixo.
    return 0;
}

//-Q2
// ----------------------------------------------------------------------------

int main()
{
    // TESTES PARA A QUESTAO 1 ------------------------------------------------
    cout << "TESTE PARA A QUESTAO 1" << endl << endl;
    questao1();
    cout << endl << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 2 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 2" << endl << endl;
    cout << "String: \"0\" \n\t==> Resultado esperado: 0 \n\t==> Resultado obtido: " << strToInt("0", 1) << endl << endl;
    cout << "String: \"2340\" \n\t==> Resultado esperado: 2340 \n\t==> Resultado obtido: " << strToInt("2340", 4) << endl << endl;
    cout << "String: \"33\" \n\t==> Resultado esperado: 33 \n\t==> Resultado obtido: " << strToInt("33", 2) << endl << endl;
    cout << "String: \"8291029\" \n\t==> Resultado esperado: 8291029 \n\t==> Resultado obtido: " << strToInt("8291029", 7) << endl << endl;
    cout << endl << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 3 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 3" << endl << endl;
    int n = 5;
    Caminho c(n);
    cout << "Caminho gerado pelo construtor: \n\t==> Resultado esperado: 0 --> 1 --> 2 --> 3 --> 4 \n\t==> Resultado obtido: \t";
    c.imprimirCaminho();
    cout << endl;

    int **distancias = new int*[n];
    for(int i = 0; i < n; i++)
        distancias[i] = new int[n];

    for(int i = 0; i < n; i++)
        distancias[i][i] = 0;
    distancias[1][0] = distancias[0][1] = 4;
    distancias[2][0] = distancias[0][2] = 7;
    distancias[3][0] = distancias[0][3] = 3;
    distancias[4][0] = distancias[0][4] = 6;
    distancias[2][1] = distancias[1][2] = 1;
    distancias[3][1] = distancias[1][3] = 7;
    distancias[4][1] = distancias[1][4] = 9;
    distancias[3][2] = distancias[2][3] = 9;
    distancias[4][2] = distancias[2][4] = 7;
    distancias[4][3] = distancias[3][4] = 4;

    cout << "Distancia percorrida pelo caminho do construtor: \n\t==> Resultado esperado: 18 \n\t==> Resultado obtido: \t" << c.calculaDistanciaPercorrida(distancias) << endl << endl;

    c.buscaGulosa(distancias);
    cout << "Menor caminho a partir da cidade 0: \n\t==> Resultado esperado: 0 --> 3 --> 4 --> 2 --> 1 \n\t==> Resultado obtido: \t";
    c.imprimirCaminho();
    cout << endl;
    cout << "Distancia percorrida no menor caminho: \n\t==> Resultado esperado: 15 \n\t==> Resultado obtido: \t" << c.calculaDistanciaPercorrida(distancias) << endl << endl;

    for(int i = 0; i < n; i++)
        delete [] distancias[i];
    delete [] distancias;
    cout << endl << endl;

    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 4 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 4" << endl << endl;
    MatrizDistancias mat(5);
    mat.set(1, 0, 4);
    mat.set(2, 0, 7);
    mat.set(3, 0, 3);
    mat.set(4, 0, 6);
    mat.set(2, 1, 1);
    mat.set(3, 1, 7);
    mat.set(4, 1, 9);
    mat.set(3, 2, 9);
    mat.set(4, 2, 7);
    mat.set(4, 3, 4);

    cout << "Matriz esperada:" << endl;

    cout << "Matriz 5 x 5:" << endl;
    cout << "0\t4\t7\t3\t6" << endl;
    cout << "4\t0\t1\t7\t9" << endl;
    cout << "7\t1\t0\t9\t7" << endl;
    cout << "3\t7\t9\t0\t4" << endl;
    cout << "6\t9\t7\t4\t0" << endl << endl;

    cout << "Matriz obtida:" << endl;
    mat.imprime();
    cout << endl << endl;

    // ------------------------------------------------------------------------

    return 0;
}
