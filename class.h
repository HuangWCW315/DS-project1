#ifndef CLASS_H
#define CLASS_H

class playing_space{
    private:
        bool **space;        // playing space
        int row;
        int col;
    public:
        playing_space():row(0), col(0){}
        playing_space(int ROW, int COL);      // initializing space
        ~playing_space();
        void print();
        void drop(class block &d_b);
        bool delete_check(int read_row);
        void delete_row(int row_deleted);
        bool check_over();
};

class block{
    friend playing_space;
    protected:
        int stop_size;
        int stop_position_height[4];  
            // when stop_position_height[i] = 1, it means the the block itselt
            // is at the second row regarding the row of reference point is row 1, and i means
            // i colume far from the reference point
        int block_position[4][2];     // block exact position
                                      // arrange by {row, colume}
        int now_row;
        int initial_position;
    public:
    ~block();
    int get_now_row();
};

class T1:public block{
    public:
    T1(){}
    T1(int initial_place);
    ~T1();

};

#endif