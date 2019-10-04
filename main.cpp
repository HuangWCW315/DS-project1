#include <iostream>
#include "class.h"
using namespace  std;

int main()
{
    playing_space space(5, 6);
    bool game_over = false;
    int arr[] = {0,3,0,3,0,3,0,3,0,3};
    int type;
    cin>>type;
    for (int i = 0; i < 1 && !game_over; i++)
    {    
        block *T = new O_block(arr[i]);
        space.drop(*T);
        for (int j = 0; j < 4; ++j)
            space.delete_row(T->get_now_row() - j);
        game_over = space.check_over();
        delete T;
    }
    space.print_real_space();
    if (game_over) cout << "Game over!!" << endl;

    return 0;
}