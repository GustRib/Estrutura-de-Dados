#ifndef AVALIACAO3_H_INCLUDED
#define AVALIACAO3_H_INCLUDED

class Jogador {

  private:

    int pontuacao;
    int melhorClassificacao;
    int totalTitulos;
  public:

    Jogador(int p, int m, int t);      /// construtor
    ~Jogador();          /// destrutor

    inline void setPontuacao(int p){ pontuacao = p;}
    void setMelhorClassificacao (int m);
    inline void setTotalTitulos(int t) {totalTitulos = t;}
    void posicaoRanking(int ranking[], int n);
};


#endif // AVALIACAO3_H_INCLUDED
