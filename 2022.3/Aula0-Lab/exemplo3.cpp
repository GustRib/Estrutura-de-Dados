#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string str1;
    string str2 = "Bob Esponja";
    cout << "Digite um nome: ";
    cin >> str1;
    cout << "Personagem 1: " << str1 << endl;
    cout << "Personagem 2: " << str2 << endl;
    cout << "Terceira letra: " << str1[2];
    cout << endl;
    cout << "Primeira letra: " << str2[0];
    cout << endl;
    return 0;
}