#include "class.h"

////////////////////////////////////////////////////////////////////
/*
    start of the definition of playing_space
*/
////////////////////////////////////////////////////////////////////
playing_space::playing_space(int ROW, int COL):row(ROW + 4), col(COL){
    space = new bool*[row];
    for (int i = 0; i < row; ++i)
        space[i] = new bool[COL];
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < COL; ++j)
            space[i][j] = 0;
}

playing_space::~playing_space(){
    for (int i = 0; i < row; ++i)
        delete space[i];
    delete space;
}

void playing_space::print_real_space(){
    for (int i = 0; i < row; ++i)
    {        
        for (int j = 0; j < col; ++j)
            cout << space[i][j] << ' ';
        cout << endl;
    }
}

void playing_space::drop(block &d_b){
    bool stop = false;
    for (int i = d_b.now_row; (i < row - 1) && (!stop); i++)
    { 
        for (int j = 0; (j < d_b.stop_size) && (!stop); ++j)
        {
            if (space[i - d_b.stop_position_height[j] + 1][d_b.initial_position + j])
                stop = true;
        }
        if (!stop) d_b.now_row++;
    }
    for (int i = 0; i < 4; ++i)
        space[d_b.now_row - d_b.block_position[i][0]][d_b.initial_position + d_b.block_position[i][1]] = true;

}

bool playing_space::check_over(){
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < col; ++j)
            if (space[i][j]) return true;
    return false;
}

bool playing_space::delete_check(int read_row){
    int sum = 0;
    for (int i = 0; i < col; ++i)
    {
        sum += space[read_row][i];
    }
    if (sum == col) return true;
    else return false;
}

void playing_space::delete_row(int row_deleted){
    if (delete_check(row_deleted))
    {
        for (int i  = row_deleted; i >= 1; --i)
            for (int j = 0; j < col; ++j)
                space[i][j] = space[i - 1][j];
    }
    for (int i = 0; i < col; ++i)
        space[0][i] = false;
    return;
}

void playing_space::print(){
    for (int i = 4; i < row; ++i)
    {        
        for (int j = 0; j < col; ++j)
            cout << space[i][j] << ' ';
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////////
/*
    end of the definition of playing_space
*/
////////////////////////////////////////////////////////////////////

int block::get_now_row(){
    return now_row;
}

////////////////////////////////////////////////////////////////////
/*
    start of the definition of T_block
*/
////////////////////////////////////////////////////////////////////

T_block::T_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 3;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 1;
        stop_position_height[1] = 0;
        stop_position_height[2] = 1;

        block_position[0][0] = 0;
        block_position[0][1] = 1;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 1; 
        block_position[3][1] = 2;
    }
    else if (type == 2)
    {
        stop_size = 2;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 1;
        stop_position_height[1] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 1;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 2; 
        block_position[3][1] = 1;
    }
    else if (type == 3)
    {
        stop_size = 3;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 0;
        stop_position_height[2] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 0;
        block_position[1][1] = 1;
        block_position[2][0] = 0;
        block_position[2][1] = 2;
        block_position[3][0] = 1; 
        block_position[3][1] = 1;
    }
    else if (type == 4)
    {
        stop_size = 2;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 1;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 2; 
        block_position[3][1] = 0;
    }
    else cout << "invalid input!!" << endl;

}
T_block::~T_block(){delete stop_position_height;}
////////////////////////////////////////////////////////////////////
/*
    end of the definition of T_block
*/
////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
/*
    start of the definition of L_block
*/
////////////////////////////////////////////////////////////////////

L_block::L_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 2;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 0;
        block_position[1][1] = 1;
        block_position[2][0] = 1;
        block_position[2][1] = 0;
        block_position[3][0] = 2; 
        block_position[3][1] = 0;
    }
    else if (type == 2)
    {
        stop_size = 3;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 1;
        stop_position_height[2] = 1;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 1; 
        block_position[3][1] = 2;
    }
    else if (type == 3)
    {
        stop_size = 2;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 2;
        stop_position_height[1] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 1;
        block_position[1][0] = 1;
        block_position[1][1] = 1;
        block_position[2][0] = 2;
        block_position[2][1] = 0;
        block_position[3][0] = 2; 
        block_position[3][1] = 1;
    }
    else if (type == 4)
    {
        stop_size = 3;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 0;
        stop_position_height[2] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 0;
        block_position[1][1] = 1;
        block_position[2][0] = 0;
        block_position[2][1] = 2;
        block_position[3][0] = 1; 
        block_position[3][1] = 2;
    }
    else cout << "invalid input!!" << endl;

}
L_block::~L_block(){delete stop_position_height;}
////////////////////////////////////////////////////////////////////
/*
    end of the definition of L_block
*/
////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
/*
    start of the definition of J_block
*/
////////////////////////////////////////////////////////////////////

