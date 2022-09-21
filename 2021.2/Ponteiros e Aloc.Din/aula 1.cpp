#include <iostream>
using namespace std;

void troca(int *a, int *b)
{
    cout << "*a = " << *a << endl;
    cout << "*b = " << *b << endl;

    int aux = *a;
    *a = *b;
    *b = aux;

    cout << "*a = " << *a << endl;
    cout << "*b = " << *b << endl;
}    

    void incr_vet (int tam, int vet[])
    {
        int i;
        for(i=0; i<tam; i++)
            vet [i] = vet [i] + 1;

    }

    int main()
    {
        int x = 2, y = 30;

        cout << "x = " << x << endl;
        cout << "y = " << y << endl;

        troca (&x, &y);

        cout << "x = " << x << endl;
        cout << "y = " << y << endl;

        x = x +1;

        cout << "x = " << x << endl;

        int *p;
        p = &x;

        cout << "p = " << p << endl;
        cout << "*p = " << *p << endl;

        *p = *p + 1;
        cout << "*p = " << *p << endl;
        cout << "y = " << y << endl;

        int vet[3] = {10, 20, 30};
        cout << "enderecos" << endl;
        cout << vet << endl;
        cout << vet+1 << endl;
        cout << vet+2 << endl;
        cout << "valores" << endl;
        cout << vet[0] << endl;
        cout << vet[1] << endl;
        cout << vet[2] << endl;
        cout << "valores" << endl;
        cout << *vet << endl;
        cout << *(vet+1) << endl;
        cout << *(vet+2) << endl;

        int *pt = NULL;

        cout << pt << endl;

        return 0;

    }