#include <iostream>
#include"console.h"
#include"MoveBlock.h"
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>

#define LEFT 4
#define TOP 4

#define MaxI 22
#define MaxJ 10

int Board[MaxI][MaxJ];

using namespace std;



struct INFO
{
    int score;
    int level;
    float speed;
};

KhoiGach *TaoKhoiGach(int ID)
{
	KhoiGach *pkhoigach = new KhoiGach;
	switch(ID)
	{
		case 15: // hình chữ I
			pkhoigach->Row=4;
			pkhoigach->Col=1;
			pkhoigach->iBoard=5;
			pkhoigach->jBoard=5;
			break;
		case 31: // hinh vuông
			pkhoigach->Row=pkhoigach->Col=2;
			pkhoigach->iBoard=5;
			pkhoigach->jBoard=5;
            break;
		default: // hình T,L,Z
			pkhoigach->Row=2;
			pkhoigach->Col=3;
			pkhoigach->iBoard=5;
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
                gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3); //  k hieu
                cout <<"";
            }
        }
    }
}





// ham dieu khien



// ham xoay





// ve ra man hinh khung
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

// ham gan gia tri cho ma tra board khi khoi gach k roi xuong nua
void GanGiaTri(KhoiGach* pkhoigach) // khong hieu ham nay
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                Board[pkhoigach->iBoard + i][pkhoigach->jBoard + j] = 1;
            }
        }
    }
}


// thong tin diem

// bat dau game

void InitGame(INFO *info)
{
	info->level=1;
	info->score=0;
	info->speed=0.4;
}

// cap nhat khi sang level moi

int CapNhat(INFO *info, int score)
{
	info->score+=score;
	if(info->score>=200&&info->level<2)
	{
		info->level++;
		info->speed-=0.1;
	}
	return 0; //Chua win game.
}
// ve bang diem lai sau moi lan

void HuyKhoiGach(KhoiGach* pkhoigach)
{
	int i;
	//Huy bo nho cua ma tran trang thai arr.
	for(i=0;i<pkhoigach->Row;i++) free(pkhoigach->arr[i]);
	free(pkhoigach->arr);
	/////////////////////////////////////////////////////////
	//Sau do moi free(pkhoigach)
	free(pkhoigach);
	pkhoigach=NULL;
}

void VeBangDiem(INFO info)
{
	TextColor(15);
	gotoXY(LEFT+MaxJ+2,10);
	cout << "  SCORE: " << info.score;
	gotoXY(LEFT+MaxJ+2,11);
	cout << "  LEVEL: " << info.level;
	gotoXY(LEFT+MaxJ+2,12);
	cout << "  SPEED: " << info.speed;
}


// ham hien khoi gach tiep thoe
void Ve_Next(int ID)
{
	KhoiGach *pnext=TaoKhoiGach(ID);
	int iRoot=LEFT+MaxJ+5;
	int jRoot=TOP + 2;
	for(int i=0;i<pnext->Row;i++)
	{
		for (int j=0;j<pnext->Col;j++)
		{
			if(pnext->arr[i][j]==1)
			{
				TextColor(9);
				gotoXY(iRoot+j,jRoot+i);
				cout << char(2);
			}
		}

	}
	HuyKhoiGach(pnext);
}

void dieuKhien(KhoiGach* pkhoigach)
{
    if(_kbhit())
    {
        clrscr();
        char key = _getch();
        if(key == 'a' || key == 'A')
            SangTrai(pkhoigach);
        if(key == 'd' || key == 'D')
            SangPhai(pkhoigach);
        if(key == 's' || key == 'S')
            RoiXuong(pkhoigach);
        if(key == 'w' || key == 'W')
            XoayKhoiGach(pkhoigach);
        VeKhoiGach(pkhoigach);
    }
}

int main()
{

    DrawBoard();
    int ID = Loai();
    KhoiGach* currKhoi;

    currKhoi = TaoKhoiGach(ID);
    VeKhoiGach(currKhoi);
    while(1)
	{

        if(_kbhit())
        {
            clrscr();
            DrawBoard();
            char key = _getch();
            if(key == 'a' || key == 'A')
                SangTrai(currKhoi);
            if(key == 'd' || key == 'D')
                SangPhai(currKhoi);
            if(key == 's' || key == 'S')
                RoiXuong(currKhoi);
            if(key == 'w' || key == 'W')
                XoayKhoiGach(currKhoi);
            VeKhoiGach(currKhoi);
        }
//        else
//        {   clrscr();
//            RoiXuong(currKhoi);
//            VeKhoiGach(currKhoi);
//
//        }
        Sleep(200);
	}


//    char c = 'd';
//    // vidu
//
//    INFO infor;
//    infor.score = 0;
//    infor.level = 1;
//    infor.speed = 200;
//    Ve_Next(ID);

    //do
    //{
        //VeBangDiem(infor);
       // VeKhoiGach(currKhoi);
        //do
    //Sleep(500);    //{
    //dieuKhien(currKhoi);
        //}while(1);
    //}while(1);

    //Sleep(5000);
    gotoXY(30,25);
}
