#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string str1 = "bom", str2 = " dia";
    string str3, str;
    str3 = str1 + str2;
    str1 += str2; // recebe o conteudo da str1 + o conteudo da str2
    cout << str1 << endl; // bom + dia
    cout << str3 << endl; // bom dia
    str1 += " . boa noite";
    cout << str1 << endl; // bom dia . boa noite
    int tam = str2.size();
    cout << "Tamanho de str2 = ";
    cout << tam << endl; // Tamanho de str2 = 4
    cin >> str; // The Hobbit
    cout << "A string digitada e: ";
    cout << str << endl; // só sai o "The" pois tem espaço na string
}

/* Para ler uma linha inteira, e preciso usar a funcao
getline(cin,str)

exemplo:

string str;
getline(cin,str);

cout << "A string digitada e: " << str;
cout << endl;/*

