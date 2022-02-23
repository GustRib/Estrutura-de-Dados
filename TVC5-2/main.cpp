#include <iostream>
#include "ArvBin.h"
#include "ArvBin.cpp"
using namespace std;

int main()
{
    ArvBin arv, vazia, a1, a2, a3;
a1.cria(-35, &vazia, &vazia);
a2.cria(-19, &vazia, &vazia);
a3.cria(-20, &a1, &a2);
a1.cria(-5, &vazia, &vazia);
a2.cria(10, &a1, &vazia);
a1.cria(-15, &a3, &a2);
a2.cria(45, &vazia, &vazia);
a3.cria(60, &vazia, &vazia);
a2.cria(50, &a2, &a3);
a3.cria(80, &vazia, &vazia);
a2.cria(75, &a2, &a3);
arv.cria(40, &a1, &a2);
a1.anulaRaiz();
a2.anulaRaiz();
a3.anulaRaiz();

return 0
}
