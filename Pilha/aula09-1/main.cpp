#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;

void caminho ()
{
    PilhaEncad p;
    char dir;
    cin >> dir;
    while(dir != 'q')
    {
        if(dir == 'n' || dir == 's' || dir == 'l' || dir == 'o')
            p.empilha(dir);
        cin >> dir;
    }
    while(!p.vazia()
    {
        dir = p.desempilha();
        switch(dir)
        {
            case 'n'; cout << 's'; break;
            case 's'; cout << 'n'; break;
            case 'l'; cout << 'o'; break;
            case 'o'; cout << 'l'; break;
        }
    }
    cout << endl;
}

int main()
{
    caminho();
    return 0;
}

