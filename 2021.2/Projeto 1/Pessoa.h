#ifndef REVISAO_TAD_TESTE_H
#define REVISAO_TAD_TESTE_H


class MatrizEspecial {
public:
    MatrizEspecial(int nn);
    ~MatrizEspecial();
    float get(int i, int j);
    void set(int i, int j, float val);
    bool verificaIndice(int i, int j);
private:
    float *vet;
    int n,tam;

};


#endif //REVISAO_TAD_TESTE_H
