#include <iostream>
#include "class.h"
using namespace  std;

int main()
{
    playing_space space(19, 15);
    space.print();
    bool flag = true;
    for (int i = 0; i < 10 && flag; i++)
{    
    block *T = new T1(3);
    flag = space.drop(*T);
    delete T;
        }
    
space.print();
if (!flag) cout << "Game over!!" << endl;
    return 0;
}