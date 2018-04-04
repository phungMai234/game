#include <iostream>
#include"console.h"
#include<cstdlib>
#include<ctime>

#define LEFT 4
#define TOP 4

#define MaxI 22
#define MaxJ 10

int Board[MaxI][MaxJ];

using namespace std;

struct KhoiGach
{
    int **arr; // la cai j
    int Row, Col;
    int iBoard, jBoard; // jBoard chỉ hàng, iBoard chỉ cột
};
KhoiGach *TaoKhoiGach(int ID)
{
	KhoiGach *pkhoigach = new KhoiGach;
	switch(ID)
	{
		case 15: // hình chữ I
			pkhoigach->Row=4;
			pkhoigach->Col=1;
			pkhoigach->iBoard=0;
			pkhoigach->jBoard=5;
			break;
		case 31: // hinh vuông
			pkhoigach->Row=pkhoigach->Col=2;
			pkhoigach->iBoard=2;
			pkhoigach->jBoard=5;
            break;
		default: // hình T,L,Z
			pkhoigach->Row=2;
			pkhoigach->Col=3;
			pkhoigach->iBoard=2;
			pkhoigach->jBoard=5;
			break;
	}
	pkhoigach->arr = new int*;
	for(int i = 0; i < pkhoigach->Row; i++)
	{
		pkhoigach->arr[i] = new int;
	}
	for(int k = 0; k < pkhoigach->Col * pkhoigach->Row; k++)
	{
		pkhoigach->arr[k / pkhoigach->Col][k % pkhoigach->Col] = (ID >> (pkhoigach->Col * pkhoigach->Row - 1 - k)) & 1;
	}
	return pkhoigach;
}
int Loai()
{
    srand(time(NULL));
    int x=rand()%7;
	switch(x)
	{
        case 0:
            return 15;
            break;
        case 1:
            return 31;
            break;
        case 2:
            return 51;
            break;
        case 3:
            return 30;
            break;
        case 4:
            return 58;
            break;
        case 5:
            return 57;
            break;
        case 6:
            return 60;
            break;
	}
}

void VeKhoiGach(KhoiGach* pkhoigach)
{
	int i;
	int j;
	for(i = 0;i < pkhoigach->Row; i++)
		for(j = 0;j < pkhoigach->Col; j++)
			if(pkhoigach->arr[i][j] == 1 ) // arr k hieu
			{
				TextColor(13);
				gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3);
				cout << char(2); // nho cout ra
			}
}

void XoaKhoiGach(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                TextColor(0);
                gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3);
                cout <<"";
            }
        }
    }
}
// ham kiem tra khoi gach co nam trong bang hay k

int Inside(int i, int j)
{
    return ((i > 0 && i < MaxI) && (j > 0 && j < MaxJ));
}

// ham di chuyen mot khoi gach sang trai, phai, xuong

int Left(int i, int j)
{
    if(j > 0 && Inside(i, j) && Board[i][j - 1] == 0)
        return 1;
    return 0;
}
int Right(int i, int j)
{
    if((j < MaxJ - 1) && Inside(i, j) && Board[i][j + 1] == 0)
        return 1;
    return 0;
}
int Down(int i, int j)
{
    if((j < MaxI - 1) && Inside(i, j) && Board[i + 1][j] == 0)
        return 1;
    return 0;
}

// ham di chuyen ca khoi gach

void SangTrai(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Left(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0 || pkhoigach->iBoard <= 3)
                    return;
            }
        }
    }
    pkhoigach->jBoard-=1;
}

void SangPhai(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Right(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0 || pkhoigach->iBoard <= 3)
                    return;
            }
        }
    }
    pkhoigach->iBoard+=1;
}

int RoiXuong(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Down(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0 || pkhoigach->iBoard <= 3)
                    return 0; // khong roi xuong
            }
        }
    }
    pkhoigach->iBoard+=1;
    return 1; // roi xuong
}

void DrawBoard()
{
	int i,j;
	for(i=LEFT;i<=LEFT+10+1;i++)
		for(j=TOP;j<=TOP+18+1;j++)
		{
			if((j==TOP||j==TOP+18+1)&&i>LEFT&&i<LEFT+10+1)
			{
				gotoXY(i,j);TextColor(7);
				cout << char(205);
			}
			if((i==LEFT||i==LEFT+10+1)&&j>TOP&&j<TOP+18+1)
			{
				gotoXY(i,j);TextColor(7);
				cout << char(186);
			}
		}
		gotoXY(LEFT,TOP);TextColor(10);cout << char(219);
		gotoXY(LEFT+10+1,TOP);TextColor(10);cout << char(219);
		gotoXY(LEFT,TOP+18+1);TextColor(10);cout << char(219);
		gotoXY(LEFT+10+1,TOP+18+1);TextColor(10);cout << char(219);

}


int main()
{
    DrawBoard();
    int ID = Loai();
    KhoiGach* currKhoi;

    currKhoi = TaoKhoiGach(ID);
    VeKhoiGach(currKhoi);
//    if(_kbhit())   //Nếu bàn phím đc nhấn
//			{
//				int c=toupper(getch());  //Lấy mã phím vừa đc bấm
//				XoaKhoiGach(currKhoi);  //Xóa khối gạch
//				switch(c)
//				{
//				case 'A':
//					SangTrai(currKhoi);
//					break;
//				case 'D':
//					SangPhai(currKhoi);
//					break;
//				case 'S':
//					RoiXuong();
//					break;
//				}
//				VeKhoiGach(currKhoi);//Vẽ lại khối gạch sau khi cập nhật thay đổi.
//			}

    gotoXY(30,25);
}
