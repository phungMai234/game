#include"IDraw.h"

/* CODE */

void drawObject(Object* pObject)
{
    int i, j;
    for(i = 0; i < pObject->Row; i++)
    {
        for(j = 0; j < pObject->Col; j++)
        {
            if(pObject->arr[i][j] == 1 && pObject->iBoard > 3)
            {
                gotoXY(LEFT + pObject->jBoard + j + 1, TOP + pObject->iBoard + i - 3);
                TextColor(13);
                cout << char(219);
            }
        }
    }
}
void deleteObject(Object* pObject)
{
    int i, j;
    for(i = 0; i < pObject->Row; i++)
    {
        for(j = 0; j < pObject->Col; j++)
        {
            if(pObject->arr[i][j] == 1 && pObject->iBoard > 3)
            {
                gotoXY(LEFT + pObject->jBoard + j + 1, TOP + pObject->iBoard + i - 3);
                TextColor(0);
                cout << " ";
            }
        }
    }
}

/*Brick blocks are in the game information*/
void drawNextObject(int ID)
{
    Object *pnext=designObject(ID);

    int iRoot=LEFT+MaxJ + 5;
    int jRoot=TOP + 1;
    for(int i=0; i<pnext->Row; i++)
    {
        for (int j=0; j<pnext->Col; j++)
        {
            if(pnext->arr[i][j]==1)
            {
                TextColor(9);
                gotoXY(iRoot+j,jRoot+i);
                cout << char(219);
            }
        }

    }
    destroyObject(pnext);
}
void deleteNextObject()
{
    int iRoot=LEFT+MaxJ+5;
    int jRoot=TOP + 1;
    for(int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {

            TextColor(0);
            gotoXY(iRoot+j,jRoot+i);
            cout << " ";
        }

    }
}


void render()
{
    int i, j;
    for(i = LEFT; i <= LEFT + 10 + 1; i++)
    {
        for(j = TOP; j <= TOP + 18 + 1; j++)
        {
            /* draw row*/
            if((j == TOP + 18 +1 || j == TOP) && i > LEFT && i < LEFT + 10 + 1)
            {
                gotoXY(i, j);
                TextColor(7);
                cout << char(205);
            }

            /* draw column*/
            if((i == LEFT || i == LEFT + 10 + 1) && j > TOP && j < TOP + 18 + 1)
            {
                gotoXY(i, j);
                TextColor(7);
                cout << char(186);
            }
        }
    }

    /* corner left up*/
    gotoXY(LEFT, TOP);
    TextColor(10);
    cout << char(219);

    /* corner right up*/
    gotoXY(LEFT + 10 + 1, TOP);
    TextColor(10);
    cout << char(219);

    /* corner left down */
    gotoXY(LEFT, TOP + 18 + 1);
    TextColor(10);
    cout << char(219);

    /* corner right down*/
    gotoXY(LEFT + 10 + 1, TOP + 18 + 1);
    TextColor(10);
    cout << char(219);

}

void drawTableScore(INFO info)
{
    TextColor(10);
    gotoXY(LEFT + MaxJ + 4, TOP + 6);
    cout << "SCORE: " << info.score << endl;
    gotoXY(LEFT + MaxJ + 4, TOP + 7);
    cout << "LEVEL: " << info.level << endl;
    gotoXY(LEFT + MaxJ + 4, TOP + 8);
    cout << "SPEED: " << info.speed << endl;

}


void displayBoard()
{
    int i, j;
    for(i = 0; i < MaxI; i++)
    {
        for(j = 0; j < MaxJ; j++)
        {
            if(Board[i][j] == 1 && i >= 4)
            {

                gotoXY(j + LEFT + 1, i + TOP + 1 - 4);
                TextColor(15);
                cout << char(219);
            }
            if(Board[i][j] == 0 && i > 4)
            {
                gotoXY(j + LEFT + 1, i + TOP + 1 - 4);
                TextColor(0);
                cout << " ";
            }
        }
    }
}
