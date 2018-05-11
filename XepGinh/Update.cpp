
#include"IUpdate.h"

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
void ganGiaTri(KhoiGach* pKhoiGach)
{
    int i, j;
    for(i = 0; i < pKhoiGach->Row; i++)
    {

        for(j = 0; j < pKhoiGach->Col; j++)
        {
            if(pKhoiGach->arr[i][j] == 1)
                Board[pKhoiGach->iBoard + i][pKhoiGach->jBoard + j] = 1;
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

    /* check to get a new level and speed */

    for(i = 1; i <= MAX; i++)
    {
        if(info->score == 1000 * i)
        {
            info->level++;
            info->speed-=0.05;
        }
    }
}


