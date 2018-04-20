#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#define LEFT 4
#define TOP 4

#define MaxI 22
#define MaxJ 10

int Board[MaxI][MaxJ];

struct KhoiGach
{
    int **_arr;
    int _Row,_Col;
    int _iBoard,_jBoard;
};


#endif // STRUCT_H_INCLUDED
