#include <iostream>

using namespace std;

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