J_block::J_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 2;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 0;
        block_position[1][1] = 1;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 2; 
        block_position[3][1] = 1;
    }
    else if (type == 2)
    {
        stop_size = 3;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 0;
        stop_position_height[2] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 0;
        block_position[1][1] = 1;
        block_position[2][0] = 0;
        block_position[2][1] = 2;
        block_position[3][0] = 1; 
        block_position[3][1] = 0;
    }
    else if (type == 3)
    {
        stop_size = 2;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 2;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 2;
        block_position[2][1] = 0;
        block_position[3][0] = 2; 
        block_position[3][1] = 1;
    }
    else if (type == 4)
    {
        stop_size = 3;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 1;
        stop_position_height[1] = 1;
        stop_position_height[2] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 2;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 1; 
        block_position[3][1] = 2;
    }
    else cout << "invalid input!!" << endl;

}
J_block::~J_block(){delete stop_position_height;}
////////////////////////////////////////////////////////////////////
/*
    end of the definition of J_block
*/
////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
/*
    start of the definition of S_block
*/
////////////////////////////////////////////////////////////////////

S_block::S_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 3;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 0;
        stop_position_height[2] = 1;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 0;
        block_position[1][1] = 1;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 1; 
        block_position[3][1] = 2;
    }
    else if (type == 2)
    {
        stop_size = 2;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 1;
        stop_position_height[1] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 1;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 2; 
        block_position[3][1] = 0;
    }
    else cout << "invalid input!!" << endl;

}
S_block::~S_block(){delete stop_position_height;}
////////////////////////////////////////////////////////////////////
/*
    end of the definition of S_block
*/
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
/*
    start of the definition of Z_block
*/
////////////////////////////////////////////////////////////////////

Z_block::Z_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 3;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 1;
        stop_position_height[1] = 0;
        stop_position_height[2] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 1;
        block_position[1][0] = 0;
        block_position[1][1] = 2;
        block_position[2][0] = 1;
        block_position[2][1] = 0;
        block_position[3][0] = 1; 
        block_position[3][1] = 1;
    }
    else if (type == 2)
    {
        stop_size = 2;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 1;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 1;
        block_position[2][1] = 1;
        block_position[3][0] = 2; 
        block_position[3][1] = 1;
    }
    else cout << "invalid input!!" << endl;

}
Z_block::~Z_block(){delete stop_position_height;}
////////////////////////////////////////////////////////////////////
/*
    end of the definition of Z_block
*/
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
/*
    start of the definition of I_block
*/
////////////////////////////////////////////////////////////////////

I_block::I_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 1;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 1;
        block_position[1][1] = 0;
        block_position[2][0] = 2;
        block_position[2][1] = 0;
        block_position[3][0] = 3; 
        block_position[3][1] = 0;
    }
    else if (type == 2)
    {
        stop_size = 4;
        stop_position_height = new int[stop_size];
        stop_position_height[0] = 0;
        stop_position_height[1] = 0;
        stop_position_height[2] = 0;
        stop_position_height[3] = 0;

        block_position[0][0] = 0;
        block_position[0][1] = 0;
        block_position[1][0] = 0;
        block_position[1][1] = 1;
        block_position[2][0] = 0;
        block_position[2][1] = 2;
        block_position[3][0] = 0; 
        block_position[3][1] = 3;
    }
    else cout << "invalid input!!" << endl;

}
I_block::~I_block(){delete stop_position_height;}
////////////////////////////////////////////////////////////////////
/*
    end of the definition of I_block
*/
////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
/*
    start of the definition of O_block
*/
////////////////////////////////////////////////////////////////////

O_block::O_block(int initial_place){
    
    now_row = 3;
    initial_position= initial_place;

    stop_size = 2;
    stop_position_height = new int[stop_size];
    stop_position_height[0] = 0;
    stop_position_height[1] = 0;

    block_position[0][0] = 0;
    block_position[0][1] = 0;
    block_position[1][0] = 0;
    block_position[1][1] = 1;
    block_position[2][0] = 1;
    block_position[2][1] = 0;
    block_position[3][0] = 1; 
    block_position[3][1] = 1;

}
O_block::~O_block(){delete stop_position_height;}
////////////////////////////////////////////////////////////////////
/*
    end of the definition of O_block
*/
////////////////////////////////////////////////////////////////////
