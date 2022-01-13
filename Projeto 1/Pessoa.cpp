#include "Teste.h"
#include <iostream>


using namespace std;

MatrizEspecial::MatrizEspecial(int nn){

    n = nn;
    int tam;

   if(n % 2 == 0)
        tam = (n*n)/2;
   else
        tam = (n/2 + 1) * n;
 vet = new float[tam];
}

MatrizEspecial::~MatrizEspecial(){
    delete [] vet;
}

bool MatrizEspecial::verificaIndice(int i, int j) {
    if(i>=0 && i<n && j>= 0 && j<n){
        return true;
    }
    return false;
}
float MatrizEspecial::get(int i, int j) {
    if (verificaIndice(i, j)) {
        if (i == 0 || i - 1 == 0) {
            if (i % 2 == 0) {
                return vet[i + j];
            } else {
                return vet[i-1 + j] * (-1);
            }
        } else if (i % 2 == 0) {
            return vet[i * i + 1 + j];
        } else {
            return vet[(i - 1) * (i - 1) + 1 + j] * (-1);
        }
    } else {
        cout << "INDICES INVALIDOS : GET" << endl;
    }
}
void MatrizEspecial::set(int i, int j, float val){
    if(verificaIndice(i,j)){
        if(i==0 || i-1 == 0){
            if(i%2 == 0){
                vet[i+j] = val;
            }else{
                vet[i-1+j] = val *(-1);
            }
        }else if(i%2 == 0){
            vet[i*i+1+j] = val;
        }else{
            vet[(i-1)(i-1)+1+j] = val(-1);
        }
    }else{
        cout << "INDICES INVALIDOS :SET";
    }
}
