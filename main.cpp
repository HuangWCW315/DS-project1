#include "class.h"
#include <stdlib.h>
#include <cstring>
#include <fstream>

int main()
{
    int row, col;
    
    cin >> row >> col;
    playing_space space(row, col);

    char ch[50];
    int begin;
    bool game_over = false;
    cin >> ch;
    while (strcmp(ch, "End") && !game_over)
    {    
        char type;
        int type_number;

        if (ch[0] != 'O') {
            type_number = atoi(&ch[1]);
            type = ch[0];
        }
        else type = ch[0];

        cin >> begin;
        begin--;
        block *B;

        if (!game_over)
        {   
            if (type == 'T')     
                B = new T_block(begin, type_number);
            else if (type == 'L')
                B = new L_block(begin, type_number);
            else if (type == 'J')
                B = new J_block(begin, type_number); 
            else if (type == 'S')
                B = new S_block(begin, type_number); 
            else if (type == 'Z')
                B = new Z_block(begin, type_number); 
            else if (type == 'I')
                B = new I_block(begin, type_number); 
            else
                B = new O_block(begin);
            space.drop(*B);
            for (int j = 0, k = 0; j < 4; ++j)
            {    
                if (B->get_now_row() - k >= 4 && space.delete_row(B->get_now_row() - k));
                else k++;
            }
            game_over = space.check_over();
            delete B;
        }

        if (!game_over) cin >> ch;
    }
    space.print();

    return 0;
}