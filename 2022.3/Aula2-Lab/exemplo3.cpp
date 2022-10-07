#include <iostream>

using namespace std;

void imprimeDecrescente(int n)
{
    if (n == 0 || n < 0)
    {
        cout << 0;
    }
    else
    {
        cout << n << " ";
        imprimeDecrescente(n-1);
    }
}

int main()
{
    int n;

    cin >> n >> endl;

    imprimeDecrescente(n);

    return 0;
}

