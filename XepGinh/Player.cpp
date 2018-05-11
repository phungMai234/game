
#include"IPlayer.h"

/* CODE */

/*move blocks of bricks*/

void moveLeftObject(KhoiGach* pKhoiGach)
{
    int i, j;
    for(i = 0; i < pKhoiGach->Row; i++)
    {
        for(j = 0; j < pKhoiGach->Col; j++)
        {

            if(pKhoiGach->arr[i][j] == 1)
            {
                if(left(pKhoiGach->iBoard + i, pKhoiGach->jBoard + j) == false)
                    return;
            }
        }
    }
    pKhoiGach->jBoard--;
}

void moveRightObject(KhoiGach* pKhoiGach)
{
    int i, j;
    for(i = 0; i < pKhoiGach->Row; i++)
    {
        for(j = 0; j < pKhoiGach->Col; j++)
        {

            if(pKhoiGach->arr[i][j] == 1)
            {
                if(right(pKhoiGach->iBoard + i, pKhoiGach->jBoard + j) == false)
                    return;
            }
        }
    }
    pKhoiGach->jBoard++;
}

bool moveDownObject(KhoiGach* pKhoiGach)
{
    int i, j;
    for(i = 0; i < pKhoiGach->Row; i++)
    {
        for(j = 0; j < pKhoiGach->Col; j++)
        {

            if(pKhoiGach->arr[i][j] == 1)
            {
                if(down(pKhoiGach->iBoard + i, pKhoiGach->jBoard + j) == false)
                    return false;
            }
        }
    }
    pKhoiGach->iBoard++;
    return true;
}

void rotateObject(KhoiGach* pKhoiGach) // hoi
{
    // xoay khoi gach la xoay tai cho
    // iBoard, jBoard k thay doi, vi tri khoi gach van giu nguyen
    int i, j;
    int **tmpArr; // mang tam thoi luu khoi gach da xoay
    int tmpRow = pKhoiGach->Col; // hang cua khoi gach xoay
    int tmpCol = pKhoiGach->Row; // cot cua khoi gach xoay


    // cap phat bo nho dong cho ma tran tam thoi
    tmpArr = new int*;
    for(i = 0; i < tmpRow; i++)
    {
        tmpArr[i] = new int;
    }

    // chuyen ma tran hien tai thanh ma tran xoay mot goc 90

    for(i = 0; i < pKhoiGach->Row; i++)
    {
        for(j = 0; j < pKhoiGach->Col; j++)
        {
            tmpArr[j][pKhoiGach->Row - i - 1] = pKhoiGach->arr[i][j];
        }
    }

    // kiem tra xem co xoay duoc khoi gach khong
    // k chay dc
    for(i = 0; i < tmpRow; i++)
    {
        for(j = 0; j < tmpCol; j++)
        {
            if(inside(pKhoiGach->iBoard + i, pKhoiGach->jBoard + j) == false || Board[pKhoiGach->iBoard + i][pKhoiGach->jBoard + j] == 1) // k hieu lam
                return;
        }

    }

    // giai phong khoi gach trc khi xoay

    // sao k goi dc ham huykhoigach
    huyKhoiGach(pKhoiGach);
//    for(i = 0; i < pKhoiGach->Row; i++)
//        delete [] pKhoiGach->arr[i];
//    delete [] pKhoiGach->arr;

    // cap nhat thay doi sau khi xoay

    pKhoiGach->Row = tmpRow;
    pKhoiGach->Col = tmpCol;
    pKhoiGach->arr = tmpArr;

}

bool playGame()
{
    clrscr();

    int Id = randomObject();

    /* creat origin brick block */

    KhoiGach * curr;
    curr = TaoKhoiGach(Id);

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
        veBangDiem(info);
        VeKhoiGach(curr);
        Xoa_Next();
        Ve_Next(IDKhoiTiepTheo);

        Start = clock();

        do
        {
            if(kbhit())
            {
                /* choice key from keyBoard */
                key = _getch();

                xoaKhoiGach(curr);

                if( key == 'a' || key == 'A' || key == key_Left)
                    moveLeftObject(curr);

                if( key == 'd' || key == 'D' || key == key_Right)
                    moveRightObject(curr);

                if( key == 's' || key == 'S' || key == key_Down)
                    moveDownObject(curr);

                if( key == 'w' || key == 'W' || key == key_Up)
                    rotateObject(curr);


                VeKhoiGach(curr);
            }

            End = clock();

        }
        while(float(End - Start)/ CLK_TCK < info.speed);

        xoaKhoiGach(curr);

        if(moveDownObject(curr) == false)
        {
            /* Assigns values to the matrix for falling blocks*/
            ganGiaTri(curr);

            /* check to get score*/
            int result = kiemTra(curr, &info);
            if(result == -1 || result == 2)
                break;

            /* free memory*/
            huyKhoiGach(curr);

            /* creat next brick block */
            curr = TaoKhoiGach(IDKhoiTiepTheo);
            IDKhoiTiepTheo = randomObject();

            /* assign value to matrix*/
            disPlayBoard();
        }

    }
    while(1);

    huyKhoiGach(curr);

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
