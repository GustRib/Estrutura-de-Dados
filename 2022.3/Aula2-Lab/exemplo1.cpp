#include <iostream>

using namespace std;

int fatorial(long long int n)
    {
        if (n==0 || n==1)
            return 1;
        else
            return n * fatorial (n-1);

    }

int main()
{
    /* Exercício 5 alocação dinamica *//*
    int n;
    cout << "digite um valor inteiro: ";
    cin >> n;

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
}
