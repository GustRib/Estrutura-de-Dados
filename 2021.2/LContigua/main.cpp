#include <iostream>
#include <cstdlib>
#include "ListaCont.h"
#include "ListaCont.cpp"

using namespace std;

int main()
{
    ListaCont l(2);

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);
    l.imprime();

    return 0;
}