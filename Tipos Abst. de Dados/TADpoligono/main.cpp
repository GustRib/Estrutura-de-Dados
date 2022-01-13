#include <iostream>
#include "poligono.h"

using namespace std;

int main()
{
    Poligono p;
    p.lePoligono();

    cout << "Area: " << p.area() << endl;
    cout << "Perimetro: " << p.perimetro() << endl;
    cout << "Angulo interno: " << p.angInterno() << endl;

    return 0;
}
