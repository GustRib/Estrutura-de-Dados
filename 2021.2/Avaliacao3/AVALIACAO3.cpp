#include "AVALIACAO3.h"
#include <iostream>
#include <math.h>


using namespace std;
//construtor
Jogador::Jogador(int p, int m, int t)
{
    pontuacao = p;
    melhorClassificacao = m;
    totalTitulos = t;
}
//destrutor
void Jogador::setTotalTitulos(int t) {
  if (t > -1)
    totalTitulos  = t;
  else
    {
        cout << "Valor invalido" << endl;
    }

}


void setMelhorClassificacao(int m)
{
    if(m>melhorClassificacao)
    {
        melhorClassificacao = m;
    }
}

Jogador::Jogador(int p, int m, int t)
{
    pontuacao = p;
    melhorClassificacao = m;
    totalTitulos = t;
}
