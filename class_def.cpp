#include <iostream>
#include "class.h"
using namespace std;

////////////////////////////////////////////////////////////////////
/*
    start of the definition of playing_space
*/
////////////////////////////////////////////////////////////////////
playing_space::playing_space(int ROW, int COL):row(ROW), col(COL){
    space = new bool*[ROW];
    for (int i = 0; i < ROW; ++i)
        space[i] = new bool[COL];
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            space[i][j] = 0;
}

playing_space::~playing_space(){
    for (int i = 0; i < row; ++i)
        delete space[i];
    delete space;
}

void playing_space::print(){
    for (int i = 0; i < row; ++i)
    {        
        for (int j = 0; j < col; ++j)
            cout << space[i][j];
        cout << endl;
    }
}

bool playing_space::drop(block &d_b){
    bool stop = false;
    for (int i = 0; (i < row - 1) && (!stop); i++)
    { 
        for (int j = 0; (j < d_b.stop_size) && (!stop); ++j)
        {
            if (space[d_b.now_row - d_b.stop_position_height[j] + 1][d_b.initial_position + j])
                stop = true;
        }
        if (!stop) d_b.now_row++;
    }
    for (int i = 0; i < 4; ++i)
        if (d_b.now_row - d_b.block_position[i][0] < 0);
        else
            space[d_b.now_row - d_b.block_position[i][0]][d_b.initial_position + d_b.block_position[i][1]] = true;
    if (d_b.now_row <= 1) return false;
    return true;
}

////////////////////////////////////////////////////////////////////
/*
    end of the definition of playing_space
*/
////////////////////////////////////////////////////////////////////

block::~block(){
    delete stop_position_height;
    cout << "deleted!\n";
}

////////////////////////////////////////////////////////////////////
/*
    start of the definition of T1
*/
////////////////////////////////////////////////////////////////////

T1::T1(int initial_place){
    now_row = 0;
    initial_position= initial_place;
    stop_size = 3;
    stop_position_height[0] = 1;
    stop_position_height[1] = 0;
    stop_position_height[2] = 1;
    stop_position_height[3] = -1;

    block_position[0][0] = 0;
    block_position[0][1] = 1;
    block_position[1][0] = 1;
    block_position[1][1] = 0;
    block_position[2][0] = 1;
    block_position[2][1] = 1;
    block_position[3][0] = 1; 
    block_position[3][1] = 2;
}

////////////////////////////////////////////////////////////////////
/*
    end of the definition of T1
*/
////////////////////////////////////////////////////////////////////
