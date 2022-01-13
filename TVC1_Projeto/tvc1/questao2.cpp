#include <iostream>

using namespace std;

int gustaAjuda(int n, int m)
{
    int vetor[100],i; 
    for(i = 0;m>=n;i++)
    {
        vetor[i] = m;
        m=m/2;
    }
    
    for(int g=i-1, j = i;g>=0;j++,g--)
    {
        vetor[j] = vetor[g];
    }
    
    for(int k = 0;k<i*2;k++)
    {
        cout<<vetor[k]<<" ";
    }
    return 1;
}


int main()
{
    gustaAjuda(100,1024);

    return 0;
}