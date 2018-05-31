
#include"Icheck.h"

/* CODE */

int checkToGetPoint(Object* pObject, INFO* info)
{
    int i, j, countB = 0;

    /*Game Over*/
    if(pObject->iBoard <= 3)
        return -1;


    /* Win Game*/
    if(info->score >= 5000)
        return 2;


    /* check*/
    for(i = 0; i < MaxI; i++)
    {
        countB = 0;
        for(j = 0; j < MaxJ; j++)
        {
            // hoi
            if(Board[pObject->iBoard + i][j] == 1) // soa k phai la Board[i][j] == 1 vì lúc nay chưa gan gia tri cho bang
            {
                countB++;
            }
        }
        /* get score*/
        if(countB == MaxJ)
        {
            /*update new score, level,speed*/
            updateINFO(info);

            /* update located row of object ingame*/
            updateGame(pObject->iBoard + i);
            displayBoard();
            cout << "\a";

        }
    }
    return 1;
}

/*Move each small brick*/

bool inside(int i, int j)
{
    if(i >= 0 && i < MaxI && j >= 0 && j < MaxJ)
        return true;
    else
        return false;
}
bool left(int i, int j)
{
    if( j > 0 && inside(i, j) == true && Board[i][j - 1] == 0)
        return true;
    else
        return false;
}
bool right(int i, int j)
{
    if( j < MaxJ - 1&& inside(i, j) == true && Board[i][j + 1] == 0) // board
        return true;
    else
        return false;
}
bool down(int i, int j)
{
    if( i < MaxI - 1 && inside(i, j) == true && Board[i + 1][j] == 0) // board
        return true;
    else
        return false;
}

