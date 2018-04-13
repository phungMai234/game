#include <iostream>
#include"console.h"

#include"taoKhoiGach.h"

#include"DrawMap.h"

#include"MoveBlock.h"

#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>



using namespace std;


// ham gan gia tri cho ma tra board khi khoi gach k roi xuong nua
//void GanGiaTri(KhoiGach* pkhoigach) // khong hieu ham nay
//{
//    int i, j;
//    for(i = 0; i < pkhoigach->Row; i++)
//    {
//        for(j = 0; j < pkhoigach->Col; j++)
//        {
//            if(pkhoigach->arr[i][j] == 1)
//            {
//                Board[pkhoigach->iBoard + i][pkhoigach->jBoard + j] = 1;
//            }
//        }
//    }
//}


// thong tin diem

// bat dau game


// ve bang diem lai sau moi lan

//void HuyKhoiGach(KhoiGach* pkhoigach)
//{
//	int i;
//	//Huy bo nho cua ma tran trang thai arr.
//	for(i=0;i<pkhoigach->Row;i++) free(pkhoigach->arr[i]);
//	free(pkhoigach->arr);
//	/////////////////////////////////////////////////////////
//	//Sau do moi free(pkhoigach)
//	free(pkhoigach);
//	pkhoigach=NULL;
//}




// ham hien khoi gach tiep thoe
//void Ve_Next(int ID)
//{
//	KhoiGach *pnext=TaoKhoiGach(ID);
//	int iRoot=LEFT+MaxJ+5;
//	int jRoot=TOP + 2;
//	for(int i=0;i<pnext->Row;i++)
//	{
//		for (int j=0;j<pnext->Col;j++)
//		{
//			if(pnext->arr[i][j]==1)
//			{
//				TextColor(9);
//				gotoXY(iRoot+j,jRoot+i);
//				cout << char(2);
//			}
//		}
//
//	}
//	HuyKhoiGach(pnext);
//}
//
//
//
//void Xoa_Next()
//{
//	int iRoot=LEFT+MaxJ+5;
//	int jRoot=TOP;
//	for(int i=0;i<4;i++)
//	{
//		for (int j=0;j<4;j++)
//		{
//
//				TextColor(0);
//				gotoXY(iRoot+j,jRoot+i);
//				cout << "";
//		}
//	}
//}

int main()
{

    DrawBoard();
    int ID = Loai();
    KhoiGach* currKhoi;

    currKhoi = TaoKhoiGach(ID);
    VeKhoiGach(currKhoi);
//    INFO info;
//    InitGame(&info);
//    CapNhat(&info, info.score);
//    VeBangDiem(info);
//    do
//    {
//        VeBangDiem(info);
//        VeKhoiGach(currKhoi);
//        Xoa_Next();
//        Ve_Next(ID);
//        do
//        {
//            if(_kbhit())
//            {
//                clrscr();
//                DrawBoard();
//                char key = _getch();
//                if(key == 'a' || key == 'A')
//                    SangTrai(currKhoi);
//                if(key == 'd' || key == 'D')
//                    SangPhai(currKhoi);
//                if(key == 's' || key == 'S')
//                    RoiXuong(currKhoi);
//                if(key == 'w' || key == 'W')
//                    XoayKhoiGach(currKhoi);
//                VeKhoiGach(currKhoi);
//            }
//            Sleep(50);
//        }while(1);
//        XoaKhoiGach(currKhoi);
//        if(RoiXuong(currKhoi) == 0)
//        {
//            GanGiaTri(currKhoi);
//            HuyKhoiGach(currKhoi);
//            currKhoi = TaoKhoiGach(ID);
//            ID = Loai();
//            DisplayBoard();
//        }
//    }while(1);

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
            else
            {   clrscr();
                RoiXuong(currKhoi);
                VeKhoiGach(currKhoi);

            }
            Sleep(500);
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
