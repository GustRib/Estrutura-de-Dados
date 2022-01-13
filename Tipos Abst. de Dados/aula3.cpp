/*
Nivel 1

inicio
"declarar as variaveis";
"leia os 3 numeros";
se "existe triangulo" entao
"verifique o tipo de triangulo";
senao
"escreva mensagem";
fim-se;
fim
*/

/*
Nivel 2-3

inicio
// declarac ̧ ̃ao das vari ́aveis
int X, Y, Z;
// leitura dos 3 n ́umeros
leia(X, Y, Z);
se "existe triangulo" entao
"verifique o tipo de triˆangulo";
senao
imprima("Os lados", X, Y, "e", Z,
"n ̃ao formam triˆangulo");

fim-se;
fim
*/

/* 
Nivel 4
*/

#include <iostream>
using namespace std;

void verifica_escaleno(int x, int y, int z)
{
if ((x == y) || (x == z) || (y == z))
cout << "Triangulo isosceles" << endl;
else
cout << "Triangulo escaleno" << endl;
}

int main()
{
int x, y, z;
cout << "Digite tres valores inteiros\n";
cin >> x >> y >> z;
if ((x < y+z) && (y < x+z) && (z < x+y))
{
// verifica tipo de triangulo
if ((x == y) && (x == z))
cout << "Triangulo equilatero";
else
verifica_escaleno(x, y, z);
}
else
cout << x << ", " << y << " e "
<< z << " nao formam triangulos";

}

