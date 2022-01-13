    #include <iostream>

    using namespace std;

    /* Exercicio 1*/
    int main(){
        int *pt;
        int x;
        cout << "Endereço do ponteiro: " << &pt << endl;
        cin >> x;
        pt = &x; // inicializacao
        cout << "Conteudo do ponteiro: " << *pt << endl;
        cout << "Endereço de x: " << pt << endl;
        *pt = *pt * 10;
        cout << "Conteudo do ponteiro: " << *pt << endl;
        *pt += 10;
        cout << "Conteudo do ponteiro: " << *pt << endl;
        cout << "Variavel ponteiro: " << pt << endl;

        return 0;
    }


