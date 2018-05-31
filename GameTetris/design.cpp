
#include"Idesign.h"

/* CODE */

Object* designObject(int ID)
{
    Object* pObject = new Object;

    if(ID == 15)
    {
        pObject->Row = 4;
        pObject->Col = 1;
        pObject->iBoard = 0;
        pObject->jBoard = 5;
    }
    else if(ID == 31)
    {
        pObject->Row = 2;
        pObject->Col = 2;
        pObject->iBoard = 2;
        pObject->jBoard = 5;
    }
    else
    {
        pObject->Row = 2;
        pObject->Col = 3;
        pObject->iBoard = 2;
        pObject->jBoard = 5;

    }

    pObject->arr = new int*;

    int i;
    for(i = 0; i < pObject->Row; i++)
    {
        pObject->arr[i] = new int;
    }

    for(i = 0; i < pObject->Row * pObject->Col; i++)
    {
        pObject->arr[i / pObject->Col][i % pObject->Col] = (ID >> (pObject->Col * pObject->Row - 1 - i)) & 1;
    }

    return pObject;
}
void destroyObject(Object* pObject)
{

    int i;
    for(i = 0; i < pObject->Row; i++)
        delete [] pObject->arr[i];
    delete [] pObject->arr;
    pObject = NULL;
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
