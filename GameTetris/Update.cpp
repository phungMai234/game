
#include"IUpdate.h"

/* CODE */

void updateGame(int  row)
{
    int i, j;

    for(i = row; i > 0; i--)
    {
        for(j = 0; j < MaxJ; j++)
        {
            Board[i][j] = Board[i - 1][j];
        }
    }

}
void getValue(Object* pObject)
{
    int i, j;
    for(i = 0; i < pObject->Row; i++)
    {

        for(j = 0; j < pObject->Col; j++)
        {
            if(pObject->arr[i][j] == 1)
                Board[pObject->iBoard + i][pObject->jBoard + j] = 1;
        }
    }
}

void initGame(INFO* info)
{
    info->score = 0;
    info->level = 1;
    info->speed = 0.4;
}

void updateINFO(INFO* info)
{
    /* add score*/
    info->score+=100;

    int i;

    /*  to get a new level and speed */

    for(i = 1; i <= MAX; i++)
    {
        if(info->score == 1000 * i)
        {
            info->level++;
            info->speed-=0.05;
        }
    }
}


