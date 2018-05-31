
#include"IPlayer.h"

/* CODE */

/*move blocks of bricks*/

void moveLeftObject(Object* pObject)
{
    int i, j;
    for(i = 0; i < pObject->Row; i++)
    {
        for(j = 0; j < pObject->Col; j++)
        {

            if(pObject->arr[i][j] == 1)
            {
                if(left(pObject->iBoard + i, pObject->jBoard + j) == false)
                    return;
            }
        }
    }
    pObject->jBoard--;
}

void moveRightObject(Object* pObject)
{
    int i, j;
    for(i = 0; i < pObject->Row; i++)
    {
        for(j = 0; j < pObject->Col; j++)
        {

            if(pObject->arr[i][j] == 1)
            {
                if(right(pObject->iBoard + i, pObject->jBoard + j) == false)
                    return;
            }
        }
    }
    pObject->jBoard++;
}

bool moveDownObject(Object* pObject)
{
    int i, j;
    for(i = 0; i < pObject->Row; i++)
    {
        for(j = 0; j < pObject->Col; j++)
        {

            if(pObject->arr[i][j] == 1)
            {
                if(down(pObject->iBoard + i, pObject->jBoard + j) == false)
                    return false;
            }
        }
    }
    pObject->iBoard++;
    return true;
}

void rotateObject(Object* pObject)
{

    int i, j;
    int **tmpArr;
    int tmpRow = pObject->Col;
    int tmpCol = pObject->Row;



    tmpArr = new int*;
    for(i = 0; i < tmpRow; i++)
    {
        tmpArr[i] = new int;
    }



    for(i = 0; i < pObject->Row; i++)
    {
        for(j = 0; j < pObject->Col; j++)
        {
            tmpArr[j][pObject->Row - i - 1] = pObject->arr[i][j];
        }
    }


    for(i = 0; i < tmpRow; i++)
    {
        for(j = 0; j < tmpCol; j++)
        {
            if(inside(pObject->iBoard + i, pObject->jBoard + j) == false || Board[pObject->iBoard + i][pObject->jBoard + j] == 1) // k hieu lam
                return;
        }

    }


    destroyObject(pObject);

    pObject->Row = tmpRow;
    pObject->Col = tmpCol;
    pObject->arr = tmpArr;

}

bool playGame()
{
    clrscr();

    int Id = randomObject();

    /* creat origin brick block */

    Object * curr;
    curr = designObject(Id);

    /* creat ID random to creat next brick block */

    int IDKhoiTiepTheo = randomObject();

    /* creat origin info*/

    INFO info;
    initGame(&info);

    char key;
    clock_t Start, End;

    /* creat origin matrix */

    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= 10; j++)
            Board[i][j] = 0;
    }

    /* play game*/

    render();
    do
    {
        drawTableScore(info);
        drawObject(curr);
        deleteNextObject();
        drawNextObject(IDKhoiTiepTheo);

        Start = clock();

        do
        {
            if(kbhit())
            {
                /* choice key from keyBoard */
                key = _getch();

                deleteObject(curr);

                if( key == 'a' || key == 'A' || key == key_Left)
                    moveLeftObject(curr);

                if( key == 'd' || key == 'D' || key == key_Right)
                    moveRightObject(curr);

                if( key == 's' || key == 'S' || key == key_Down)
                    moveDownObject(curr);

                if( key == 'w' || key == 'W' || key == key_Up)
                    rotateObject(curr);


                drawObject(curr);
            }

            End = clock();

        }
        while(float(End - Start)/ CLK_TCK < info.speed);

        deleteObject(curr);

        if(moveDownObject(curr) == false)
        {
            /* Assigns values to the matrix for falling blocks*/
            getValue(curr);

            /* check to get score*/
            int result = checkToGetPoint(curr, &info);
            if(result == -1 || result == 2)
                break;

            /* free memory*/
            destroyObject(curr);

            /* creat next brick block */
            curr = designObject(IDKhoiTiepTheo);
            IDKhoiTiepTheo = randomObject();

            /* assign value to matrix*/
            displayBoard();
        }

    }
    while(1);

    destroyObject(curr);

    /* Win Game*/ // trang tri them
    if(info.score >= 5000)
    {
        TextColor(13);
        gotoXY(LEFT + MaxJ + 20, TOP + 10);
        cout << "CONGRATULATION! YOU WIN";
    }
    /*Show core, end game*/
    else
    {
        TextColor(14);
        gotoXY(LEFT + MaxJ + 20, TOP + 10);
        cout << "Game Over\n";
        gotoXY(LEFT + MaxJ + 20, TOP + 11);
        cout << "Your core :\n";
        gotoXY(LEFT + MaxJ + 32, TOP + 11);
        cout << info.score << endl;

    }

    /* Ask player want to continue game*/

    gotoXY(LEFT + MaxJ + 20, TOP + 14);
    cout << "Do you want to back Main menu? (Y/N) \n";
    char choice;

    /* get character from keyBoard */

    choice = _getch();

    if(choice == 'N' || choice == 'n')
        return false;
    return true;
}
