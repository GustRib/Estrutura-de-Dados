#include <cmath>
#include "poligono.h"

using namespace std;

float Poligono:area()
{
    return numLados*pow(tamLado,2) / (4*tan(3.141592/numLados));
}

float poligono::perimetro()
{
    return numLados*tamLado;
}

float Poligono::angInterno()
{
return 180*(numLados - 2)/numLados;
}

void Poligono::lePoligono()
{
    cout << "Digite o numero de lados: ";
    cin >> numLados;
    while(!(numLados > 2))
    {
        cout << "Entrada invalida" << endl;
        cout << "Digite o numero";
        cin >> numLados;
    }
    while(!(tamLado > 0))
    {
        cout << "Entrada invalida" << endl;
        cout << "Digite o tamanho de cada lado: ";
        cin >> tamLado;
    }

}