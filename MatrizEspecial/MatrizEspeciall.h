#ifndef MATRIZESPECIALL_H_INCLUDED
#define MATRIZESPECIALL_H_INCLUDED

int MatrizEspecial::get(int i, int k)
{
  int j=getInd(i, k);

  if(j==-1){
    cout << "Erro! Indice invalido";
    exit(1);
  }else{
    if(j==-2){
      return 0.0;
    }else{
      return vet[j];
    }
  }
}


#endif // MATRIZESPECIALL_H_INCLUDED
