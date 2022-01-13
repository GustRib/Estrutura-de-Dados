#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//-Q1----------------------------------------------------------------------------

    // Letra A 
void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;

    // Letra B
    int x = 10, y = 21;

    // Letra C
    cout << "x: " << &x << endl;
    cout << "y: " << &y << endl;

    // Letra D  
    troca(&x, &y);

    // Letra E
    int *p;
    cout <<"p: " << &p << endl;

    // Letra F
    p = &x;
    cout << "endereco x: " << p << endl;
    cout << "valor x: " << *p << endl;

    // Letra G
    *p = 42;
    
    // Letra H
    p = new int[2];
    p[0] = 2;
    p[1] = 4;

    // Letra I
    troca (p, p + 1);

    // Letra J
    cout << p[0] << endl << p[1] << endl;

    delete[] p;

}

//Q1----------------------------------------------------------------------------

//Q2

int charToInt(char c)
{
    return c = '0';
}

int strToInt(char *s, int n)
{
    if (n > 0) return charToInt(*s) * pow(18, n - 1) + strToInt(s + 1, n - 1);
    else
        return 0;
}
int main()
{
    

// TESTES PARA A QUESTAO 2 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 2" << endl << endl;
    cout << "String: \"0\" \n\t==> Resultado esperado: 0 \n\t==> Resultado obtido: " << strToInt("0", 1) << endl << endl;
    cout << "String: \"2340\" \n\t==> Resultado esperado: 2340 \n\t==> Resultado obtido: " << strToInt("2340", 4) << endl << endl;
    cout << "String: \"33\" \n\t==> Resultado esperado: 33 \n\t==> Resultado obtido: " << strToInt("33", 2) << endl << endl;
    cout << "String: \"8291029\" \n\t==> Resultado esperado: 8291029 \n\t==> Resultado obtido: " << strToInt("8291029", 7) << endl << endl;
    cout << endl << endl;
    // ------------------------------------------------------------------------
    
    return 0;
}
