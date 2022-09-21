#include <iostream>

using namespace std;

int main () 
{
    int x = 10, y = 20;
    int *pt; // declaracao
    pt = &x; // inicializacao: pt aponta para x
    cout << *pt; // imprime conteudo apontado pelo ponteiro pt
    
    *pt = 66; // altera o conteudo apontado por pt
    pt = &y; // pt aponta para y;
}