
#include"Idesign.h"

/* CODE */

KhoiGach* TaoKhoiGach(int ID)
{
    KhoiGach* pKhoiGach = new KhoiGach;

    if(ID == 15)
    {
        pKhoiGach->Row = 4;
        pKhoiGach->Col = 1;
        pKhoiGach->iBoard = 0;
        pKhoiGach->jBoard = 5;
    }
    else if(ID == 31)
    {
        pKhoiGach->Row = 2;
        pKhoiGach->Col = 2;
        pKhoiGach->iBoard = 2;
        pKhoiGach->jBoard = 5;
    }
    else
    {
        pKhoiGach->Row = 2;
        pKhoiGach->Col = 3;
        pKhoiGach->iBoard = 2;
        pKhoiGach->jBoard = 5;

    }

    pKhoiGach->arr = new int*;

    int i;
    for(i = 0; i < pKhoiGach->Row; i++)
    {
        pKhoiGach->arr[i] = new int;
    }

    for(i = 0; i < pKhoiGach->Row * pKhoiGach->Col; i++)
    {
        pKhoiGach->arr[i / pKhoiGach->Col][i % pKhoiGach->Col] = (ID >> (pKhoiGach->Col * pKhoiGach->Row - 1 - i)) & 1;
    }

    return pKhoiGach;
}
void huyKhoiGach(KhoiGach* pKhoiGach)
{

    int i;
    for(i = 0; i < pKhoiGach->Row; i++)
        delete [] pKhoiGach->arr[i];
    delete [] pKhoiGach->arr;
    pKhoiGach = NULL;
}

int randomObject()
{

    srand(time(NULL));
    int x = rand() % 7 + 1;
    if(x == 1)
    {
        return 15;
    }
    if(x == 2)
    {
        return 30;
    }
    if(x == 3)
    {
        return 31;
    }
    if(x == 4)
    {
        return 51;
    }
    if(x == 5)
    {
        return 57;
    }
    if(x == 6)
    {
        return 58;
    }
    if(x == 7)
    {
        return 60;
    }
    return 0;
}
