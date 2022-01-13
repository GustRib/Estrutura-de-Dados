#include <iostream>
#include "AlgumaClasse.h"
using namespace std;

int main() {
    int m;
    m = 5;
    int k = 1;
    MatrizEspecial v(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            v.set(i, j, i + k);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << v.get(i, j) << "  ";
        }
        cout << endl;
    }
    return 0;
}
