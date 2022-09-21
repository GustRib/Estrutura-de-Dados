#include <iostream>

using namespace std;

int main () 
{
    int *pt;
    int x;
    cout << *pt << endl;
    cout << "Digite um valor inteiro: " << endl;
    cin >> x;
    *pt = x;
    cout << "Valor de pt atualizado: "<< pt << endl;
}