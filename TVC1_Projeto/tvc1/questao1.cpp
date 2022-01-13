#include <iostream>

using namespace std;

//primeira parte

int *vetorPositivos(int vet[], int n, int *t)
{
    int j;
    
    for(int i = 0;i<n;i++)
    {
        if(vet[i]>-1) j++;
    }
    
    if(j>0)
    {
        
    int posivosVet[j];
    int *p;
    
    for(int k = 0; k<n;k++)
    {
        if(vet[k]>-1) posivosVet[k] = vet[k]; 
    }
        
        p = posivosVet;
        return p;
    
    }
    else return NULL;
    
    return nullptr;
}

//segunda parte 

int main()
{
    int n;
    cin>>n;
    int *t;
    int *novoVetor = new int[n];
    
    for(int i = 0; i<n ; i++)
    {
        cin>>novoVetor[i]; 
    }
    
    novoVetor = vetorPositivos(novoVetor, n, t);
    
    for(int i = 0;i<2;i++)
    {
        cout<<novoVetor[i]<<" ";
    }

    return 0;
}