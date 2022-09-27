#include <iostream>

using namespace std;


void imprimeDecrescente(int n){

    if (n == 0 || n < 0)
    {
        cout << 0;
    }
    else{
        cout << n << " ";
        imprimeDecrescente(n-1);
    }



}

/*
void imprimeIntervalo(int a, int b, int inc)
{
        if (a <= b)
        {
            cout << a << " ";
            imprimeIntervalo(a+inc, b, inc);
        }


    }
*/


/*
int fatorial(long long int n)
    {
        if (n==0 || n==1)
            return 1;
        else
            return n * fatorial (n-1);

    }
*/
int main()
{
    /* Exercício 5 alocação dinamica *//*
    int n;
    cout << "digite um valor inteiro: ";
    cin >> n;

    int *vet;
    vet = new int[n];

    int soma = 0;
    for(int i = 0; i<n; i++)
    {
        cout << "Digite o valor de indice: " << i << ": ";
        cin >> vet[i];
        soma += vet[i];
    }

    cout << "media dos valores: " << soma / (float)n << endl;

    delete [] vet;
    *//*

    float pot(float x, int n)
        {
            if(n==0)
                return 1.0;
            else if(n<0)
                return pot(1.0/x, -n);
            else
                return x * pot(x, n-1);
        }
    */
    int X;

    cin >> X;

    imprimeDecrescente(X);

    return 0;
}
