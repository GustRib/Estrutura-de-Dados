#include <iostream>
using namespace std;

int main ()
{
    int *pt = new int;
    *pt = *pt + 1;
    delete pt;

    int *pt_x = new int[100];
        for(int i = 0; i < 100; i++)
        pt_x[i] = i*i;
        delete [] pt_x;
}